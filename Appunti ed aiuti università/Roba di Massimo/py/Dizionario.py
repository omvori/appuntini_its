#crea un dizionario
informazioni = {'nome': 'Dionysia', 'età': 28, 'luogo': 'Atene'} #dizionario={chiave:valore,chiave2:valore2...}
d2 = {'altezza':'2,4'}
print(informazioni)               #{'nome': 'Dionysia', 'età': 28, 'luogo': 'Atene'}
print(informazioni['età'])        #28

print(informazioni.items())            # .items = elementi del dizionario come insieme di tuple
print(informazioni.keys())             # .keys = retituisce le chiavi
print("-----")            
print(informazioni.values())           # .values = restituisce i valori
print(informazioni.get('nome'))        # .get (chiave, valore/default) = restituisce valore associato alla chiave
print(informazioni.pop('luogo'))       # .pop (chiave, valore/default) = rimuove e restituisce valore associato alla chiave
print(informazioni.popitem())          # .popitem = rimuove e restituisce un elemento arbitrario 
print(informazioni.update({'a':1}))    # .update = aggiunge gli elementi nelle () a quelli di informazioni
print(informazioni.copy())             # .copy = restituisce una copia del dizionario
print(informazioni.clear())            # .clear = rimuove tutti gli elementi

