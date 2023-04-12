# Example file showing a circle moving on screen
import os
import pygame

# pygame setup
pygame.init()


class Menu:
    def __init__(self):
        pygame.init()
        screen = pygame.display.set_mode((1280, 720))
        pygame.display.set_caption('Alex pygame')
        clock = pygame.time.Clock()
        running = True
        while running:
            # poll for events
            # pygame.QUIT event means the user clicked X to close your window
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

            # fill the screen with a color to wipe away anything from last frame
            screen.fill("blue")

            keys = pygame.key.get_pressed()
            if keys[pygame.K_COMMA] or keys[pygame.K_w]:
                game_scr()

            # flip() the display to put your work on screen
            pygame.display.flip()

            # limits FPS to 60
            # dt is delta time in seconds since last frame, used for framerate-
            # independent physics.
            dt = clock.tick(60) / 1000
        pygame.quit()
        

class game_scr():
    def __init__(self):
        pygame.init()
        pygame.mixer.init()
        screen = pygame.display.set_mode((1280, 720))
        pygame.display.set_caption('jUEGO')
        clock = pygame.time.Clock()
        running = True
        dt = 0
        player_pos = pygame.Vector2(screen.get_width() / 2, screen.get_height() / 2)

        while running:
            # poll for events
            # pygame.QUIT event means the user clicked X to close your window
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

            # fill the screen with a color to wipe away anything from last frame
            bg=pygame.image.load(os.path.join("space2.gif"))
            bgs=pygame.transform.scale(bg,(1280,720))
            screen.blit(bgs,(0,0))

            pygame.mixer.music.load("dwtd.mp3")
            pygame.mixer.music.set_volume(0.7)
            pygame.mixer.music.play()

            
            img=pygame.image.load(os.path.join("space-ship.png"))
            imga=pygame.transform.scale(img,(100,100))
            screen.blit(imga,player_pos)

            keys = pygame.key.get_pressed()
            if keys[pygame.K_UP] or keys[pygame.K_w]:
                player_pos.y -= 300 * dt
            if keys[pygame.K_DOWN] or keys[pygame.K_s]:
                player_pos.y += 300 * dt
            if keys[pygame.K_LEFT] or keys[pygame.K_a]:
                player_pos.x -= 300 * dt
            if keys[pygame.K_RIGHT] or keys[pygame.K_d]:
                player_pos.x += 300 * dt

            # flip() the display to put your work on screen
            pygame.display.flip()

            # limits FPS to 60
            # dt is delta time in seconds since last frame, used for framerate-
            # independent physics.
            dt = clock.tick(60) / 1000
        pygame.quit()

#ventana_principal=Menu()

screen = pygame.display.set_mode((1280, 720))
pygame.display.set_caption('jUEGO')
clock = pygame.time.Clock()
running = True
dt = 0
player_pos = pygame.Vector2(screen.get_width() / 2, screen.get_height() / 2)

while running:
    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # fill the screen with a color to wipe away anything from last frame
    bg=pygame.image.load(os.path.join("space2.gif"))
    bgs=pygame.transform.scale(bg,(1280,720))
    screen.blit(bgs,(0,0))

    pygame.mixer.music.load("dwtd.mp3")
    pygame.mixer.music.set_volume(0.7)
    pygame.mixer.music.play()

    
    img=pygame.image.load(os.path.join("space-ship.png"))
    imga=pygame.transform.scale(img,(100,100))
    screen.blit(imga,player_pos)

    keys = pygame.key.get_pressed()
    if keys[pygame.K_UP] or keys[pygame.K_w]:
        player_pos.y -= 300 * dt
    if keys[pygame.K_DOWN] or keys[pygame.K_s]:
        player_pos.y += 300 * dt
    if keys[pygame.K_LEFT] or keys[pygame.K_a]:
        player_pos.x -= 300 * dt
    if keys[pygame.K_RIGHT] or keys[pygame.K_d]:
        player_pos.x += 300 * dt

    # flip() the display to put your work on screen
    pygame.display.update()

    # limits FPS to 60
    # dt is delta time in seconds since last frame, used for framerate-
    # independent physics.
    dt = clock.tick(60) / 1000
pygame.quit()