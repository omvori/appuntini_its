#calcolare numero di interi nella lista 'a' e nelle sue sottoliste
def conta_interi(x,n):
    i=0
    for e in x:
        if type(e)==int:
            i+=1
        else:
            if type(e) == list:    #se l'elemento è una lista si richiama la funzione che analizzerà i suoi elementi
                conta_interi(e,n)
        n=n+i
    return n
a=[4,5,[4,5,6,5,[10,11]],7,8,[12,13,[2,3],7,8]]
print('numero interi nella lista',conta_interi(a,0))





