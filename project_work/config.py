from crewai import Agent, Crew, Process, Task,LLM
from langchain_community.utilities.sql_database import SQLDatabase
import psycopg2
from langchain.tools import tool
from langchain_community.tools.sql_database.tool import (
    InfoSQLDatabaseTool,
    ListSQLDatabaseTool,
    QuerySQLCheckerTool,
    QuerySQLDatabaseTool)
from langchain_community.utilities.sql_database import SQLDatabase
from crewai_tools import PGSearchTool,NL2SQLTool




db= SQLDatabase.from_uri("postgresql://postgres:admin@localhost:5432/project_voli",schema = "project_voli,public")
llm=dict(
    provider="google",
    config=dict(
        model="gemini/gemini-2.5-flash-lite",
        api_key="AIzaSyCnYceW0CMqKlGoFaiI6hW4Qq61Cwga9m8",  # aggiungi qui
    ),
),

#verifica di connessione
try:
    tables = db.run("SELECT table_name FROM information_schema.tables WHERE table_schema='public';")
    print("Connessione riuscita, Tabelle trovate:")
    print(tables)
except Exception as e:
    print("Errore di connessione al database:", e)



#tool per ricercare dentro al db
pg_search = PGSearchTool(
    db_uri='postgresql://postgres:admin@localhost:5432/project_voli',
    table_name="passeggeri",
    config=dict(
        llm=dict(
            provider="google",
            config=dict(
                model="gemini/gemini-2.5-flash-lite",
                api_key="AIzaSyCnYceW0CMqKlGoFaiI6hW4Qq61Cwga9m8",  # <- aggiungi qui
                # temperature=0.5,
                # top_p=1,
                # stream=true,
            ),
        ),
        embedder=dict(
            provider="ollama",
            config=dict(
                model="bge-m3:latest",
            ),
        ),
    )
)



# Definizione del tool
@tool("input_tastiera")
def input_tastiera_tool(prompt: str) -> str:
    """Richiedi all'utente di inserire dei dati manualmente tramite tastiera."""
    return input(f"\n Agente: {prompt} \n\n Tu: ")


@tool("execute_sql")
def execute_sql(sql_query: str) -> str:
    #esegue una query nel database
    return QuerySQLDatabaseTool(db=db).invoke(sql_query) 

#run del tool 
execute_sql.run("SELECT * FROM passeggeri")

