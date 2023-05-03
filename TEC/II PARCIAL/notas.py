def notas(lista):
    if isinstance(lista,list):
        if escala(lista):
            return [mayor(lista,0),menor(lista,lista[0]),cantmay(lista,0),promedio(lista,0,0)]
        else:
            return "error de escala"
    else:
        return "error, no es una lista"

def escala(lista):
    if lista==[]:
        return True
    else:
        if 0<=lista[0]<=100:
            return escala(lista[1:])
        else:
            return False

def mayor(lista,result):
    if lista==[]:
        return result
    else:
        if lista[0]>result:
            return mayor(lista[1:],lista[0])
        else:
            return mayor(lista[1:],result)

def menor(lista,result):
    if lista==[]:
        return result
    else:
        if lista[0]<result:
            return menor(lista[1:],lista[0])
        else:
            return menor(lista[1:],result)

def cantmay(lista,result):
    if lista==[]:
        return result
    else:
        if lista[0]>67.5:
            return cantmay(lista[1:],result+1)
        else:
            return cantmay(lista[1:],result)

def promedio(lista,i,result):
    if i==len(lista):
        return result/(i-1)
    else:
        return promedio(lista,i+1,result+lista[i])


