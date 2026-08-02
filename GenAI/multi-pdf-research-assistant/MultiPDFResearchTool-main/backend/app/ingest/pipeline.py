from app.ingest.loader import load_pdf
from app.ingest.chunker import chunk_documents

from app.services.vectorstore_service import create_vectorstore


def process_pdf(pdf_path: str):

    # Load PDF
    documents = load_pdf(pdf_path)

    # Chunk PDF
    chunks = chunk_documents(documents)

    # Create Vector Store
    vectorstore = create_vectorstore(chunks)

    return vectorstore