# Example file showing a circle moving on screen
import sys
import pygame
import random
import os
import time
from tkinter import *

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
            self.lab_radio1 = Label(self.canvas, text="0-100",bg=self.bgcolor,fg=self.elcolor)
            self.lab_radio1.place(x=275, y=120)
            

            self.radio2 = Radiobutton(self.canvas,variable=self.v, value=2, bg=self.bgcolor)
            self.radio2.place(x=350, y=120)
            self.lab_radio1 = Label(self.canvas, text="0-1000",bg=self.bgcolor,fg=self.elcolor)
            self.lab_radio1.place(x=375, y=120)

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
    teeemp=0

    puntaje=0
    dificulty=rang
    vidas=3
    enemigos_elm=0
    gover=False
    

    class Enemigo(pygame.sprite.Sprite):
        def __init__(self):
            super().__init__()
            self.time=0
            self.image = pygame.Surface((100, 100))
            self.image.fill("green")

            self.rect=self.image.get_rect()
            self.rect.center=(random.randrange(screen.get_width(),screen.get_width()+1500,1),random.randrange(150,screen.get_height()-100,150))
        
        def update(self):
            if not gover:
                self.shoot()
                self.rect.x -=1

                if self.rect.right<=0:
                    self.kill()
        
        def shoot(self):
            if (time.time()-self.time)>3: #and len(balas.sprites())<3
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
                self.rect.x -=10
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
            self.image=pygame.transform.scale(pygame.image.load(os.path.join("space-ship.png")),(100,100))

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
            if (time.time()-self.time)>0.15: #and len(balas.sprites())<3
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
    
    class Information(pygame.sprite.Sprite):
        def __init__(self):
            super().__init__()
            self.image = pygame.Surface((screen.get_width()//4,100))
            self.image.fill("orange")

            self.rect=self.image.get_rect()
            self.rect.center=(screen.get_width()//2,50)


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
    informacion.add(Information())
    
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

        if vidas==0 or enemigos_elm==10:
            if not gover:
                print(puntaje)
                pygame.mixer.music.stop()
                pygame.mixer.quit()
                running=False
                menu()
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


        def  add_enemigo_time():
            if len(enems.sprites())<9:
                enems.add(Enemigo())
                
        
        if time.time()-tiempo_enemigo>3:
            tiempo_enemigo=time.time()
            if dificulty==1:
                add_enemigo(1)
            else:
                add_enemigo(random.randrange(1,9,1))

        # flip() the display to put your work on screen
        pygame.display.update()

        # limits FPS to 60
        # dt is delta time in seconds sinc e last frame, used for framerate-
        # independent physics.
        clock.tick(60)
    pygame.quit()

mainscr()
