from fastapi import FastAPI, APIRouter, UploadFile, File, HTTPException
from fastapi.responses import StreamingResponse
from dotenv import load_dotenv
from starlette.middleware.cors import CORSMiddleware
from motor.motor_asyncio import AsyncIOMotorClient
import os
import asyncio
import json
import logging
import secrets
from pathlib import Path
from pydantic import BaseModel, Field, ConfigDict
from typing import List, Optional
import uuid
from datetime import datetime, timezone


ROOT_DIR = Path(__file__).parent
load_dotenv(ROOT_DIR / '.env')

mongo_url = os.environ['MONGO_URL']
client = AsyncIOMotorClient(mongo_url)
db = client[os.environ['DB_NAME']]

app = FastAPI(title="PDF Research Assistant API")
api_router = APIRouter(prefix="/api")


# ========= Models =========
class Document(BaseModel):
    model_config = ConfigDict(extra="ignore")
    id: str = Field(default_factory=lambda: str(uuid.uuid4()))
    filename: str
    size: int
    pages: int
    status: str = "ready"  # uploading | embedding | ready | failed
    uploaded_at: str = Field(default_factory=lambda: datetime.now(timezone.utc).isoformat())


class Session(BaseModel):
    model_config = ConfigDict(extra="ignore")
    id: str = Field(default_factory=lambda: str(uuid.uuid4()))
    title: str = "New Chat"
    created_at: str = Field(default_factory=lambda: datetime.now(timezone.utc).isoformat())
    updated_at: str = Field(default_factory=lambda: datetime.now(timezone.utc).isoformat())


class SessionCreate(BaseModel):
    title: Optional[str] = "New Chat"


class SessionRename(BaseModel):
    title: str


class Citation(BaseModel):
    id: str
    document_id: str
    filename: str
    page: int
    snippet: str


class Message(BaseModel):
    model_config = ConfigDict(extra="ignore")
    id: str = Field(default_factory=lambda: str(uuid.uuid4()))
    session_id: str
    role: str  # user | assistant
    content: str
    citations: List[Citation] = []
    created_at: str = Field(default_factory=lambda: datetime.now(timezone.utc).isoformat())


class ChatRequest(BaseModel):
    message: str
    session_id: str


class SearchRequest(BaseModel):
    query: str
    top_k: int = 5


class SearchChunk(BaseModel):
    id: str
    document_id: str
    filename: str
    page: int
    score: float
    text: str


# ========= Helpers =========
SAMPLE_INSIGHTS = [
    "introduces a novel attention mechanism",
    "demonstrates strong empirical performance on benchmark datasets",
    "proposes a hybrid retrieval architecture",
    "evaluates scaling behavior across model sizes",
    "presents a theoretical analysis of convergence guarantees",
]


def _rand_int(low: int, high: int) -> int:
    """Inclusive [low, high] using cryptographically secure secrets."""
    if high <= low:
        return low
    return low + secrets.randbelow(high - low + 1)


def _rand_choice(seq):
    return seq[secrets.randbelow(len(seq))]


def _rand_sample(seq, k: int):
    pool = list(seq)
    out = []
    for _ in range(min(k, len(pool))):
        idx = secrets.randbelow(len(pool))
        out.append(pool.pop(idx))
    return out


def _rand_shuffle(seq):
    for i in range(len(seq) - 1, 0, -1):
        j = secrets.randbelow(i + 1)
        seq[i], seq[j] = seq[j], seq[i]


def _rand_uniform(low: float, high: float) -> float:
    # 1e6-bin uniform from secrets.
    span = high - low
    return low + (secrets.randbelow(1_000_001) / 1_000_000) * span


