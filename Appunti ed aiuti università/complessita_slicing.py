# -*- coding: utf-8 -*-
"""
Created on Mon Oct 16 21:21:45 2023

@author: dario
Programma per calcolare i palindromi 
La funzione restiuisce true se è palindromo 
"""
def palindromo (a) :
    i,n=0,len(a)
    while i<n//2:
        if a[i] !=a[n-1-i]:
            return False
        i+=1
        return True
    
    
    
a=input("Inserisci una stringa -> ")
print(palindromo(a))

#se n=len(a), richiede n^2 operazioni
#b occupa spazio 

#%%
"""
Operazione di slicing, crea una sottostringa a partire da una stringa dato 
un indice inziale e finale 

a={0123456789}
b=a[2:5]  -> b=234   lo slicing parte dall indice 2 e si ferma a 5-1
in generale data n=len(a)  b=[i:n] con i=0 e n=n-1 
con tre numeri interi modifico anche il passo 

a={0123456789}
b=a[1:8:2] -> b=1357 in passo di default è 2 
posso usare passo negativo e girare la stringa 
b=a[1:8:-1]=8765432
se ometto il primo indice usa di default 0 
b=a[:4:2] parte da 0 a 3 con passo 2 
se ometto l'ultimo finisce a n
b=[1::2] da 1 a n-1 con passo 2
se scrivo  b=a[::-1] ottengo la scritta invertita 
"""
def palindromo (a) :
    return (a==a[::-1])
    
a=input("Inserisci una stringa -> ")
print(palindromo(a))

#%% 
""" 
Programma per calcolare la radice quarta 
teoricamente se questo tipo di commento viene scritto dentro una 
funzione, chiamiamola per ipotesi funzione(x) allora facendo help(funzione(x))
appare la scritta dentro il commento 
"""

def radice_quarta(x) :
    """
    Parameters
    ----------
    x : TYPE INT o FLOAT 
        DESCRIPTION. prende in input x, lo assegna a y 

    Returns
    -------
    y : TYPE INT o FLOAT
        DESCRIPTION. richiama 2 volte la funzione radice_quadrata

    """
    y=radice_quadrata(radice_quadrata(x))
    return y

def radice_quadrata(x) :
    g=x
    while abs(g*g-x)>0.00001: #la funzione abs restituisce il valore assoluto 
        print(g)
        g=0.5*(g+x/g)
    return g
x=float(input("Inserisci il valore  -> "))
y=radice_quarta(x)
print("La radice quarta di ",x , " è ", y)

"""
python tutor è un sito online dove posso vedere tutti le operazioni che 
esegue il programma 

frame=ambiente dove mi sto muovendo, contiene i riferimenti agli ogetti del frame 
objects=oggetti in memoria.
parametro attuale=valore in fase di chiamata 
parametro formale  nome del valore nella funzione chiamata 


"""
#%% 

"""
La misura che quantifica l'efficenza di un programma è spazio e risorse. 
Bisogna contare il numero di operazioni elementari eseguite dal programma 
Operazioni elementari:aritmetiche,assegnazione di valori scalari 
confronto tra scalari e booleani
"""


def conta_parole( a ):
    # a è una stringa che rappresenta una frase
    # (parole separate da punteggiatura)
    # return numero di parole in a
    # i separatori sono: spazio, virgola e punto
    
    m = len(a) # 1 o 2 o 5... operazioni, dipende da len?
    
    n = 0 # numero di parole  # 1 operazione
    in_parola = False # 1 operazione
    
    for c in a:
        if c in ' .,': # 4 5 oppure 3 oppure...
            if in_parola: # 2 ops
                in_parola = False # 1 op
        else: # c è una lettera
            if not in_parola: # 2 ops  # nega il valore di in_parola
                in_parola = True # 1 op
                n += 1 # 3 ops 
                
    return n # 1 op

# costo complessivo al massimo 7 + m*8 + 1
# elimino le costanti additive
# costo 8*m meglio dire k*m dove k è una costante
# k non dipende da a (o da m)
# 
# 8*m
# 6*m
# 10*m
#
# si tratta di funzioni lineari in m
# introduco una notazione asintotica,
# il numero di operazioni eseguite dall'algoritmo è
# è in  O(m)
#
# in generale sia f(m) il numero di operazioni eseguite
# da un algoritmo su input di dimensione m
# l'algoritmo ha complessità temporale O(g(m)) se
# f(m) è in O(g(m))
#
# nel nostro caso f(m) = 7+8*m+1
# g(m) = m
#
# osservazione: la nostra f(m) è in O(m*m)
# f(m) è anche in O(m) e in Theta(m)
# O(m) contiene anche le funzioni 'più piccole'
# p.e. log(m) è in O(m) ma log(m) non è in Theta(m)


f = '. programmazione dei   calcolatori .  con,   laboratorio'
print(conta_parole(f))
# In[]

a = input('inserisci un testo ')

# voglio sapere la compl. temporale da qui in poi

n = len(a)

if 'A' in a:
    print('Si')
else:
    print('No')
    
# complessità è Theta(n) nel caso peggiore, 'A' non in a
# è Theta(n) anche nel caso medio.

# In[]

def conta_occorrenze(x, y):
    '''
    Input: x, e y sono due str len(y) < len(x)
    Ritorna: il numero di volte in cui y compare in x
    '''
    n, m = len(x), len(y)
    
    occ = 0
    i = 0 # la prima posizione della sottostringa di x in esame
    while i < n-m:
        if x[i:i+m] == y: # Theta(m) operazioni 
            occ += 1 # O(1) tempo costante
        i += 1 # O(1)
        
    return occ 

print(conta_occorrenze('prtghydfjuy7dfkiu', 'df'))
    
# Complessità temporale
#
# per n-m volte eseguo Theta(m) operazioni, in totale
# Theta(m(n-m))















