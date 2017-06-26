import pygame
from pygame.locals import *
from sys import exit
from font import small


SCALE=3
SCREEN_X=256
SCREEN_Y=192
BORDER=20

pygame.init()
pygame.display.set_caption("Tranker Mock")

tv = pygame.display.set_mode((SCALE*(SCREEN_X+2*BORDER), SCALE*(SCREEN_Y+2*BORDER)), 0, 24)

screen = pygame.Surface((SCREEN_X, SCREEN_Y))

screen.fill((255, 255, 255))
#for i in range(1024):
#  screen.set_at((i%256, i%192), (255, 255, 255))
screen.blit(small.print("I01 A A# B C D D# E 4 F F# G G#8"), (100, 100))
#screen.blit(small.font_image, (10, 3))
while True:
  for i in pygame.event.get():
    if (i.type == QUIT):
      print("Quitting")
      exit()

  tv.blit(pygame.transform.scale(screen, (SCALE*SCREEN_X, SCALE*SCREEN_Y)), (SCALE*BORDER, SCALE*BORDER))
  pygame.display.flip()

