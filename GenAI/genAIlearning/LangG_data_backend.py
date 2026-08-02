from langgraph.graph import StateGraph, START, END
from typing import TypedDict, Annotated
from langchain_core.messages import HumanMessage, SystemMessage, BaseMessage
from langchain_ollama import ChatOllama
from dotenv import load_dotenv
from pydantic import BaseModel, Field
from langgraph.checkpoint.sqlite import SqliteSaver
from langgraph.graph.message import add_messages
import sqlite3

load_dotenv()

model = ChatOllama(
    model="qwen3",  # or any model you have pulled
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

sqlite_conn = sqlite3.connect("checkpointer.db", check_same_thread=False)
checkpointer = SqliteSaver(sqlite_conn)

graph = StateGraph(ChatState)

# Add_nodes
graph.add_node('chat_node', chat_node)

graph.add_edge(START, 'chat_node')
graph.add_edge('chat_node', END)

chatbot = graph.compile(checkpointer=checkpointer)

def retrieve_all_threads():
    threads = set()
    for checkpoint in checkpointer.list(None):
        threads.add(checkpoint.config['configurable']['thread_id'])
    return list(threads)  
