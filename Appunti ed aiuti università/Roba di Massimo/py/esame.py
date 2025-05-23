#Si scriva una funzione, denominata mode , che prenda in input una lista di numeri e restituisca la lista degli elementi di a che compaiono più frequentemente.

def mode(a):
    #utilizzo i dizionari per contare quante volte compaiono gli elementi nella lista visto che nei dizionari l'ordine non conta
    dizionario={}
    for i in a: #contatore i si scorre la lista a
        if i not in dizionario: #vede se l'elemento i-esimo di a si trova nel dizionario
            dizionario[i]=0     #l'occorrenza dell'elemento i preso in considerazione rimane invariato
        dizionario[i]+=1        #l'occorrenza dell'elemento i preso in considerazione viene incrementata di 1
    occorrenze= max(dizionario.values()) #dopo lo scorriemento della lista si trova l'occorrenza più grande  
    lista=[i for i in dizionario if dizionario[i]==occorrenze] #creazione della lista
    return lista
#la funzione ha costo temporale O(n) in quanto deve scorrere tutti gli elementi della lista a in input.
#il costo spaziale nel caso peggiore può essere O(n) nel caso in cui tutti gli elementi hanno la stessa occorrenza

