import pygame
import os
import time
import random
   
def game_scr():
    pygame.init()
    pygame.mixer.init()
    screen = pygame.display.set_mode((1280, 680))
    pygame.display.set_caption('jUEGO')
    clock = pygame.time.Clock()
    pygame.mixer.music.load("dwtd.mp3")
    pygame.mixer.music.set_volume(0.7)
    pygame.mixer.music.play()

    running = True 

    vidas=3
    enemigos_elm=0
    

    class Enemigo(pygame.sprite.Sprite):
        def __init__(self):
            super().__init__()
            self.time=0
            self.image = pygame.Surface((100, 100))
            self.image.fill("green")

            self.rect=self.image.get_rect()
            self.rect.center=(random.randrange(screen.get_width(),screen.get_width()+1500,150),random.randrange(100,screen.get_height()-100,150))
        
        def add_enemigo(self,rand):
                if rand!=0 and len(enems.sprites())<9:
                    enems.add(Enemigo())
                    self.add_enemigo(rand-1)
        
        def update(self):
            self.shoot()
            self.rect.x -=3

            if self.rect.right<=0:
                self.kill()
                if len(enems.sprites())<1:
                    rand=random.randrange(1,9,1)
                    self.add_enemigo(rand)
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
            self.rect.x -=10
            if self.rect.right>=screen.get_width():
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

            keys = pygame.key.get_pressed()
            if keys[pygame.K_w]:
                if self.rect.top>=0:
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

    sprites=pygame.sprite.Group()
    jugador=Player()
    sprites.add(jugador)
    balas=pygame.sprite.Group()
    enems=pygame.sprite.Group()
    enems.add(Enemigo())
    balase=pygame.sprite.Group()
    
    while running:
        # poll for events
        # pygame.QUIT event means the user clicked X to close your window
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        # fill the screen with a color to wipe away anything from last frame
        bg=pygame.image.load(os.path.join("space2.gif"))
        bgs=pygame.transform.scale(bg,(1280,680))
        screen.blit(bgs,(0,0))


        cej=pygame.sprite.groupcollide(sprites, enems, False,True)
        ceb=pygame.sprite.groupcollide(sprites, balase, False,True)

        colision=pygame.sprite.groupcollide(balas, enems, True,True)
        if colision or cej:
            enemigos_elm+=1
            print("eliminados",enemigos_elm)
            enemigo_elimindado(random.randrange(1,9,1))
        
        if cej or ceb:
            vidas-=1
            print("vidas",vidas)

        if vidas==0 or enemigos_elm==10:
            print("game over")
            #pause() 
        
        if vidas!=0 and enemigos_elm!=10:
            sprites.update()
            sprites.draw(screen)
            balas.update()
            balas.draw(screen)
            enems.update()
            enems.draw(screen)
            balase.draw(screen)
            balase.update()
            

        def enemigo_elimindado(randn):
            if randn!=0 and len(enems.sprites())<9:
                enems.add(Enemigo())
                enemigo_elimindado(randn-1)




        # flip() the display to put your work on screen
        pygame.display.update()

        # limits FPS to 60
        # dt is delta time in seconds sinc e last frame, used for framerate-
        # independent physics.
        clock.tick(60)
    pygame.quit()

game_scr()