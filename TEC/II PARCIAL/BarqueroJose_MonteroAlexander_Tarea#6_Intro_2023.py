'''
Problema #1

Entradas: Número entero.
Salidas: Número entero sin los dígitos repetidos (del número original) dos o más veces.
Restricciones: Únicamente se permiten números enteros positivos.

Estudiantes:
José Bernardo Barquero Bonilla.
Alexander Montero Vargas.

'''
def cambiar(num):
    if isinstance(num,int) and num>=0:
        x=contar(num,0)
        rep=cambAux(num,x,0,[],[])
        return elmAux(num,rep,0,0,0)
    else:
        return "Erorr"
    

def elmAux(num,lista,i,j,result):
    if num==0:
        return result
    else:
        if j==len(lista):
            return elmAux(num//10,lista,i+1,0,result+num%10*10**i)
        else:
            if num%10==lista[j]:
                return elmAux(num//10,lista,i+1,0,result)
            else:
                return elmAux(num,lista,i,j+1,result)

def cambAux(num,i,j,lista,result):
    if i<0:
        return result
    else:
        if lista==[]:
            return cambAux(num%10**i,i-1,0,lista+[num//10**i],result)
        elif j==len(lista):
            return cambAux(num%10**i,i-1,0,lista+[num//10**i],result)
        else:
            if num//10**i==lista[j]:
                return cambAux(num%10**i,i-1,0,lista,result+[num//10**i])
            else:
                return cambAux(num,i,j+1,lista,result)

def contar(num,i):
    if num==0:
        return i-1
    else:
        return contar(num//10,i+1)

'''
Problema #2

Entradas: Lista con números que representan las notas de los estudiantes (en escala de 100).
Salidas: Lista con la nota más alta, nota más baja, cantidad de notas mayores a 67.5 y el promedio entre todas las notas.
Restricciones: Únicamente se admiten listas que contengan números 

Estudiantes:
José Bernardo Barquero Bonilla.
Alexander Montero Vargas.

'''

def notas(lista):
    if isinstance(lista,list):
        return verificar(lista,0)
    else:
        return "Error"

def verificar(lista,i):
    if i==len(lista):
        return [aux(lista,0,[]),aux2(lista,0,[]),aux3(lista,0,0),aux4(lista,0,0)]
    elif 0<=lista[i]<=100:
        return verificar(lista,i+1)
    else:
        return "Error2"
    
def aux(lista,i,result):
    if i==len(lista):
        return result
    elif lista[i]>lista[i-1]:
        return aux(lista,i+1,lista[i])
    else:
        return aux(lista,i+1,result)

def aux2(lista,i,result):
    if i==len(lista):
        return result
    elif lista[i]<lista[i-1]:
        return aux2(lista,i+1,lista[i])
    else:
        return aux2(lista,i+1,result)

def aux3(lista,i,result):
    if i==len(lista):
        return result
    elif lista[i]>=67.5:
        return aux3(lista,i+1,result+1)
    else:
        return aux3(lista,i+1,result)

def aux4(lista,i,result):
    if i==len(lista):
        return result
    else:
        return aux4(lista,i+1,result+(lista[i]/len(lista))*100)

'''
Problema #3

Entradas: Matriz (lista con sublistas).
Salidas: Lista con sublistas anidadas, las cuales representan las coordenadas de los números más pequeños de cada columna.
Restricciones: Únicamente se admiten matrices (lista con sublistas).

Estudiantes:
José Bernardo Barquero Bonilla.
Alexander Montero Vargas.

'''

def cordenadas(matrix):
    if isinstance(matrix,list) and isinstance(matrix[0],list):
        return auxCor(matrix,0,0,[],0,[])
    else:
        return "Error"
    
def auxCor(matrix,i,j,tempCol,menor,result):
    if j==len(matrix[0]):
        return result
    else:
        if i==len(matrix):
            return auxCor(matrix,0,j+1,[],0,result+[tempCol])
        else:
            if isinstance(matrix[i][j],int):
                if i==0:
                    return auxCor(matrix,i+1,j,[i,j],matrix[i][j],result)
                elif matrix[i][j]<menor:
                    return auxCor(matrix,i+1,j,[i,j],matrix[i][j],result)
                else:
                    return auxCor(matrix,i+1,j,tempCol,menor,result)
            else:
                return "Error2"

'''
Problema #4

Entradas: Un string (cadena).
Salidas: Un string sin los caracteres repetidos presentes en el original.
Restricciones: Únicamente se admiten strings.

Estudiantes:
José Bernardo Barquero Bonilla.
Alexander Montero Vargas.

'''

def reemplazar(string):
    if isinstance(string,str):
        return aux5(string,0,"")
    else:
        return "Error"

def aux5(string,i,result):
    if i==len(string):
        return result
    elif i==0:
        return aux5(string,i+1,result+string[i])
    elif string[i-1]==string[i]:
        return aux(string,i+1,result)
    else:
        return aux(string,i+1,result+string[i])