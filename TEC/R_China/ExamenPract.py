#Repetidos

def repetido(lista,num):
    if isinstance(lista,list):
        return flat(lista,lista,[])

def flat(lista,listaaux,result):
    if lista==[]:
        return result
    else:
        if isinstance(lista[0],list):
            print("lista encontrada")
            if listaaux==[]:
                return flat(lista[1:],lista[1:],result)
            else:
                return flat(lista,listaaux[:1],result[0][0])
        else:
            return flat(lista[1:],lista[1:],result+[lista[0]])   


#print(repetido([0,1,[2,[3],4],0,2],0))

def col_mayor(matrix):
    if isinstance(matrix,list) and isinstance(matrix[0],list):
        return aux(matrix,0,0,0,0,1)

def aux(matrix,svmax,imax,i,j,result):
    if j==len(matrix[0]):
        return (maxT(matrix,imax,0,[]),svmax)
    else:
        if i==len(matrix):
            if result>svmax:
                return aux(matrix,result,j,0,j+1,1)
            else:
                return aux(matrix,svmax,imax,0,j+1,1)
        else:
            return aux(matrix,svmax,imax,i+1,j,result*matrix[i][j])

def maxT(matrix,jmax,i,result):
    if i==len(matrix):
            return result
    else:
            return maxT(matrix,jmax,i+1,result+[matrix[i][jmax]]) 

print(col_mayor([[1,2,3],[4,5,6],[7,8,9],[10,11,12]]))