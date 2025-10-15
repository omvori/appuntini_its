from crewai.flow.flow import Flow, start, listen, router
from crewai import Crew, Process, Task
from agents import welcome_agent, sql_inserter,sql_asker, output_agent
from agents import welcome_task,inserter_task,output_task,asker_task
from config import list_tables_tool, tables_schema_tool, execute_sql_tool



class Flow_fly(Flow):
    @start()
    def start_to_ex(self):
        print("1. Inserire nuovo biglietto")
        print("2. Estrarre biglietto esistente")
        
        self.state["checker"] = input("\n Scegli un'opzione (1 o 2): ").strip()
        
        return "menu_shown"
    
    @router(start_to_ex)
    def check(self):
        if self.state["checker"] == "1":
            return "insert"
        elif self.state["checker"] == "2":
            return "query"
        else:
            print("Opzione non valida!")
            return "insert"
    
    @listen("insert")
    def db_insert(self, prev_res):
        
        self.state["welcome_result"] = input("Inserire i dati (destinazione,nome,cognome,data): ").strip()
        
        sql_crew = Crew(
            agents=[sql_inserter],
            tasks=[inserter_task],
            process=Process.sequential
        )
        
        inputs = {'richiesta': self.state["welcome_result"]}
        result = sql_crew.kickoff(inputs=inputs)
        self.state["db_result"] = result
        return result

    @listen("insert")
    def out_ex_ticket(self, prev_res):
        db_result = self.state.get("db_result", "")
        
        from crewai import Task
        import json
        
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
            
            Restituisci il risultato in formato JSON con questa struttura:
            {{
                "passeggero": {{"nome": "", "cognome": ""}},
                "destinazione": "",
                "data": "",
                "numero_conferma": ""
            }}
            
            IMPORTANTE: Usa SOLO i dati forniti sopra, non inventare informazioni!
            IMPORTANTE: Estrai i dati REALI da {db_result}, non usare dati di default!
            ''',
            agent=output_agent,
            expected_output='JSON formattato con i dati reali del passeggero e biglietto'
        )

        out_crew = Crew(
            agents=[output_agent],
            tasks=[dynamic_output_task],
            process=Process.sequential
        )
        
        result = out_crew.kickoff(inputs={"db_data": str(db_result)})
        self.state["final_result"] = result
        
        # Salva il JSON
        try:
            with open("biglietto_output.json", "w", encoding="utf-8") as f:
                json.dump({"ticket": str(result)}, f, indent=2, ensure_ascii=False)
            print("\n✓ Biglietto salvato in 'biglietto_output.json'")
        except Exception as e:
            print(f"Errore nel salvataggio JSON: {e}")
        
        return result
        
    @listen("query")
    def db_query(self, prev_res):
             
        self.state["welcome_result"] = input("Inserire i dati ").strip()
        
        sql_crew = Crew(
            agents=[sql_asker],
            tasks=[asker_task],
            process=Process.sequential
        )
        
        inputs = {'richiesta': self.state["welcome_result"]}
        result = sql_crew.kickoff(inputs=inputs)
        self.state["db_result"] = result
        return result


    
    @listen("failed")
    def out_error(self, prev_res):
        print("Errore nell'inserimento: flow fallito")