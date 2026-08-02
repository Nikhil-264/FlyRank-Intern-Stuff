# test_llm.py

from langchain_ollama import ChatOllama

llm = ChatOllama(model="llama3")

response = llm.invoke("Hello")

print(response.content)