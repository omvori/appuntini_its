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
    role="Database Insert Specialist",
    goal="Insert user flight booking data into the 'passeggeri' table using SQL INSERT or the SELECT * FROM commands",
    backstory="Expert in database operations and SQL queries, specialized in structured data insertion",
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
    description='''
    DATI DA PROCESSARE: {richiesta}
    
    STEP OBBLIGATORI:
    1. Dividi {richiesta} usando la virgola: [destinazione, nome, cognome, data]
       Esempio: "Roma,Andrea,Cazzi,10-20-2027" diventa ['Roma', 'Andrea', 'Cazzi', '10-20-2027']
    
    2. Converti la data:
       - Input: MM-DD-YYYY o DD-MM-YYYY
       - Output: YYYY-MM-DD
       Esempio: "10-20-2027" diventa "2027-10-20"
    
    3. CHIAMA execute_sql_tool con questa query (sostituisci con i valori estratti):
       INSERT INTO passeggeri (destinazione, nome, cognome, data_viaggio) 
       VALUES ('Roma', 'Andrea', 'Cazzi', '2027-10-20');
    
    4. CHIAMA execute_sql_tool per verificare:
       SELECT * FROM passeggeri ORDER BY id DESC LIMIT 1;
    
    IMPORTANTE: Usa i valori REALI da {richiesta}, non i placeholder!
    ''',
    agent=sql_querier,
    expected_output='Dati del record inserito (destinazione, nome, cognome, data, id)',
    tools=[list_tables_tool, tables_schema_tool, execute_sql_tool]
)


output_task = Task(
    description="Format the flight booking information into a clear, readable ticket.",
    expected_output="Valid JSON string that can be directly parsed",
    agent=output_agent,
)
