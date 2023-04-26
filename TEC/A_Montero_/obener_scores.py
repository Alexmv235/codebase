#Funcion para obtener una lista con puntajes y con nombres

def obtenerPunt():
    return auxOb(3)
def auxOb(indice):

    try:    
        path = "resultados_completos.txt"
        myFile = open(path, 'r')
        result=[int((myFile.readlines()[indice])[:-1])]
        return result+auxOb(indice+5)
    except:
        myFile.close()
        return []
    finally:
        myFile.close()

def obtenerNomb():
    x=auxNomb(1)
    return x
def auxNomb(indice):
    try:    
        path = "resultados_completos.txt"
        myFile = open(path, 'r')
        result=[(myFile.readlines()[indice])[:-1]]
        return result+auxNomb(indice+5)
    except:
        myFile.close()
        return []
    finally:
        myFile.close()
    
#Funcion que ordena las listas utlilizando el metodo de burbuja "divide y vencerás"
#https://www.geeksforgeeks.org/merge-sort/
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
