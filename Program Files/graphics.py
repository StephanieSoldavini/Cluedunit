import os, pygame
from pygame.locals import *
from pygame.compat import geterror

pygame.init()

main_dir = os.path.split(os.path.abspath(__file__))[0]
data_dir = os.path.join(main_dir, 'images')


def load_image(name, colorkey=None):
    fullname = os.path.join(data_dir, name)
    try:
        image = pygame.image.load(fullname)
    except pygame.error:
        print('Cannot load image:', fullname)
        raise SystemExit(str(geterror()))
    image = image.convert()
    if colorkey is not None:
        if colorkey is -1:
            colorkey = image.get_at((0, 0))
        image.set_colorkey(colorkey, RLEACCEL)
    return image


class People(pygame.sprite.Sprite):
    def __init__(self, image):
        pygame.sprite.Sprite.__init__(self)  # call Sprite initializer
        self.image, self.rect = load_image(People.name, -1)


class HumanPlayer(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)  # call Sprite initializer
        self.image, self.rect = load_image(HumanPlayer.name, -1)  # ?????Maybe not Player.name

    def move(self):
        pass
    


class ComputerPlayer(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)  # call Sprite initializer
        self.image, self.rect = load_image(HumanPlayer.name, -1)  # ?????Maybe not Player.name

    # def move(self, direction, player):

class Weapon(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)  # call Sprite initializer
        self.image, self.rect = load_image(Weapon.name, -1)  #?????Maybe not Weapon.name

def drawBG():

    screen = pygame.display.set_mode((1000, 1000), RESIZABLE)
    background = load_image('ScanBoard.bmp')
    height, width = background.get_rect().size
    background = background.convert()
    background = pygame.transform.scale(background, (1000, 1010))
    screen.blit(background, (0, 0))
    pygame.display.flip()

def main():
    drawBG()
    input("Press enter")

main()