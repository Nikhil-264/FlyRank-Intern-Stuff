from langchain_google_genai import ChatGoogleGenerativeAI
from dotenv import load_dotenv

load_dotenv()

chat = ChatGoogleGenerativeAI(model = "gemini-pro", temperature = 0.9, max_completion_tokens = 10)

result = chat.invoke("What is the capital of France?")

print(result.content)