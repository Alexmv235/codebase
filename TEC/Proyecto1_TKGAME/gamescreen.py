import pygame
import os
import time


pygame.init()
pygame.mixer.init()
screen = pygame.display.set_mode((1280, 680))
pygame.display.set_caption('jUEGO')
clock = pygame.time.Clock()
player_pos = pygame.Vector2(screen.get_width() / 12, screen.get_height() / 2)
pygame.mixer.music.load("dwtd.mp3")
pygame.mixer.music.set_volume(0.7)
pygame.mixer.music.play()
bala_pos = pygame.Vector2(10, player_pos.y+40)
dt = 0   
def game_scr():
        running = True 
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

            pygame.draw.rect(screen, "red", (bala_pos.x,bala_pos.y,50,25))

            
            img=pygame.image.load(os.path.join("space-ship.png"))
            imga=pygame.transform.scale(img,(100,100))
            screen.blit(imga,player_pos)

            
            keys = pygame.key.get_pressed()
            if keys[pygame.K_UP] or keys[pygame.K_w]:
                if player_pos.y>=0:
                    player_pos.y -= 300 * dt
            if keys[pygame.K_DOWN] or keys[pygame.K_s]:
                if player_pos.y<=screen.get_height()-100:
                    player_pos.y += 300 * dt
            if keys[pygame.K_LEFT] or keys[pygame.K_a]:
                if player_pos.x>=0:
                    player_pos.x -= 300 * dt
            if keys[pygame.K_RIGHT] or keys[pygame.K_d]:
                if player_pos.x<=screen.get_width()-100:
                    player_pos.x += 300 * dt
            if keys[pygame.K_SPACE]:
                disparar()
                pygame.display.update()
                    
            # flip() the display to put your work on screen
            pygame.display.update()

            # limits FPS to 60
            # dt is delta time in seconds sinc e last frame, used for framerate-
            # independent physics.
            dt = clock.tick(90) / 1000
        pygame.quit()


def disparar():
    print(bala_pos.x)
    bala_pos.x += 300 * dt

game_scr()