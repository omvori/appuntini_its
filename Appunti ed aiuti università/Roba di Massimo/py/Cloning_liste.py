a = [81, 82, 83]
	
b = a[:]       #fare un clone con lo slicing
print(a == b)  #True perchè il clone b di a è uguale alla lista a
print(a is b)  #False perchè b non è alias di a

b[0] = 5

print(a) #[81,82,83]
print(b) #[5,82,83]
#ottenere un clone di una lista ci permette di poi modificarla senza cambiare l'originale
c=[1,2,3,4,5]
d=c[-3:5]  #l'estremo negativo non cambia l'ordine del clone
print(d)
# se il salto è negativo l'ordine si inverte