def _mock_ai_answer(question: str, docs: List[dict]) -> tuple[str, List[Citation]]:
    if not docs:
        body = (
            f"I haven't been connected to any indexed PDFs yet, so this response is a placeholder. "
            f"Once you upload research papers, I'll ground my answer to **{question.strip()}** in their content.\n\n"
            "### What I can do once documents are indexed\n"
            "- Cross-reference claims across multiple PDFs\n"
            "- Return inline citations with page numbers\n"
            "- Surface the most relevant chunks in the right panel\n"
        )
        return body, []

    chosen = _rand_sample(docs, k=min(2, len(docs)))
    citations: List[Citation] = []
    for d in chosen:
        citations.append(Citation(
            id=str(uuid.uuid4()),
            document_id=d["id"],
            filename=d["filename"],
            page=_rand_int(1, max(2, d.get("pages", 10))),
            snippet=f"…the authors argue that {_rand_choice(SAMPLE_INSIGHTS)}, with results consistent across runs…",
        ))

    refs = " ".join(f"[{i+1}]" for i in range(len(citations)))
    body = (
        f"Based on the indexed corpus, here is what the literature suggests about **{question.strip()}**:\n\n"
        f"The reviewed papers collectively show that the field {_rand_choice(SAMPLE_INSIGHTS)} {refs}. "
        "Several limitations remain — sample efficiency and out-of-distribution robustness in particular.\n\n"
        "### Key takeaways\n"
        f"- {chosen[0]['filename']} provides the strongest empirical evidence\n"
        f"- {'Cross-paper agreement is high' if len(chosen) > 1 else 'A single source informs this answer'}\n"
        "- Open questions remain around generalization\n\n"
        "```python\n# Example: minimal retrieval call\nresults = retriever.search(query, top_k=5)\nfor r in results:\n    print(r.page, r.score)\n```\n"
    )
    return body, citations


# ========= Routes =========
@api_router.get("/")
async def root():
    return {"message": "PDF Research Assistant API", "status": "ok"}


