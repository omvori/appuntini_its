from crewai import Agent, Crew, Process, Task,LLM
from langchain_community.utilities.sql_database import SQLDatabase
import psycopg2
from langchain_community.tools.sql_database.tool import (
    InfoSQLDatabaseTool,
    ListSQLDatabaseTool,
    QuerySQLCheckerTool,
    QuerySQLDatabaseTool)
from langchain_community.utilities.sql_database import SQLDatabase



db= SQLDatabase.from_uri("postgresql://postgres:admin@localhost:5432/project_fly",schema = "project_fly,public")


#verifica di connessione
try:
    tables = db.run("SELECT table_name FROM information_schema.tables WHERE table_schema='public';")
    print("Connessione riuscita, Tabelle trovate:")
    print(tables)
except Exception as e:
    print("Errore di connessione al database:", e)



tool = InfoSQLDatabaseTool()

