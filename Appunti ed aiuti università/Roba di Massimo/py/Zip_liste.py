a=[3,4,5,6]
b=['tre','quattro','cinque','sei']
for e in zip(a,b):
    print(e)
#date due liste lo zip unisce gli elementi di esse a coppie in tuple diverse
for e,c in zip(a,b):
    print(e,c) #per stampare le coppie senza inserirle in tuple

    