#Funcion que guarda los resultados en un txt
def guardar_resultados(NombreJug,Puntaje):
    try:    
        path = "resultados_completos.txt"
        myFile = open(path, 'a')
        myFile.write('Jugador: \n')
        myFile.write(NombreJug+'\n')
        myFile.write('Puntaje:\n')
        myFile.write(str(Puntaje)+'\n')
        myFile.write('- - - - - - - - - - - - - -'"\n")
    finally:
        myFile.close()

