def buscar(lista,num):
    if isinstance(lista,list) and isinstance(num,int):
        count=0
        i=0
        while i<len(lista):
            if isinstance(lista[i],list):
                lista=lista[:i]+lista[i]+lista[i+1:]
                i=0
            i+=1
        for e in lista:
            if e==num:
                count+=1
        return count
    else:
        return "error"
    

print(buscar([[2,2,3],[2,[5],2],7],2))
