from langchain_core.messages import SystemMessage, HumanMessage, AIMessage
from langchain_huggingface import ChatHuggingFace, HuggingFaceEndpoint
from dotenv import load_dotenv
import os

load_dotenv()

hf_token = os.getenv("HUGGINGFACEHUB_ACCESS_TOKEN")

# Create LLM endpoint
llm = HuggingFaceEndpoint(
    repo_id="meta-llama/Llama-3.1-8B-Instruct",
    huggingfacehub_api_token=hf_token,
    max_new_tokens=100
)

# Pass llm into ChatHuggingFace
model = ChatHuggingFace(llm=llm)

messages = [
    SystemMessage(content='You are a helpful assistant.'),
    HumanMessage(content='What is the capital of France?')
]

result = model.invoke(messages)

messages.append(AIMessage(content=result.content))
print(messages)