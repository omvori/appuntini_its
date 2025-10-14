from crewai import Agent,LLM,crew
from langchain.tools import tool
from langchain_community.tools.sql_database.tool import (
    InfoSQLDatabaseTool,
    ListSQLDatabaseTool,
    QuerySQLCheckerTool,
    QuerySQLDatabaseTool)
from config import db

gemini_llm = LLM(model="gemini/gemini-2.5-flash", api_key="AIzaSyBqNeHTwiMlK-V2vFwr0O_FyNU7tCgm3pM")


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


#run del tool 

sql_querier = Agent(
    role="Ricercatore di informazioni",
    goal="USANDO I TOOL forniti, raccogliere informazioni sulle persone contenute nella tabella utenti",
    backstory="Esperto di documentazione, specializzato nella ricerca e nell'analisi di dati strutturati",
    llm=gemini_llm,
    tools=[list_tables_tool, tables_schema_tool, execute_sql_tool, check_sql_tool],
    verbose=True
)

