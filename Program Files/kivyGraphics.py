from __future__ import division
import kivy
kivy.require('1.1.1')

from kivy.app import App
from kivy.uix.widget import Widget
from kivy.properties import NumericProperty, ReferenceListProperty,\
    ObjectProperty
from kivy.vector import Vector
from kivy.clock import Clock
from kivy.config import Config
from kivy.core.window import Window
# from kivy.uix.layout import Relative
import boardFunctions

class ClueGame(Widget):
    white = ObjectProperty(None)

    def __init__(self, **kwargs):
        super(ClueGame, self).__init__(**kwargs)
        self._keyboard = Window.request_keyboard(self._keyboard_closed, self)
        self._keyboard.bind(on_key_down=self._on_keyboard_down)


    def _keyboard_closed(self):
        self._keyboard.unbind(on_key_down=self._on_keyboard_down)
        self._keyboard = None

    def _on_keyboard_down(self, keyboard, keycode, text, modifiers):
        # # newSpace = input("Space to go to:")
        # path = boardFunctions.bfs(boardFunctions.boardDict, (14, 1), (16, 5))
        # #DEBUG
        # print(path)
        # for space in path:
        #     self.white.center = spaceToPixel(space)
        # #DEBUG
        # print(self.white.center)
        # return True
        position = self.white.space
        x_pos = position[0]
        y_pos = position[1]
        up = (x_pos, y_pos + 1)
        down = (x_pos, y_pos - 1)
        left = (x_pos - 1, y_pos)
        right = (x_pos + 1, y_pos)
        if keycode[1] == 'right' and (right in boardFunctions.boardDict[position]):
            self.white.center = spaceToPixel(right)
            self.white.space = right
        elif keycode[1] == 'left' and (left in boardFunctions.boardDict[position]):
            self.white.center = spaceToPixel(left)
            self.white.space = left
        elif keycode[1] == 'up' and (up in boardFunctions.boardDict[position]):
            self.white.center = spaceToPixel(up)
            self.white.space = up
        elif keycode[1] == 'down'and (down in boardFunctions.boardDict[position]):
            self.white.center = spaceToPixel(down)
            self.white.space = down
        elif keycode[1] == 'w':
            quit(ClueApp())
        return True

    def placePiece(self, space):
        # print(Window.size)
        self.white.space = space
        self.white.center = spaceToPixel(space)
        print(self.white.center)

def spaceToPixel(space):
    """
    converts a board space (when the 0,0 space is by conservatory) to a pixel (when 0,0 is the same corner)
    :param space: tuple with x first
    :return: tuple with x first
    """
    windowSize = Window.size
    space = (14,0)
    spaceW = windowSize[0]*(1/26)
    spaceH = windowSize[1]*(1/27)
    x_pixel = ((space[0] + 1.5) * spaceW - 10.5) 
    y_pixel = ((space[1] + 1.5) * spaceH - 11.25)
    return (x_pixel, y_pixel)


class CluePiece(Widget):
    def move(self):
        pass

class ClueBoard(Widget):
    pass

class ClueApp(App):
    def build(self):
        game = ClueGame()
        game.placePiece((14,1))
        return game


if __name__ == '__main__':
    Config.set('graphics', 'fullscreen', '0')
    Config.set('graphics', 'width', '800')
    Config.set('graphics', 'height', '850')
    Config.set('graphics', 'resizable', 0)
    Config.write()
    ClueApp().run() 
