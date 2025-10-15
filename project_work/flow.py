from crewai.flow.flow import Flow, start, listen
from crewai import Crew, Process, Task
from agents import welcome_agent, sql_querier, output_agent
from agents import welcome_task,query_task,output_task
from config import list_tables_tool, tables_schema_tool, execute_sql_tool

class Flow_fly(Flow):

    @start()
    def start_to_ex(self):

        welcome_crew = Crew(
            agents=[welcome_agent],
            tasks=[welcome_task],
            process=Process.sequential
        )
        
        result = welcome_crew.kickoff()
        self.state["welcome_result"] = input("> ..")

        return result 
    
    @listen(start_to_ex)
    def db_search(self, prev_res):        
        
        sql_crew = Crew(
            agents=[sql_querier],
            tasks=[query_task],
            process=Process.sequential
        )
        
        # IMPORTANTE: passa l'input come variabile
        inputs = {'richiesta': self.state["welcome_result"]}

        result = sql_crew.kickoff(inputs=inputs)
        self.state["db_result"] = result
        return result
    
    @listen(db_search)
    def out_ex(self, prev_res):
        
        # Recupera i dati inseriti dal database
        db_result = self.state.get("db_result", "")
        
        # Crea un task dinamico con i dati reali
        from crewai import Task
        
        dynamic_output_task = Task(
            description=f'''
            Formatta questi dati reali del passeggero in un biglietto aereo professionale:
            
            DATI DAL DATABASE:
            {db_result}
            
            Crea un biglietto che include:
            - Nome completo del passeggero (nome + cognome)
            - Destinazione del volo
            - Data del viaggio
            - Numero di conferma (usa l'ID dal database)
            
            IMPORTANTE: Usa SOLO i dati forniti sopra, non inventare informazioni!
            ''',
            agent=output_agent,
            expected_output='Biglietto aereo formattato e JSON con i dati reali del passeggero'
        )

        out_crew = Crew(
            agents=[output_agent],
            tasks=[dynamic_output_task],
            process=Process.sequential
        )
        
        result = out_crew.kickoff()
        self.state["final_result"] = result
        return result
