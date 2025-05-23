a=[3,5,7,9,10,21]
b=[1,2,6,8,16,23]
def merge(a,b):   #date due liste con numeri diversi e crescenti
    n,m=len(a),len(b)
    c=[]
    i,j=0,0
    while i<n and j<m:
        if a[i]<b[j]:       
            c.append(a[i]) #viene aggiunt l'elemento a[i] se più piccolo di b[j]   
            i+=1
        else:
            c.append(b[j]) #viene aggiunto l'elemento b[j] se più piccolo di a[i]
            j+=1
    if i==n:
        c.extend(b[j:])
    else:
        c.extend(a[i:])
    return c
merge(a,b)
print(merge(a,b))