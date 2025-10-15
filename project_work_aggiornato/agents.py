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

sql_inserter = Agent(
    role="Database Insert Specialist",
    goal="Insert user flight booking data into the 'passeggeri' table using SQL INSERT or the SELECT * FROM commands",
    backstory="Expert in database operations and SQL queries, specialized in structured data insertion",
    llm=gemini_llm,
    tools=[list_tables_tool, tables_schema_tool, execute_sql_tool],
    verbose=True,
    allow_delegation=False
)

sql_asker = Agent(
    role="Database Asker Specialist",
    goal="ASK THE DATABASE USING SELECT * FROM commands, USE THE TOOLS AND SEARCH FOR THE RESULT IN THE DATABASE",
    backstory="Expert in database operations and SQL queries, specialized in structured queries",
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


welcome_task = Task(
    description="Welcome the client and gather the following information in order: 1) Flight destination, 2) Name, 3) Surname, 4) Preferred flight date.",
    expected_output="All collected information formatted for database operations.",
    agent=welcome_agent
)

inserter_task= Task(
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
       INSERT INTO passeggeri (flight_destination, nome, cognome, preferred_flight_date) 
       VALUES ('Roma', 'Andrea', 'Cazzi', '2027-10-20');
    
    4. CHIAMA execute_sql_tool per verificare:
       SELECT * FROM passeggeri LIMIT 1;
    
    IMPORTANTE: Usa i valori REALI da {richiesta}, non i placeholder!
    IMPORTANTE: I nomi delle colonne sono: flight_destination, nome, cognome, preferred_flight_date
    ''',
    agent=sql_inserter,
    expected_output='Dati del record inserito (flight_destination, nome, cognome, preferred_flight_date)',
    tools=[list_tables_tool, tables_schema_tool, execute_sql_tool]
)

asker_task = Task(
    description='''
    DATI DA PROCESSARE: {richiesta}
    
    STEP OBBLIGATORI:
    1. Analizza la richiesta {richiesta} per identificare:
       - Le colonne richieste (es: *, nome, cognome, ecc.)
       - Le condizioni WHERE (se presenti)
       - Le clausole aggiuntive (ORDER BY, LIMIT, ecc.)
    
    2. Costruisci una query SELECT SQL valida basata sulla richiesta
       Esempio: "mostrami tutti i passeggeri per Roma" â†’ "SELECT * FROM passeggeri WHERE flight_destination = 'Roma'"
       Esempio: "nomi e cognomi dei passeggeri" â†’ "SELECT nome, cognome FROM passeggeri"
    
    3. CHIAMA execute_sql_tool con la query costruita
    
    4. Restituisci i risultati della query
    
    IMPORTANTE: 
    - La tabella si chiama 'passeggeri'
    - Le colonne disponibili sono: flight_destination, nome, cognome, preferred_flight_date
    - Assicurati che la query sia sintatticamente corretta
    - Gestisci appropriatamente le stringhe (usando apici singoli) e i numeri
    - Se non ci sono condizioni specifiche, usa una query di base come "SELECT * FROM passeggeri LIMIT 10"
    ''',
    agent=sql_asker,
    expected_output='Risultati della query SQL eseguita sul database',
    tools=[list_tables_tool, tables_schema_tool, execute_sql_tool]
)


output_task = Task(
    description="Format the flight booking information into a clear, readable ticket.",
    expected_output="Valid JSON string that can be directly parsed",
    agent=output_agent,
    output_file="biglietto.json"

)