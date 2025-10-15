from flow import Flow_fly

if __name__ == "__main__":
    richiesta = input("Inserisci la tua richiesta di prenotazione volo: ")
    
    flow = Flow_fly()
    flow.state["richiesta"] = richiesta
    
    final = flow.kickoff()
    print("\n=== RISULTATO FINALE ===")
    print(final)
