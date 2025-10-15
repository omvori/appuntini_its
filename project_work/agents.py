from crewai import Agent, LLM, Task
from config import list_tables_tool, tables_schema_tool, execute_sql_tool, gemini_llm

# Agents
welcome_agent = Agent(
    role="Client Welcoming Agent",
    goal="Welcome the client and gather flight booking information in this order: destination, name, surname, preferred date",
    backstory="You are an experienced flight assistant, excellent at making people comfortable and very organized",
    llm=gemini_llm,
    verbose=True,
    allow_delegation=False
)

sql_querier = Agent(
    role="Database Query Specialist",
    goal="Use the provided tools to query or insert data into the database based on user requirements. YOU MUST USE THE TOOLS PROVIDED.",
    backstory="Expert in database operations and SQL queries, specialized in structured data analysis",
    llm=gemini_llm,
    tools=[list_tables_tool, tables_schema_tool, execute_sql_tool],  
    verbose=True,
    allow_delegation=False
)

output_agent = Agent(
    role="Ticket Formatter",
    goal="Format flight booking information into a clear, readable ticket for the client",
    backstory="You are a machine that emits flight tickets in a clean and comprehensible way",
    llm=gemini_llm,
    allow_delegation=False
)

# Tasks BASE
welcome_task = Task(
    description="Welcome the client and gather the following information in order: 1) Flight destination, 2) Name, 3) Surname, 4) Preferred flight date.",
    expected_output="All collected information formatted for database operations.",
    agent=welcome_agent
)

query_task = Task(
    description="Use the database tools to query or insert flight booking information.",
    expected_output="Database query results or confirmation of data insertion.",
    agent=sql_querier,
    tools=[list_tables_tool, tables_schema_tool, execute_sql_tool]  
)

output_task = Task(
    description="Format the flight booking information into a clear, readable ticket.",
    expected_output="A clear flight ticket description and JSON representation.",
    agent=output_agent
)
