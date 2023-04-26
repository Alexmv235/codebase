#Proyecto Taller de Progra- CE1102
#Elaborado por:
#Alexander Montero Vargas
#Carne: 2023166058

import pydoc
import sys
import pygame
import random
import os
import time
from tkinter import *
from scores import guardar_resultados
from obener_scores import ordenar_lista, obtenerPunt, obtenerNomb

# pygame setup

#Pantalla de inicio
def mainscr():
    class Ventana_Principal:
    
    #Funcion con los elementos visuales de la pantalla principal
        def __init__(self,master): #https://www.geeksforgeeks.org/how-to-use-images-as-backgrounds-in-tkinter/
            self.v= IntVar()
            self.bgcolor=''
            self.elcolor=''
            self.print=False

            self.bg = PhotoImage(file="space2.gif").zoom(4, 4)
            self.canvas = Canvas(master, width=1280,
                             height=715)
            self.canvas.pack(fill="both", expand=True)

            self.canvas.create_image(0, 0, image=self.bg,
                                 anchor="nw")
            self.canvas.create_text(600, 50, text="Space Game",font=(
                "Times New Roman", 36),fill="white")
            self.canvas.create_text(600, 100, text="Por jugar dijite un nombre",font=(
                "Times New Roman", 22),fill="white")
            
            self.entrada_nombre = Entry(self.canvas)
            self.entrada_nombre.place(x=400, y=140, width=400, height=32)

            self.canvas.create_text(600, 210, text="Seleccione una dificultad",font=(
                "Times New Roman", 20),fill="white")
            
            self.radio1 = Radiobutton(master, variable=self.v, value=1, text="Dificultad 1")
            self.radio1_canvas = self.canvas.create_window( 450, 240, anchor = "nw",
                                                window = self.radio1)
            self.radio2 = Radiobutton(master, variable=self.v, value=2, text="Dificultad 2")
            self.radio2_canvas = self.canvas.create_window( 550, 240, anchor = "nw",
                                                window = self.radio2)
            self.radio3 = Radiobutton(master, variable=self.v, value=3, text="Dificultad 3")
            self.radio3_canvas = self.canvas.create_window( 650, 240, anchor = "nw",
                                                window = self.radio3)
            
            #El boton 1 es seleccionado por defecto, por lo que no hace falta verifiar si se seleccionó una dificultad
            self.radio1.select()
            
            self.button_Jugar = Button(self.canvas, text="Jugar", command= self.pass_data, bg= "white")
            self.button_Jugar.place(x=525, y=320, width=150, height=30)
            self.button_Mejores = Button(self.canvas, text="Mejores Puntajes", command= self.pshow, bg= "white")
            self.button_Mejores.place(x=525, y=360, width=150, height=30)
            self.button_Acerca = Button(self.canvas, text="Acerca del Juego", command= self.acercaShow, bg= "white")
            self.button_Acerca.place(x=525, y=400, width=150, height=30)
            self.button_Salir = Button(self.canvas, text="Salir", command= self.salir, bg= "white")
            self.button_Salir.place(x=525, y=440, width=150, height=30)

            self.label_Error = Label(self.canvas, text="", font= ("Cascadia Code",12),fg="#B3261E")
            self.label_Error.place(x=800, y=140,height=32)

        #Funcion que al presionar el boton jugar, obtiene los valores de las funciones y las envia a la pantalla de juego (pygame)
        def pass_data(self):
            nomb=self.entrada_nombre.get()
            ranges=self.v.get()
            #Verificador que el nombre no es vacio y que hay una dificultad
            if nomb != '':
                if ranges !=None and ranges!=0:
                    Window.destroy()
                    game_scr(nomb,ranges)
                else:
                    self.label_Error['text']='Seleccione un rango'
            else:
                self.label_Error['text']='Ingrese un nombre'
        #Funcion de los botones
        def pshow(self):
            Window.destroy()
            bestscores()

        def acercaShow(self):
            Window.destroy()
            acercade()
        def salir(self):
            Window.destroy()
    
    #Propiedades de la ventana
    Window=Tk()
    ventana_principal=Ventana_Principal(Window)
    Window.title("Main - Space Game")
    Window.minsize(500,300)
    Window.resizable(False,False)
    Window.mainloop()

