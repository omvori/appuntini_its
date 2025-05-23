print( (3, 2) < (1, 6, 9) ) #False
print( (3, 2) < (3, 6, 9) ) #True
print( (3, 6) < (3, 6, 9) ) #True
def numeristringhe( e ): #mette in ordine le stringhe all'interno di una lista ponendole a destra
    if type (e) == str:
        return (1, e)
    else:
        return (0, e)
a = [3.14, 'python',2,'programma',12,0,'stringa']
print(sorted(a, key=numeristringhe)) #sorted tra float e stringhe non si può fare quindi si deve unire il sorted per i numeri con quello per le stringhe

#sort() è solo per le liste
#sorted è per tutto