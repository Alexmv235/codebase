def bordes(lista):
    if isinstance(lista,list) and isinstance(lista[0],list):
        columnas=len(lista[0])
        esMatrix=True
        for e in lista:
            if len(e)!=columnas:
                esMatrix=False
        if esMatrix:
            result=[]
            i=0
            filas=len(lista)
            while i<filas:
                if i==0 or i==(filas-1):
                    result+=lista[i]
                else:
                    result+=[lista[i][0]]
                    result+=[lista[i][columnas-1]]
                i+=1
            return result
        else:
            return "no es una matriz"
    else:
        return "error"
    
print(bordes([
[1, 2, 3, 4],
[4, 5, 6, 4],
[7, 8, 9, 4],
[6, 2, 7, 2]
]))
                