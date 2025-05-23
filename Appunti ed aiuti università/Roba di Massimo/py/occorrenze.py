a=")-:))-"
b=")"
c="-"
d=":"
i1=0
i2=0
i3=0
i4=0

for i in range(0, len(a)):
    if a[i]==")":
        i1+=1
for i in range(0, len(a)):
    if a[i]=="-":
        i2+=1
for i in range(0, len(a)):
    if a[i]==":":
        i3+=1
print("il numero di ')' è ",i1)
print("il numero di '-' è ",i2)
print("il numero di '-' è ",i3)
print(max(i1,i2,i3))
print(min(i1,i2,i3))
