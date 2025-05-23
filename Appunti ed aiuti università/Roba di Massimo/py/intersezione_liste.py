def intersezione_liste( a, b ):
    '''
    input: a, b: liste
    output: lista c contenente gli elementi che sono sia in a che in b, senza ripetizioni
    '''
    c = []
    
    for e in a: # n iterazioni
        if e in b and not e in c: # O(m) + O(n). Se e è anche in b ma non è già presente in c
            c.append(e) # O(1)
    # "e" scorre "a" ma nel secondo for vede se si trova anche in "b"
    return c

