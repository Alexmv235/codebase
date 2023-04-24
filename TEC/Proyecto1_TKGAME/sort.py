def unir(izqPunt, derPunt, izqNomb, derNomb):
    if not izqPunt:
        return derPunt, derNomb
    if not derPunt:
        return izqPunt, izqNomb
    if izqPunt[0] >= derPunt[0]:
        puntajeU, nombreU = unir(izqPunt[1:], derPunt, izqNomb[1:], derNomb)
        return [izqPunt[0]] + puntajeU, [izqNomb[0]] + nombreU
    else:
        puntajeU, nombreU = unir(izqPunt, derPunt[1:], izqNomb, derNomb[1:])
        return [derPunt[0]] + puntajeU, [derNomb[0]] + nombreU

def ordenar_lista(listaPunt, listaNomb):
    if len(listaPunt) <= 1:
        return listaPunt, listaNomb
    mid = len(listaPunt) // 2
    izqPunt = listaPunt[:mid]
    derPunt = listaPunt[mid:]
    izqNomb = listaNomb[:mid]
    derNomb = listaNomb[mid:]
    izqPunt, izqNomb = ordenar_lista(izqPunt, izqNomb)
    derPunt, derNomb = ordenar_lista(derPunt, derNomb)
    return unir(izqPunt, derPunt, izqNomb, derNomb)

# Ejemplo de uso
num_lst = [1, 6, 3, 4, 2, 4, 5, 8]
text_lst = ['uno', 'seis', 'tres', 'cuatro', 'dos', 'cuatro', 'cinco', 'ocho']
print(ordenar_lista(num_lst, text_lst)) 
