def intersezione_dizionari( d0, d1, f = lambda x, y: x+y ):
    '''
    input: d0 e d1 dizionari che mappano stringhe in numeri
    output: un dizionario c tale che:
        - le chiavi di c sono quelle comuni in d0 che in d1
        - se k è una chiave di c allora c[k] = f(d0[k], d1[k]) 
    '''
    n, m = len(d0), len(d1)
    
    dt0, dt1 = (d1, d0) if n > m else (d0, d1) # alias costo O(1)
    
    # equivalente a...
    # if n > m:  
    #     dt0, dt1 = d1, d0 # alias costo O(1)
    # else:
    #     dt0, dt1 = d0, d1 # alias costo O(1)
    c = {}
    
    for e in dt0: # n iterazioni
        if e in dt1:
            c[e] = f(dt0[e], dt1[e]) # O(1)
            
    return c

    # Complessità temporale: min( Theta(n), Theta(m) )
    
a = {'uno':1, 'due': 2, 'quattro':4, 'sei':6}
b = {'uno':10,  'quattro':30, 'zero':0}

c = intersezione_dizionari(a, b)

print(c) #dizionario con chiavi comuni ad entrambi i dizionari 
         #gli elementi associati alle chiavi comuni verranno addizionati tramite f