#Pantalla de mejores puntuaciones
def bestscores():
    class Best7:
        def __init__(self, master): #https://www.geeksforgeeks.org/how-to-use-images-as-backgrounds-in-tkinter/

            self.puntajes, self.nombres = ordenar_lista(obtenerPunt(), obtenerNomb())

            self.bg = PhotoImage(file="space2.gif").zoom(4, 4)

            self.canvas = Canvas(master, width=1280,
                             height=715)

            self.canvas.pack(fill="both", expand=True)

            self.canvas.create_image(0, 0, image=self.bg,
                                 anchor="nw")

            self.canvas.create_text(400, 15, text="Los Mejores Puntajes",font=(
                "Times New Roman", 24),fill="white")
            self.canvas.create_text(150, 50, text="Posicion:",font=(
                "Times New Roman", 16),fill="white")
            self.canvas.create_text(250, 50, text="Nombre:",font=(
                "Times New Roman", 16),fill="white")
            self.canvas.create_text(640, 50, text="Puntaje:",font=(
                "Times New Roman", 16),fill="white")
            
            self.button_Jugar = Button(self.canvas, text="Volver al menu", command= self.back, bg= "white")
            self.button_Jugar.place(x=900, y=50, width=150, height=30)
           
            self.showResults()
        def back(self):
            Window.destroy()
            mainscr()

        def showResults(self):
            return self.auxShw(self.puntajes, self.nombres, 80, 0)

        def auxShw(self, puntajes, nombres, posy, i):
            if puntajes != [] and i < 7 and i < len(puntajes):
                self.canvas.create_text(150, posy, text=str(i+1),font=(
                "Times New Roman", 16),fill="white")
                self.canvas.create_text(250, posy, text=nombres[i],font=(
                    "Times New Roman", 16),fill="white")
                self.canvas.create_text(640, posy, text=puntajes[i],font=(
                    "Times New Roman", 16),fill="white")

                self.auxShw(puntajes, nombres, posy+30, i+1)
    #Propiedades de la ventana
    Window=Tk()
    ventana_principal=Best7(Window)
    Window.title("Mejores Puntajes - Space Game")
    Window.minsize(500,300)
    Window.resizable(False,False)
    Window.mainloop()

def acercade():
    class Acrca: #https://www.geeksforgeeks.org/how-to-use-images-as-backgrounds-in-tkinter/
    
    #Funcion con los elementos visuales de la pantalla principal
        def __init__(self,master):
            self.v= IntVar()
            self.bgcolor=''
            self.elcolor=''
            self.print=False

            self.bg = PhotoImage(file="space2.gif").zoom(4, 4)
            self.canvas = Canvas(master, width=1280,
                             height=715)
            self.canvas.pack(fill="both", expand=True)

            self.canvas.create_image(0, 0, image=self.bg,
                                 anchor="nw")
            self.canvas.create_text(600, 50, text="Space Game",font=(
                "Times New Roman", 36),fill="white")
            
            self.canvas.create_text(200, 100, text="Juego elaborado por:",font=(
                "Times New Roman", 22),fill="white")
            self.canvas.create_text(200, 150, text="Alexander Montero Vargas",font=(
                "Times New Roman", 22),fill="white")
            self.canvas.create_text(200, 200, text="Carné:2023166058",font=(
                "Times New Roman", 22),fill="white")
            self.canvas.create_text(800, 100, text="Instituto Tecnologico de Costa Rica",font=(
                "Times New Roman", 22),fill="white")
            self.canvas.create_text(800, 150, text="Taller de Programación (CE1102)",font=(
                "Times New Roman", 22),fill="white")
            self.canvas.create_text(800, 200, text="Ingeniería en Computadores",font=(
                "Times New Roman", 22),fill="white")
            self.canvas.create_text(800, 250, text="Año 2023",font=(
                "Times New Roman", 22),fill="white")
            self.canvas.create_text(800, 300, text="Profesor: Luis Barboza",font=(
                "Times New Roman", 22),fill="white")
            self.canvas.create_text(800, 350, text="Costa Rica",font=(
                "Times New Roman", 22),fill="white")
            self.canvas.create_text(800, 400, text="Version: 0.1.1 beta",font=(
                "Times New Roman", 22),fill="white")
            
            self.autor = PhotoImage(file="autor.png").subsample(10,10)
            self.label_logo = Label(self.canvas, image=self.autor)
            self.label_logo.place(x=100,y=300)

            self.button_Jugar = Button(self.canvas, text="Volver al menu", command= self.back, bg= "white")
            self.button_Jugar.place(x=900, y=500, width=150, height=30)
       
        def back(self):
            Window.destroy()
            mainscr()
            
    
    #Propiedades de la ventana
    Window=Tk()
    ventana_principal=Acrca(Window)
    Window.title("Acerca de - Space Game")
    Window.minsize(500,300)
    Window.resizable(False,False)
    Window.mainloop()
        
