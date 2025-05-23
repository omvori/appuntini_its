dizionario = {"name": "John", "country": "Norway"}
separatore = " TEST "

x = separatore.join(dizionario) #aggiunte separatore tra le chiavi del dizionario 
                                #essenzialmente dove vi sono normalmente le virgole
print(x)  # name TEST country     #nel caso dei dizionari non vengono stampati gli item