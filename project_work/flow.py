from crewai import Agent, Crew, Process, Task,LLM,Flow
from crewai.flow.flow import Flow, start, listen
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

from agents import sql_querier



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
            agent=sql_querier
        )

        crew = Crew(
            agents=[sql_querier],
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