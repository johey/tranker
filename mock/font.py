import pygame

class Fontloader:
  def __init__(self):
    self.line = ' !"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~'
    self.image_width = 19
    self.font_x = 4
    self.font_y = 5
    self.font_spacing = 0
    self.font_image = pygame.image.load("341.png")
  
  def char_pos(self, character):
    try:
      i = self.line.index(character)
      row = int(i / self.image_width)
      col = i % self.image_width
      pos = (col * (self.font_x + self.font_spacing) + self.font_spacing, row * (self.font_y + self.font_spacing) + self.font_spacing, self.font_x, self.font_y)
    except ValueError:
      pos = (0, 0, self.font_x, self.font_y)

    return pos

  def print(self, text):
    ts = pygame.Surface((self.font_x*len(text), self.font_y))
    i = 0;
    for c in text:
      ts.blit(self.font_image, (i * self.font_x, 0), self.char_pos(c))
      i += 1

    return ts


small = Fontloader()

