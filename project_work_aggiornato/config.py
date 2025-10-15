from crewai import LLM
from langchain_community.utilities.sql_database import SQLDatabase
from crewai.tools import BaseTool
from pydantic import Field
from langchain_community.tools.sql_database.tool import (
    InfoSQLDatabaseTool,
    ListSQLDatabaseTool,
    QuerySQLDatabaseTool)

# Configurazione database
db = SQLDatabase.from_uri(
    "postgresql://postgres:admin@localhost:5432/project_fly", 
    schema="public",
    sample_rows_in_table_info=0
)
gemini_llm = LLM(model="gemini/gemini-2.5-flash-lite", api_key="AIzaSyCbbeKN4EAaA5sJ5OCxRshpjopAA4OcHsM")

# Verifica connessione
try:
    tables = db.run("SELECT table_name FROM information_schema.tables WHERE table_schema='public';")
    print("Connessione riuscita, Tabelle trovate:")
    print(tables)
except Exception as e:
    print("Errore di connessione al database:", e)

# Tools CrewAI compatibili
class ListTablesTool(BaseTool):
    name: str = "list_tables_tool"
    description: str = "Useful for listing all tables in the database"
    
    def _run(self) -> str:
        tool = ListSQLDatabaseTool(db=db)
        return tool.run()

class TableSchemaTool(BaseTool):
    name: str = "tables_schema_tool"
    description: str = "Useful for getting the schema of specific tables"
    
    def _run(self, table_names: str) -> str:
        tool = InfoSQLDatabaseTool(db=db)
        return tool.run(table_names)

class ExecuteQueryTool(BaseTool):
    name: str = "execute_sql_tool"
    description: str = "Useful for executing SQL queries on the database (SELECT, INSERT, UPDATE, DELETE)"
    
    def _run(self, query: str) -> str:
        try:
            result = db.run(query)
            
            if query.strip().upper().startswith(('INSERT', 'UPDATE', 'DELETE')):
                return f"Query eseguita con successo: {result if result else 'Operazione completata'}"
            
            return str(result)
            
        except Exception as e:
            return f"Errore: {str(e)}"
        
# Istanze tool
list_tables_tool = ListTablesTool()
tables_schema_tool = TableSchemaTool()
execute_sql_tool = ExecuteQueryTool()