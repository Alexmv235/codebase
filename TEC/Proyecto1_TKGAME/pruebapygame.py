# Example file showing a circle moving on screen
import sys
import pygame
import random
import os
import time
from tkinter import *
from scores import guardar_resultados
from obener_scores import ordenar_lista, obtenerPunt, obtenerNomb

# pygame setup


def mainscr():
    class Ventana_Principal:
    
    #Funcion con los elementos visuales de la pantalla principal
        def __init__(self,master,theme):
            self.v= IntVar()
            self.theme= theme
            self.bgcolor=''
            self.elcolor=''
            self.print=False
            self.themecolors()

            
            self.canvas = Canvas(master,width=500,height=300,highlightthickness=0,relief='ridge',background=self.bgcolor)
            self.canvas.place(x=0,y=0)

            self.label_bienv = Label(self.canvas, text="!Juego de adivinanza!", font= ("Cascadia Code",25),bg=self.bgcolor,fg=self.elcolor)
            self.label_bienv.place(x=80, y=10)

            self.label_Nom = Label(self.canvas, text="Por favor digite su nombre: ", font= ("Cascadia Code",10),bg=self.bgcolor,fg=self.elcolor)
            self.label_Nom.place(x=30, y=70)

            self.lab_select = Label(self.canvas, text="Seleccione un rango para jugar: ", font= ("Cascadia Code",9),bg=self.bgcolor,fg=self.elcolor)
            self.lab_select.place(x=25, y=120)

            self.entrada_nombre = Entry(self.canvas)
            self.entrada_nombre.place(x=250, y=67, width=150, height=32)

            self.radio1 = Radiobutton(self.canvas, variable=self.v, value=1, bg=self.bgcolor)
            self.radio1.place(x=250, y=120)
            
            #El boton 1 es seleccionado por defecto, por lo que no hace falta verifiar si se seleccionó un rango
            self.radio1.select()
            self.lab_radio1 = Label(self.canvas, text="1",bg=self.bgcolor,fg=self.elcolor)
            self.lab_radio1.place(x=275, y=120)
            

            self.radio2 = Radiobutton(self.canvas,variable=self.v, value=2, bg=self.bgcolor)
            self.radio2.place(x=350, y=120)
            self.lab_radio2 = Label(self.canvas, text="2",bg=self.bgcolor,fg=self.elcolor)
            self.lab_radio2.place(x=375, y=120)
            
            self.radio3 = Radiobutton(self.canvas,variable=self.v, value=3, bg=self.bgcolor)
            self.radio3.place(x=350, y=150)
            self.lab_radio3 = Label(self.canvas, text="3",bg=self.bgcolor,fg=self.elcolor)
            self.lab_radio3.place(x=375, y=150)

            self.button_mostrar = Button(self.canvas, text="Jugar", command= self.pass_data, bg= "white")
            self.button_mostrar.place(x=170, y=160, width=150, height=30)

            self.label_Error = Label(self.canvas, text="", font= ("Cascadia Code",12),fg="#B3261E", bg=self.bgcolor)
            self.label_Error.place(x=150, y=200)

            #Adicional: Un boton para elegir si imprimir en consola el numero generado random, con fines de revision rapida
            self.print_button= Button(self.canvas, text="(dev)Imprimir en consola: "+str(self.print),font= ("Cascadia Code",10), bg='#ba1a1a', fg='white', command=self.print_fun)
            self.print_button.place(x=200, y=250, width=260, height=30)

            #Adicional, un boton que llama a una funcion para cambiar el tema del app
            self.theme_button= Button(self.canvas, text="Cambiar tema", bg=self.elcolor, fg=self.bgcolor, command=self.cambiar_tem)
            self.theme_button.place(x=15, y=250, width=150, height=30)
        
        #Funcion que define si se deve o no imprimir en consola el numero generado
        def print_fun(self):
            if self.print==False:
                self.print=True
                self.print_button['text']="(dev)Imprimir en consola: "+str(self.print)
                self.print_button['bg']='#386664'
            else:
                self.print=False
                self.print_button['text']="(dev)Imprimir en consola: "+str(self.print)
                self.print_button['bg']='#ba1a1a'
        
        #Funcion para cammbiar el color del tema
        def cambiar_tem(self):
            if self.theme=='#FFFBFE':
                Ventana_Principal(Window,'#1C1B1F')
            else:
                Ventana_Principal(Window,'#FFFBFE')

        #Funcion que establece los valores de los colores para los elementos
        def themecolors(self):
            if self.theme=='#FFFBFE':
                self.bgcolor='#FFFBFE'
                self.elcolor='#1C1B1F'
            else:
                self.bgcolor='#1C1B1F'
                self.elcolor='#E6E1E5'
        #Funcion que al presionar el boton jugar, obtiene los valores de las funciones y las envia a la seguda pantalla
        def pass_data(self):
            nomb=self.entrada_nombre.get()
            ranges=self.v.get()
            #Verificador que el nombre no es vacio y que hay un rango seleccionado
            if nomb != '':
                if ranges !=None and ranges!=0:
                    Window.destroy()
                    game_scr(nomb,ranges)
                else:
                    self.label_Error['text']='Seleccione un rango'
            else:
                self.label_Error['text']='Ingrese un nombre'
    
    class Best7:
        def __init__(self, master, puntajes, nombres):

            self.puntajes = puntajes
            self.nombres = nombres

            self.bg = PhotoImage(file="space2.gif").zoom(4, 4)

            # Create Canvas
            self.canvas = Canvas(master, width=1280,
                             height=715)

            self.canvas.pack(fill="both", expand=True)

            # Display image
            self.canvas.create_image(0, 0, image=self.bg,
                                 anchor="nw")

            # Add Text
            self.canvas.create_text(400, 15, text="Los Mejores Puntajes",font=(
                "Times New Roman", 24),fill="white")
            self.canvas.create_text(150, 50, text="Posicion",font=(
                "Times New Roman", 16),fill="white")
            self.canvas.create_text(250, 50, text="Nombre",font=(
                "Times New Roman", 16),fill="white")
            self.canvas.create_text(640, 50, text="Puntaje",font=(
                "Times New Roman", 16),fill="white")
           
            self.showResults()

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

    puntajes, nombres = ordenar_lista(obtenerPunt(), obtenerNomb())
    #Propiedades de la ventana
    Window=Tk()
    ventana_principal=Ventana_Principal(Window,'#FFFBFE')
    Window.title("Adivinanzas - Alex TK")
    Window.minsize(500,300)
    Window.resizable(False,False)
    Window.mainloop()

