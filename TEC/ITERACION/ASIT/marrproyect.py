Dic={'forestales':40,'agronegocios':30}

def disminuyaMatricula():
    nombre=input("Escriba el nombre de la carrera")
    cantidad=int(input("Escriba la cantidad de personas"))
    if nombre in Dic:
        if Dic[nombre]>=cantidad:
            Dic[nombre]-=cantidad
            print('se actualizó en ', cantidad, 'estudiantes')
        else:
            print("Negativos")
    else:
        print('no exite carrera')


            