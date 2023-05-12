# aplanar lista anidada

lista = [ [1,[2], 3], 4, 5, [6, 7], 8, 9]

lista_plana = []


#se puede usar cualquiera de las dos funciones, isinstance o type

for l in lista:
	if isinstance(l, int):
		lista_plana.append(l)
	elif type(l) == list:
		for i in l:
			lista_plana.append(i)

print(lista_plana)