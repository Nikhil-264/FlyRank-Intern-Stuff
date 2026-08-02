from langchain_openai import ChatOpenAI
from dotenv import load_dotenv

load_dotenv()

chat = ChatOpenAI(model = "gpt-3.5-turbo-instruct", temprerature = 0.9, max_completion_tokens = 10)

result = chat.invoke("What is the capital of France?")

print(result)
## string input and output