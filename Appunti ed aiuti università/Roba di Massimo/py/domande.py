a=[5,4,3,2,1]
b=[(a[i],a[-1-i]) for i in range(len(a))]
c=[x+y for x,y in b]
print(sum(c))

d=[]
for i in range(5):
    d.append(i*5)
    print(d[i])