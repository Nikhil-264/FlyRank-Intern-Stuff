from langchain_core.prompts import ChatPromptTemplate, MessagesPlaceholder
from langchain_core.messages import HumanMessage, AIMessage

chat_template = ChatPromptTemplate.from_messages([
    ('system', 'You are a helpful {domain} expert.'),
    MessagesPlaceholder(variable_name='chat_history'),
    ('human', 'Explain in simple terms what is {topic}?')
])

chat_history = [
    HumanMessage(content="I want to request a refund for my order #12345."),
    AIMessage(content="Your refund request has been initiated.")
]

prompt = chat_template.invoke({
    'domain': 'machine learning',
    'topic': 'overfitting',
    'chat_history': chat_history
})

print(prompt.messages)