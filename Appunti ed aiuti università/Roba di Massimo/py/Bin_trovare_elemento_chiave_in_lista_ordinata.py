def bin_search( a, k ):
    '''
    Parameters
    ----------
    a : una lista ORDINATA
    k : una chiave di ricerca

    Returns
    -------
    Un int p
     - Se k è in a restituisce p tale che a[p] == k
     - Se k non è in a restituisce -1
    '''
    #n = len(a)
    sx, rx = 0, len(a)
    # ricerco k in a[sx:rx]
    
    while rx > sx:
        cx = (sx+rx)//2
        if a[cx] == k:
            return cx
        if k < a[cx]:  #vedo se k è più piccolo del valore a metà della lista
            rx = cx   #se k si trova nella prima metà allora il mio nuovo limite destro per lo studio della lista diventa la metà di essa
        else:
            sx = cx+1 #se k si trova nella seconda metà allora il mio limite sx della lista aumenta di 1 portando lo studio della lista una posizione avanti
            
    return -1

    # Complessità spaziale: O(1)
    # Complessità temporale: O(log n)

   

    