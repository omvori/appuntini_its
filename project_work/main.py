from crewai.flow.flow import Flow, start, listen
from langchain_community.tools.sql_database.tool import (
    InfoSQLDatabaseTool,
    ListSQLDatabaseTool,
    QuerySQLCheckerTool,
    QuerySQLDatabaseTool
)
from langchain_community.utilities.sql_database import SQLDatabase
from crewai import LLM, Agent, Task, Crew, Process
from crewai.tools import tool

# LLM Gemini
gemini_llm = LLM(model="gemini/gemini-2.5-flash", api_key="AIzaSyBqNeHTwiMlK-V2vFwr0O_FyNU7tCgm3pM")

# Connessione al database PostgreSQL
db = SQLDatabase.from_uri(
    database_uri="postgresql://postgres:admin@localhost:5432/database_agent",
    schema="utenti"
)

# Tool CrewAI
@tool("list_tables")
def list_tables_tool() -> str:
    """List the available tables in the DB."""
    return ListSQLDatabaseTool(db=db).invoke("")

@tool("tables_schema")
def tables_schema_tool(tables: str) -> str:
    """Show schema & sample rows for the given tables (comma-separated)."""
    return InfoSQLDatabaseTool(db=db).invoke(tables)

@tool("execute_sql")
def execute_sql_tool(sql_query: str) -> str:
    """Execute a SQL query against the DB. Returns the result as a string."""
    return QuerySQLDatabaseTool(db=db).invoke(sql_query)

@tool("check_sql")
def check_sql_tool(sql_query: str) -> str:
    """Check if the SQL query is correct. Returns suggestions/fixes or success message."""
    try:
        query_checker_tool = QuerySQLCheckerTool(db=db, llm=gemini_llm)
        return query_checker_tool.invoke(sql_query)
    except Exception as e:
        return f"Error using QuerySQLCheckerTool: {str(e)}"

# Agente CrewAI
ricercatore = Agent(
    role="Ricercatore di informazioni",
    goal="USANDO I TOOL forniti, raccogliere informazioni sulle persone contenute nella tabella utenti",
    backstory="Esperto di documentazione, specializzato nella ricerca e nell'analisi di dati strutturati",
    llm=gemini_llm,
    tools=[list_tables_tool, tables_schema_tool, execute_sql_tool, check_sql_tool],
    verbose=True
)

# Flow CrewAI che costruisce dinamicamente il task
class SQLAgentFlow(Flow):
    @start()
    def ricevi_richiesta(self):
        return "Richiesta ricevuta"

    @listen(ricevi_richiesta)
    def crea_task_ed_esegui(self, previous_result):
        richiesta = self.state["richiesta"]

        task = Task(
            description=richiesta,
            expected_output="Risposta dettagliata e coerente con la richiesta.",
            agent=ricercatore
        )

        crew = Crew(
            agents=[ricercatore],
            tasks=[task],
            process=Process.sequential
        )

        print("🚀 Avvio del task con richiesta:", richiesta)
        risultato = crew.kickoff()
        self.state["risultato"] = risultato
        return "Task completato"

    @listen(crea_task_ed_esegui)
    def riepilogo(self, previous_result):
        return f"""
🧾 Riepilogo:
- Richiesta: {self.state['richiesta']}
- Risultato: {self.state['risultato']}
"""

# Esecuzione del flow
if __name__ == "__main__":
    print("🧠 Scrivi cosa vuoi sapere dal database (es. 'Mostrami gli utenti attivi sopra i 30 anni'):")
    richiesta = input("> ")

    flow = SQLAgentFlow()
    flow.state["richiesta"] = richiesta
    flow.state["risultato"] = None

    final = flow.kickoff()
    print("\n🎯 Risultato finale:")
    print(final)
    print("\n📦 Stato finale:")
    print(flow.state)