def menu():
        pygame.init()
        screen = pygame.display.set_mode((1280, 715))
        pygame.display.set_caption('Alex pygame')
        clock = pygame.time.Clock()
        running = True
        
        while running:
            # poll for events
            # pygame.QUIT event means the user clicked X to close your window
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                    #pygame.quit()
                    sys.exit()

            # fill the screen with a color to wipe away anything from last frame
            screen.fill("blue")

            keys = pygame.key.get_pressed()
            if keys[pygame.K_COMMA]:
                running=False
                game_scr()

            # flip() the display to put your work on screen
            pygame.display.update()

            # limits FPS to 60
            # dt is delta time in seconds since last frame, used for framerate-
            # independent physics.
            dt = clock.tick(60) / 1000
        pygame.quit()
        
def game_scr(nomb,rang):
    pygame.init()
    pygame.mixer.init()

    pname=nomb
    screen = pygame.display.set_mode((1280, 680))
    pygame.display.set_caption('jUEGO')
    clock = pygame.time.Clock()
    pygame.mixer.music.load("dwtd.mp3")
    pygame.mixer.music.set_volume(0.7)
    #pygame.mixer.music.play()

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

    

    class Enemigo(pygame.sprite.Sprite):
        def __init__(self):
            super().__init__()
            self.time=0
            self.image = pygame.Surface((75, 75))
            self.image.fill("green")

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

    class GameOver(pygame.sprite.Sprite):
        def __init__(self):
            super().__init__()
            self.image = pygame.Surface((700, 400))
            self.image.fill("orange")

            self.rect=self.image.get_rect()
            self.rect.center=(screen.get_width()//2,screen.get_height()//2)
            
        def update(self):
            keys = pygame.key.get_pressed()
            if keys[pygame.K_COMMA]:
                GameOver.kill()
    
    sprites=pygame.sprite.Group()
    jugador=Player()
    sprites.add(jugador)
    balas=pygame.sprite.Group()
    enems=pygame.sprite.Group()
    #enems.add(Enemigo())
    balase=pygame.sprite.Group()
    goscreen=pygame.sprite.Group()
    game_st=pygame.sprite.Group()
    informacion=pygame.sprite.Group()
    
    while running:
        # poll for events
        # pygame.QUIT event means the user clicked X to close your window
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                #pygame.quit()
                sys.exit()

        # fill the screen with a color to wipe away anything from last frame
        bg=pygame.image.load(os.path.join("space2.gif"))
        bgs=pygame.transform.scale(bg,(1280,680))
        screen.blit(bgs,(0,00))
        
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

        if vidas==0 or enemigos_elm==objetivo:
            if not gover:
                gover=True
                print(puntaje)
                guardar_resultados(pname,puntaje)
                #pygame.mixer.music.stop()
                #pygame.mixer.quit()
                #srunning=False
                #menu()
                '''print("game over")
                goscreen.add(GameOver())
                gover=True'''

        goscreen.draw(screen)
        goscreen.update()
        sprites.update()
        sprites.draw(screen)
        balas.update()
        balas.draw(screen)
        enems.update()
        enems.draw(screen)
        balase.draw(screen)
        balase.update()


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

mainscr()
