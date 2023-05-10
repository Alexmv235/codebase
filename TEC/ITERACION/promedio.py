def promedio(lista):
    if isinstance(lista,list):
        result=0
        i=0
        while i<len(lista):
            result+=lista[i]
            i+=1
        return result/(len(lista))
    
print(promedio([1,2,3]))