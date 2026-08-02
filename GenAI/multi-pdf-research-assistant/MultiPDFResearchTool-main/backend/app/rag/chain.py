from app.rag.retriever import get_retriever

from app.rag.generator import generate_answer


def ask_question(question):

    retriever = get_retriever()

    retrieved_docs = retriever.invoke(question)

    context = "\n\n".join(
        [doc.page_content for doc in retrieved_docs]
    )

    answer = generate_answer(context, question)

    return {
        "answer": answer,
        "sources": retrieved_docs
    }