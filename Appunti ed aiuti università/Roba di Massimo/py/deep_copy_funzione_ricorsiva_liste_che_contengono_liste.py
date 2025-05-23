def deep_copy(a):
    b=[]
    for e in a:
        if type(e)==list:     # se l'elemento è una sottolista si richiama la funzione su di essa  
            b.append(deep_copy(e))
        else:
            b.append(e)
    print(b)        
    return b
c=[1,2,[3,6,7],5,[4,0]]
deep_copy(c)

#data una lista contenente altre liste, le quali a loro volta possono contenere altre liste, deep_copy() 

#tramite una funzione ricorsiva "smonta" la le liste e crea una copia per ogni lista contenuta in un'altra lista

#l'output sarà la serie di liste prese singolarmente e non contenute tra di loro