# ---- Documents ----
@api_router.post("/upload", response_model=Document)
async def upload_document(file: UploadFile = File(...)):
    contents = await file.read()
    size = len(contents)
    # mock page count proportional to size
    pages = max(1, min(120, size // 8000 or _rand_int(6, 24)))
    doc = Document(filename=file.filename or "untitled.pdf", size=size, pages=pages, status="ready")
    await db.documents.insert_one(doc.model_dump())
    return doc


@api_router.get("/documents", response_model=List[Document])
async def list_documents():
    docs = await db.documents.find({}, {"_id": 0}).sort("uploaded_at", -1).to_list(500)
    return docs


@api_router.delete("/documents/{doc_id}")
async def delete_document(doc_id: str):
    res = await db.documents.delete_one({"id": doc_id})
    if res.deleted_count == 0:
        raise HTTPException(status_code=404, detail="Document not found")
    return {"ok": True}


@api_router.get("/documents/{doc_id}/summary")
async def document_summary(doc_id: str):
    doc = await db.documents.find_one({"id": doc_id}, {"_id": 0})
    if not doc:
        raise HTTPException(status_code=404, detail="Document not found")
    return {
        "document_id": doc_id,
        "filename": doc["filename"],
        "summary": (
            f"This paper {_rand_choice(SAMPLE_INSIGHTS)}. The authors present experiments on multiple "
            "benchmarks and analyze the trade-offs between accuracy, latency, and compute. They conclude that "
            "the proposed approach generalizes across domains, with caveats around data scale."
        ),
        "key_findings": [
            "Outperforms strong baselines on three benchmarks",
            "Inference cost reduced by ~28%",
            "Failure modes appear under distribution shift",
        ],
        "keywords": ["retrieval", "attention", "evaluation", "scaling", "robustness"],
    }


# ---- Sessions ----
@api_router.get("/sessions", response_model=List[Session])
async def list_sessions():
    sessions = await db.sessions.find({}, {"_id": 0}).sort("updated_at", -1).to_list(500)
    return sessions


@api_router.post("/sessions", response_model=Session)
async def create_session(body: SessionCreate):
    s = Session(title=body.title or "New Chat")
    await db.sessions.insert_one(s.model_dump())
    return s


@api_router.patch("/sessions/{session_id}", response_model=Session)
async def rename_session(session_id: str, body: SessionRename):
    now = datetime.now(timezone.utc).isoformat()
    res = await db.sessions.find_one_and_update(
        {"id": session_id},
        {"$set": {"title": body.title, "updated_at": now}},
        return_document=True,
        projection={"_id": 0},
    )
    if not res:
        raise HTTPException(status_code=404, detail="Session not found")
    return res


@api_router.delete("/sessions/{session_id}")
async def delete_session(session_id: str):
    await db.sessions.delete_one({"id": session_id})
    await db.messages.delete_many({"session_id": session_id})
    return {"ok": True}


@api_router.get("/sessions/{session_id}/messages", response_model=List[Message])
async def list_messages(session_id: str):
    msgs = await db.messages.find({"session_id": session_id}, {"_id": 0}).sort("created_at", 1).to_list(1000)
    return msgs


# ---- Chat ----
@api_router.post("/chat", response_model=Message)
async def chat(body: ChatRequest):
    # ensure session exists
    sess = await db.sessions.find_one({"id": body.session_id}, {"_id": 0})
    if not sess:
        new_sess = Session(id=body.session_id, title=body.message[:48] or "New Chat")
        await db.sessions.insert_one(new_sess.model_dump())

    user_msg = Message(session_id=body.session_id, role="user", content=body.message)
    await db.messages.insert_one(user_msg.model_dump())

    docs = await db.documents.find({}, {"_id": 0}).to_list(50)
    content, citations = _mock_ai_answer(body.message, docs)
    ai_msg = Message(session_id=body.session_id, role="assistant", content=content, citations=citations)
    await db.messages.insert_one(ai_msg.model_dump())

    # bump session updated_at + auto-title if "New Chat"
    update = {"updated_at": datetime.now(timezone.utc).isoformat()}
    if sess and sess.get("title") in (None, "", "New Chat"):
        update["title"] = body.message[:48]
    await db.sessions.update_one({"id": body.session_id}, {"$set": update})

    return ai_msg


@api_router.post("/chat/stream")
async def chat_stream(body: ChatRequest):
    sess = await db.sessions.find_one({"id": body.session_id}, {"_id": 0})
    if not sess:
        new_sess = Session(id=body.session_id, title=body.message[:48] or "New Chat")
        await db.sessions.insert_one(new_sess.model_dump())

    user_msg = Message(session_id=body.session_id, role="user", content=body.message)
    await db.messages.insert_one(user_msg.model_dump())

    docs = await db.documents.find({}, {"_id": 0}).to_list(50)
    content, citations = _mock_ai_answer(body.message, docs)
    ai_msg = Message(session_id=body.session_id, role="assistant", content=content, citations=citations)
    await db.messages.insert_one(ai_msg.model_dump())

    async def gen():
        # stream meta first
        yield "data: " + json.dumps({"type": "meta", "id": ai_msg.id, "citations": [c.model_dump() for c in citations]}) + "\n\n"
        for token in content.split(" "):
            yield "data: " + json.dumps({"type": "token", "token": token + " "}) + "\n\n"
            await asyncio.sleep(0.015)
        yield "data: " + json.dumps({"type": "done"}) + "\n\n"

    return StreamingResponse(gen(), media_type="text/event-stream")


# ---- Search ----
@api_router.post("/search", response_model=List[SearchChunk])
async def semantic_search(body: SearchRequest):
    docs = await db.documents.find({}, {"_id": 0}).to_list(50)
    if not docs:
        return []
    out: List[SearchChunk] = []
    pool = (docs * 3)[: max(body.top_k, 5)]
    _rand_shuffle(pool)
    for i, d in enumerate(pool[: body.top_k]):
        out.append(SearchChunk(
            id=str(uuid.uuid4()),
            document_id=d["id"],
            filename=d["filename"],
            page=_rand_int(1, max(2, d.get("pages", 10))),
            score=round(0.92 - i * 0.07 + _rand_uniform(-0.02, 0.02), 3),
            text=(
                f"…relevant passage matching '{body.query}'. The paper notes that "
                f"{_rand_choice(SAMPLE_INSIGHTS)} and reports gains across configurations…"
            ),
        ))
    return out


app.include_router(api_router)

app.add_middleware(
    CORSMiddleware,
    allow_credentials=True,
    allow_origins=os.environ.get('CORS_ORIGINS', '*').split(','),
    allow_methods=["*"],
    allow_headers=["*"],
)

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)


@app.on_event("shutdown")
async def shutdown_db_client():
    client.close()
