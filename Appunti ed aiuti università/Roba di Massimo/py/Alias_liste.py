a = [81, 82, 83]
b = [81, 82, 83]

print(a == b) # true
print(a is b) # false in quanto b non è alias di a

b = a         # adesso b è alias di a
print(a == b) # true
print(a is b) # true

b[0] = 5
print(a) #[5,82,83]
# Dal momento in cui la lista ha nomi diversi, a e b, essi vengono chiamati alias. 
# I cambiamneti fatti con un alias hanno effetto anche sull'altro
print(a[1:-1]) #esclude primo e ultimo