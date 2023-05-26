def coordenadas(mat):
    if isinstance(mat,list) and isinstance(mat[0],list):
        tempcol=[]
        result=[]
        for fila in range(len(mat)):
            temnum=mat[fila][0]
            for col in range(len(mat[fila])):
                if mat[fila][col]<=temnum:
                    temnum=mat[fila][col]
                    tempcol=[fila,col]
            result+=[tempcol]
        return result
