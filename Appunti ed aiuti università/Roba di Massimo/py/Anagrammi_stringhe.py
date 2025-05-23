stringa_1=input('inserire stringa 1:')
stringa_2=input('inserire stringa 2 anagramma stringa 1:')

lista_1=[]
lista_2=[]

for i in range(len(stringa_1)):
    lista_1.append(stringa_1[i]) #converto ogni carattere della stringa in un elemento di una nuova lista
for i in range(len(stringa_2)):
    lista_2.append(stringa_2[i])


def bubble_sort( a ):
    n = len(a)

    for c in range(n-1):
        for i in range(n-1): #servono due for perchè non basta scorrerla una volta
            if a[i] > a[i+1]:
                a[i], a[i+1] = a[i+1], a[i]
                
bubble_sort(lista_1)
bubble_sort(lista_2)   #un alternativa era fare sorted(lista1 e lista 2) e vedere se sono uguali

print(lista_1)
print(lista_2)

if lista_1 == lista_2:
    print('Anagrammi')
else:
    print('Non sono anagrammi')