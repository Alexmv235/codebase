
def fw(lista):
    if isinstance(lista,list):
        i=0
        while i<len(lista):
            if isinstance(lista[i],list):
                lista=lista[:i]+lista[i]+lista[i+1:]
                i=0
            i+=1
        return lista



print(fw([[1,2,3],[4,[5],6],7]))