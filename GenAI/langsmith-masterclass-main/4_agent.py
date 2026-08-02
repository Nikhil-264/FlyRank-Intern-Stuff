from dotenv import load_dotenv
import requests
import os

from langchain_ollama import ChatOllama
from langchain_core.tools import tool
from langchain_community.tools import DuckDuckGoSearchRun

from langgraph.prebuilt import create_react_agent

os.environ['LANGCHAIN_PROJECT'] = 'agent-demo'


load_dotenv()

# ---------------- TOOLS ----------------

search_tool = DuckDuckGoSearchRun()


@tool
def get_weather_data(city: str) -> str:
    """
    Fetch current weather for a city.
    """

    url = (
        f"https://api.weatherstack.com/current"
        f"?access_key=f12d01391122d94416d488b09d7f7079"
        f"&query={city}"
    )

    response = requests.get(url, timeout=10)

    return str(response.json())


# ---------------- LLM ----------------

llm = ChatOllama(
    model="qwen3",
    temperature=0
)

# ---------------- AGENT ----------------

agent = create_react_agent(
    model=llm,
    tools=[search_tool, get_weather_data]
)

# ---------------- INVOKE ----------------

response = agent.invoke(
    {
        "messages": [
            (
                "user",
                "Identify the birthplace of Kalpana Chawla and give us the current temperature in that city?"
            )
        ]
    }
)

print(response)

print("\nFinal Answer:")
print(response["messages"][-1].content)