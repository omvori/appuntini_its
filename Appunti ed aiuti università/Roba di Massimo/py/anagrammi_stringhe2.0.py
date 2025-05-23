def anagrammi(a, b):
    '''
        Input: a, b due stringhe
        Return: True se e solo se a e b sono anagrammi
    '''
    
    if len(a) != len(b): # O(1)
        return False
    
    # n = len(a) = len(b)
    
    # da =  db = {} # NO! da è alias di db
    da, db = {}, {} # 2 dizionari vuoti
      
    for x,y in zip(a, b):          #non importa l'ordine delle chiavi, due dizionari sono uguali anche se le loro chiavi hanno ordini diversi
        da[x] = da.get(x, 0) + 1   #viene aggiunto 1 per aver un avere un counter di quante volte ho quella lettera, altrimenti
        db[y] = db.get(y, 0) + 1   #cane e caaaaneeeee risulterebbero uguali
    
    return da == db # O(n)  
        
    # Complessità temporale è O(n)
    # Complessità spaziale è O(n)

# funzione incorporata id()
    
print(anagrammi('pane', 'nepa'))