def game_scr(nomb,rang): #https://www.pygame.org/docs/
    #Inicialización de variables de juego
    pygame.init()
    pygame.mixer.init()

    pname=nomb
    screen = pygame.display.set_mode((1280, 680))
    pygame.display.set_caption('jUEGO')
    clock = pygame.time.Clock()
    pygame.mixer.music.load("spci.mp3")
    pygame.mixer.music.set_volume(0.7)
    pygame.mixer.music.play(-1)

    running = True 
    tiempo_enemigo=0

    puntaje=0
    dificulty=rang
    vidas=3
    enemigos_elm=0
    gover=False
    
    if dificulty ==1:
        objetivo=10
        tiempo_enem=2.8
    elif dificulty ==2:
        tiempo_enem=2.2
        objetivo=20
    else:
        tiempo_enem=1.6
        objetivo=10

    
    #Clases de objetos y sus propiedades
    class Enemigo(pygame.sprite.Sprite):
        def __init__(self):
            super().__init__()
            self.time=0
            self.image = self.image=pygame.transform.scale(pygame.image.load(os.path.join("ovni.png")),(75,75))

            self.rect=self.image.get_rect()
            self.rect.center=(random.randrange(screen.get_width(),screen.get_width()+301,150),random.randrange(150,screen.get_height()-100,30))
        
        def update(self):
            if not gover:
                self.shoot()
                if dificulty==1:
                    self.rect.x -=2
                elif dificulty==2:
                    self.rect.x -=4
                else:
                    self.rect.x -=6

                if self.rect.right<=0:
                    self.kill()
        
        def shoot(self):
            if (time.time()-self.time)>tiempo_enem-0.2: #and len(balas.sprites())<3
                self.time=time.time()
                balase.add(Bala_Enemigas(self.rect.left,self.rect.centery))

    class Bala_Enemigas(pygame.sprite.Sprite):
        def __init__(self,pox,poy):
            super().__init__()
            self.image = pygame.Surface((26, 10))
            self.image.fill("blue")

            self.rect=self.image.get_rect()
            self.rect.center=(pox,poy)
            
        def update(self):
            if not gover:
                if dificulty==1:
                    self.rect.x -=10
                elif dificulty==2:
                    self.rect.x-=13
                else:
                    self.rect.x -=16
                if self.rect.right>=screen.get_width():
                    self.kill()
            else:
                self.kill()
            
    class Bala(pygame.sprite.Sprite):
        def __init__(self,pox,poy):
            super().__init__()
            self.image = pygame.Surface((26, 10))
            self.image.fill("red")

            self.rect=self.image.get_rect()
            self.rect.center=(pox,poy)
            
        def update(self):
            
            self.rect.x +=10
            if self.rect.right>=screen.get_width():
                self.kill()
    
    
    class Player(pygame.sprite.Sprite):
        def __init__(self):
            super().__init__()
            self.time=0
            self.image=pygame.transform.scale(pygame.image.load(os.path.join("space-ship.png")),(75,75))

            self.rect=self.image.get_rect()
            self.rect.center=(screen.get_width()//14,screen.get_height()//2)

        def update(self):
            if not gover:
                keys = pygame.key.get_pressed()
                if keys[pygame.K_w]:
                    if self.rect.top>=100:
                        self.rect.y -=4
                if keys[pygame.K_s]:
                    if self.rect.bottom<=screen.get_height():
                        self.rect.y +=4
                if keys[pygame.K_a]:
                    if self.rect.left>=0:
                        self.rect.x -=4
                if keys[pygame.K_d]:
                    if self.rect.right<=screen.get_width():
                        self.rect.x +=4
                keys = pygame.key.get_pressed()
                if keys[pygame.K_SPACE]:
                    self.shoot()
        
        def shoot(self):
            if (time.time()-self.time)>tiempo_enem-1: #and len(balas.sprites())<3
                self.time=time.time()
                balas.add(Bala(self.rect.right,self.rect.centery))
    
    #Sprites https://www.programacionfacil.org/cursos/pygame/capitulo_7_creacion_sprites.html
    sprites=pygame.sprite.Group()
    jugador=Player()
    sprites.add(jugador)
    balas=pygame.sprite.Group()
    enems=pygame.sprite.Group()
    balase=pygame.sprite.Group()
    
    #Ciclo while propio de pygame para su ejecución
    while running:
        # pygame.QUIT event means the user clicked X to close your window
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                sys.exit()

        #Propiedades generales de pantalla pygame
        bg=pygame.image.load(os.path.join("space2.gif"))
        bgs=pygame.transform.scale(bg,(1280,680))
        screen.blit(bgs,(0,00))
        
        #Barra de estado
        font = pygame.font.SysFont("comicsans", 30, True)
        score= font.render("Score: " + str(puntaje), 1, (254,254,254))
        screen.blit(score, (390, 10))

        name= font.render("Jugador: " + str(pname), 1, (254,254,254))
        screen.blit(name, (20, 10))
        vida= font.render("Vidas: " + str(vidas), 1, (254,254,254))
        screen.blit(vida, (20, 50))

        lev= font.render("Dificultad: " + str(dificulty), 1, (254,254,254))
        screen.blit(lev, (600, 10))

        elm= font.render("Enemigos Eliminados: " + str(enemigos_elm) +" / " + str(objetivo), 1, (254,254,254))
        screen.blit(elm, (600, 50))

        enemigos_en_pantalla= font.render("Enemigos en pantalla: " + str(len(enems.sprites())), 1, (254,254,254))
        screen.blit(enemigos_en_pantalla, (800, 10))

                           

        #Gestion de colisiones
        cej=pygame.sprite.groupcollide(sprites, enems, False,True)
        ceb=pygame.sprite.groupcollide(sprites, balase, False,True)

        balascol=pygame.sprite.groupcollide(balas, balase, True,True)
        if balascol:
            puntaje+=50

        colision=pygame.sprite.groupcollide(balas, enems, True,True)
        if colision or cej:
            enemigos_elm+=1
            puntaje=puntaje+10*(10-len(enems.sprites()))**dificulty
            print(puntaje)
            print("eliminados",enemigos_elm)
            #enemigo_elimindado(random.randrange(1,9,1))s
        
        if cej or ceb:
            puntaje-=100
            vidas-=1
            print("vidas",vidas)

        if vidas==0:
            if not gover:
                gover=True
                pygame.display.quit()
                pygame.mixer.music.stop()
                pygame.mixer.quit()
                perdiste(pname,puntaje,dificulty)
                pygame.quit()
                break
        
        if enemigos_elm==objetivo:
            gover=True
            guardar_resultados(pname,puntaje)
            running=False
            pygame.display.quit()
            ganaste(pname,puntaje,dificulty)
            pygame.quit()
            break

        #Actualizacion de pantalla
        sprites.update()
        sprites.draw(screen)
        balas.update()
        balas.draw(screen)
        enems.update()
        enems.draw(screen)
        balase.draw(screen)
        balase.update()


        #Añadir enemigos
        def add_enemigo(randn):
            #global tiempo_enemigo
            if randn!=0 and len(enems.sprites())<9:
                enems.add(Enemigo())
                add_enemigo(randn-1)
                
    
        if time.time()-tiempo_enemigo>tiempo_enem:
            if dificulty !=2:
                tiempo_enemigo=time.time()+0
                add_enemigo(1)
            else:
                tiempo_enemigo=time.time()+0
                add_enemigo(random.randrange(1,3))

        # flip() the display to put your work on screen
        pygame.display.update()

        # limits FPS to 60
        # dt is delta time in seconds sinc e last frame, used for framerate-
        # independent physics.
        clock.tick(60)
    pygame.quit()



# Funcion que muestra que ganó
def ganaste(Nombre,puntaje,dificultad):
    class YouWIn:
        def __init__(self, master): #https://www.geeksforgeeks.org/how-to-use-images-as-backgrounds-in-tkinter/

            self.puntajes, self.nombres = ordenar_lista(obtenerPunt(), obtenerNomb())

            self.bg = PhotoImage(file="space2.gif").zoom(4, 4)

            # Create Canvas
            self.canvas = Canvas(master, width=1280,
                             height=715)

            self.canvas.pack(fill="both", expand=True)

            # Display image
            self.canvas.create_image(0, 0, image=self.bg,
                                 anchor="nw")

            # Add Text
            self.canvas.create_text(600,100, text="Ganaste",font=(
                "Times New Roman", 33),fill="white")
            
            self.button_Jugar = Button(self.canvas, text="Volver al menu", command= self.back, bg= "white")
            self.button_Jugar.place(x=300, y=500, width=150, height=30)
            self.button_Jugar = Button(self.canvas, text="Siguiente Nivel", command= self.continu, bg= "white")
            self.button_Jugar.place(x=700, y=500, width=150, height=30)
           
            self.showResults()
        
        #Funciones de botones y resultados (puntajes)
        def continu(self):
            if dificultad!=3:
                Window.destroy()
                game_scr(Nombre,dificultad+1)
            else:
                Window.destroy()
                game_scr(Nombre,dificultad)
        
        def back(self):
            Window.destroy()
            mainscr()

        def showResults(self):
            return self.auxShw(self.puntajes, self.nombres, 0)

        def auxShw(self, puntajes, nombres, i):
            if puntajes != [] and i < 7 and i < len(puntajes):
                if puntajes[i]== puntaje and nombres[i]==Nombre:
                    self.canvas.create_text(550, 200, text="Has obtenido un nuevo puntaje",font=(
                    "Times New Roman", 30),fill="white")
                    self.canvas.create_text(550, 250, text="Posición :"+str(i+1),font=(
                        "Times New Roman", 16),fill="white")
                    self.canvas.create_text(550, 300, text="Puntos: "+ str(puntajes[i]),font=(
                        "Times New Roman", 16),fill="white")
                self.auxShw(puntajes, nombres, i+1)
    #Propiedades de la ventana
    Window=Tk()
    ventana_principal=YouWIn(Window)
    Window.title("Mejores Puntajes - Space Game")
    Window.minsize(500,300)
    Window.resizable(False,False)
    Window.mainloop()

#Funcion que muestra que perdió
def perdiste(Nombre,puntaje,dificultad):
    class YouLose:
        def __init__(self, master): #https://www.geeksforgeeks.org/how-to-use-images-as-backgrounds-in-tkinter/

            self.bg = PhotoImage(file="space2.gif").zoom(4, 4)

            # Create Canvas
            self.canvas = Canvas(master, width=1280,
                             height=715)

            self.canvas.pack(fill="both", expand=True)

            # Display image
            self.canvas.create_image(0, 0, image=self.bg,
                                 anchor="nw")

            # Add Text
            self.canvas.create_text(600,100, text="Perdiste",font=(
                "Times New Roman", 33),fill="white")
            
            self.button_Jugar = Button(self.canvas, text="Volver al menu", command= self.back, bg= "white")
            self.button_Jugar.place(x=300, y=500, width=150, height=30)
            self.button_Jugar = Button(self.canvas, text="Volver a jugar", command= self.continu, bg= "white")
            self.button_Jugar.place(x=700, y=500, width=150, height=30)
           
        #Funciones de botones
        def continu(self):
            Window.destroy()
            game_scr(Nombre,dificultad)
                
        
        def back(self):
            Window.destroy()
            mainscr()

    #Propiedades de la ventana
    Window=Tk()
    ventana_principal=YouLose(Window)
    Window.title("Mejores Puntajes - Space Game")
    Window.minsize(500,300)
    Window.resizable(False,False)
    Window.mainloop()

#Ejecutar funcion para mostrar pantalla principal
mainscr()