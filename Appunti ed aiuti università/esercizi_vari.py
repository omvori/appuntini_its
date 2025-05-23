#****ESAME****

# Si scriva una funzione, denominata second_max , che prenda in input una lista di numeri e restituisca il
# secondo numero in ordine di grandezza tra quelli in a . Se a non contiene questo numero (ad
# esempio se la lista contiene meno di due elementi, o gli elementi della lista sono tutti uguali), la
# funzione restituisca None


def second_max(a):
    for i in range(len(a) - 1):
        if a[i] != a[i+1]:
            def bb_sort(x):
               n = len(x)
               i = 0
               ordinata = False
               c = 0
     
               while not ordinata and c < n:
                ordinata = True
                for i in range(n-1-c):
                 if x[i] > x[i+1]:
                  x[i],x[i+1] = x[i+1],x[i]
                  ordinata = False
                  c+=1
    if len(a)<2:
        return None
    bb_sort(a)
    maxval = a[-2]
    return maxval
    
            
     

arr = [5,5,53,12,3,21]
print(second_max(arr))
