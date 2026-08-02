from langchain_chroma import Chroma

from app.services.embedding_service import get_embedding_model


PERSIST_DIRECTORY = "backend/vectorstore"


def get_retriever():

    embedding_model = get_embedding_model()

    vectorstore = Chroma(
        persist_directory=PERSIST_DIRECTORY,
        embedding_function=embedding_model
    )

    retriever = vectorstore.as_retriever(
        search_type="similarity",
        search_kwargs={"k": 3}
    )

    return retriever