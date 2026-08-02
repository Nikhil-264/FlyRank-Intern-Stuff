# pip install -U langchain langchain-openai langchain-community faiss-cpu pypdf python-dotenv

import os
from langchain_community.document_loaders import PyPDFLoader
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain_ollama import ChatOllama, OllamaEmbeddings
from langchain_community.vectorstores import FAISS
from langchain_core.prompts import ChatPromptTemplate
from langchain_core.runnables import RunnableParallel, RunnablePassthrough, RunnableLambda
from langchain_core.output_parsers import StrOutputParser
from dotenv import load_dotenv


os.environ['LANGCHAIN_PROJECT'] = 'rag-chain-demo'

load_dotenv()



PDF_PATH = "Book1.pdf"  # <-- change to your PDF filename

# 1) Load PDF
loader = PyPDFLoader(PDF_PATH)
docs = loader.load()  # one Document per page

# 2) Chunk
splitter = RecursiveCharacterTextSplitter(chunk_size=1000, chunk_overlap=150)
splits = splitter.split_documents(docs)

emb = OllamaEmbeddings(model="nomic-embed-text")

from langchain_community.vectorstores import FAISS

texts = [doc.page_content for doc in splits]
metadatas = [doc.metadata for doc in splits]

all_embeddings = []

batch_size = 20

for i in range(0, len(texts), batch_size):
    batch = texts[i:i+batch_size]
    # print(f"Embedding batch {i//batch_size + 1}")
    all_embeddings.extend(emb.embed_documents(batch))

vs = FAISS.from_embeddings(
    text_embeddings=list(zip(texts, all_embeddings)),
    embedding=emb,
    metadatas=metadatas
)

retriever = vs.as_retriever(
    search_type="similarity",
    search_kwargs={"k": 4}
)

# 4) Prompt
prompt = ChatPromptTemplate.from_messages([
    ("system", "Answer ONLY from the provided context. If not found, say you don't know."),
    ("human", "Question: {question}\n\nContext:\n{context}")
])

# 5) Chain
llm = ChatOllama(model="llama3", temperature=0)
def format_docs(docs): return "\n\n".join(d.page_content for d in docs)

parallel = RunnableParallel({
    "context": retriever | RunnableLambda(format_docs),
    "question": RunnablePassthrough()
})

chain = parallel | prompt | llm | StrOutputParser()

# 6) Ask questions
print("PDF RAG ready. Ask a question (or Ctrl+C to exit).")
q = input("\nQ: ")
ans = chain.invoke(q.strip())
print("\nA:", ans)
