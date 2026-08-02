from langchain_chroma import Chroma
from app.services.embedding_service import get_embedding_model


PERSIST_DIRECTORY = "backend/vectorstore"


def create_vectorstore(chunks):

    embedding_model = get_embedding_model()

    vectorstore = Chroma.from_documents(
        documents=chunks,
        embedding=embedding_model,
        persist_directory=PERSIST_DIRECTORY
    )

    return vectorstore