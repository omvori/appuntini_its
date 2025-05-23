def merge(a,sx,cx,dx):
    c=[]
    i,j=sx,cx
    while i<cx and j<dx:
        if a[i]<a[j]:
            c.append(a[i])
            i+=1
        else:
            c.append(a[j])
            j+=1
    if i ==cx:
        c.extend(a[j:dx])
    else:
        c.extend(a[i:cx])
    for i in range(len(c)):
        a[sx+i]=c[i]


def merge_sort(a,sx,dx):
    #a:una lista t.c per ogni coppia di elementi in a è definito l'operatore <
    #sx e dx=interi
    #Ordina a[sx:dx] dentro la funzione
    if dx==None:
        dx=len(a)
    n=dx-sx
    if n>=2:
        cx = (sx+dx)//2   #divisione INTERA
        merge_sort(a,sx,cx)
        merge_sort(a,cx,dx)
        merge(a,sx,cx,dx)
a=[3,7,4,5,2,9,8,1,0,9,0,5,2,5,6,3]
merge_sort(a,0,len(a))
print(a)


