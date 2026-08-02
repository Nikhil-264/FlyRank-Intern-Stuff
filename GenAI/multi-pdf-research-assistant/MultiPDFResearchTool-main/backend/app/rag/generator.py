from app.services.llm_service import get_llm

from app.rag.prompts import RAG_PROMPT


def generate_answer(context, question):

    llm = get_llm()

    formatted_prompt = RAG_PROMPT.format(
        context=context,
        question=question
    )

    response = llm.invoke(formatted_prompt)

    return response.content