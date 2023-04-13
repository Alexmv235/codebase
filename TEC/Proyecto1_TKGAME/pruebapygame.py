# Example file showing a circle moving on screen
import pygame
from gamescreen import game_scr

# pygame setup
pygame.init()

def menu():
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

            # fill the screen with a color to wipe away anything from last frame
            screen.fill("blue")

            keys = pygame.key.get_pressed()
            if keys[pygame.K_COMMA] or keys[pygame.K_w]:
                game_scr()

            # flip() the display to put your work on screen
            pygame.display.update()

            # limits FPS to 60
            # dt is delta time in seconds since last frame, used for framerate-
            # independent physics.
            dt = clock.tick(60) / 1000
        pygame.quit()
        

menu()
