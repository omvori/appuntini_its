from crewai.flow.flow import Flow, start, listen
from crewai import Crew, Process, Task
from agents import welcome_agent, sql_querier, output_agent
from agents import welcome_task
from config import list_tables_tool, tables_schema_tool, execute_sql_tool

class Flow_fly(Flow):

    @start
    def start_to_ex(self):
        welcome_crew = Crew(
            agents=[welcome_agent],
            tasks=[welcome_task],
            process=Process.sequential
        )
        
        result = welcome_crew.kickoff()
        self.state["welcome_result"] = result
        return result 

    @listen(start_to_ex)
    def db_search(self, prev_res):

        richiesta = self.state["richiesta"]
        
        # Task DINAMICO con la richiesta specifica
        dynamic_query_task = Task(
            description=f"Process this flight booking request: '{richiesta}'. Use the database tools to search or create bookings.",
            expected_output="Database results with flight details.",
            agent=sql_querier,
            tools=[list_tables_tool, tables_schema_tool, execute_sql_tool]
        )
        
        sql_crew = Crew(
            agents=[sql_querier],
            tasks=[dynamic_query_task],
            process=Process.sequential
        )
        result = sql_crew.kickoff()
        self.state["db_result"] = result
        return result
    
    @listen(db_search)
    def out_ex(self, prev_res):
        
        db_result = self.state.get("db_result", "")
        
        dynamic_output_task = Task(
            description=f"Format this flight data: {db_result}",
            expected_output="Professional flight ticket with all details.",
            agent=output_agent
        )
        
        out_crew = Crew(
            agents=[output_agent],
            tasks=[dynamic_output_task],
            process=Process.sequential
        )
        
        result = out_crew.kickoff()
        self.state["final_result"] = result
        return result  
