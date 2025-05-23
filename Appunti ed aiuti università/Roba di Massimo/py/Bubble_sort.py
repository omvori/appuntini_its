def bubble_sort( a ): # input una sequenza di numeri a [n,m,k...] 
    n=len(a)          # elementi ordinati dal più piccolo al più grande 
    for c in range(n-1):
        for i in range(n-1):  #scorrere la lista una sola volta non basta, serve O(n^2)
            if a[i]>a[i+1]:
                a[i], a[i+1] = a[i+1], a[i]
x = [8, 2, 9, 1, 7, 3, 4, 10, 5, 6, 21]
bubble_sort(x)
print(x)  
