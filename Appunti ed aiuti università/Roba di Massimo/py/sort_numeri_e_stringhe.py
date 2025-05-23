lista=[1,2,3,4,'ciao','come','stai',3,8]
funzione=lambda e: (1,e) if type(e)==str else (0,e)
lista1=sorted(lista,key=funzione)
print(lista1) 
