from langgraph.graph import StateGraph, START, END
from typing import TypedDict, Annotated
from langchain_core.messages import HumanMessage, SystemMessage, BaseMessage
from langchain_ollama import ChatOllama
from dotenv import load_dotenv
from pydantic import BaseModel, Field
from langgraph.checkpoint.memory import InMemorySaver
from langgraph.graph.message import add_messages

load_dotenv()

model = ChatOllama(
    model="llama3",  # or any model you have pulled
    temperature=0
) 


class ChatState(TypedDict):
    messages : Annotated[list[BaseMessage], add_messages]
    
    
def chat_node(state : ChatState):

    # take user query from state
    messages = state['messages']
    
    # send to llm
    response = model.invoke(messages)
    
    # response store state
    return {'messages' : [response]}

checkpointer = InMemorySaver()

graph = StateGraph(ChatState)

# Add_nodes
graph.add_node('chat_node', chat_node)

graph.add_edge(START, 'chat_node')
graph.add_edge('chat_node', END)

chatbot = graph.compile(checkpointer=checkpointer)

