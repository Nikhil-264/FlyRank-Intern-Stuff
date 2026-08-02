from langchain_huggingface import ChatHuggingFace, HuggingFaceEndpoint
import os
from dotenv import load_dotenv
from langchain_core.messages import SystemMessage, HumanMessage, AIMessage

# Load environment variables
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

chatHistory = [SystemMessage(content='You are a helpful assistant.')]

while(True):
    user_input = input("User: ")
    chatHistory.append(HumanMessage(content=user_input))
    if user_input.lower() == "exit":
        break

    response = model.invoke(chatHistory)
    chatHistory.append(AIMessage(content=response.content))
    print(f"Chatbot: {response.content}")

print(chatHistory)