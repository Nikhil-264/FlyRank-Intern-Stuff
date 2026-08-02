from langchain_anthropic import ChatAnthropic
from dotenv import load_dotenv
load_dotenv()
chat = ChatAnthropic(model = "claude-2", temperature = 0.9, max_completion_tokens = 10)

result = chat.invoke("What is the capital of France?")

print(result)