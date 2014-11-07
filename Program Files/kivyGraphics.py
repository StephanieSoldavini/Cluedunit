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

class CluePiece(Widget):
    #white = ObjectProperty(None)

    def __init__(self, **kwargs):
        """This might do something"""
        super(CluePiece, self).__init__(**kwargs)

    def move(self, keycode):
        position = self.space
        x_pos = position[0]
        y_pos = position[1]
        up = (x_pos, y_pos + 1)
        down = (x_pos, y_pos - 1)
        left = (x_pos - 1, y_pos)
        right = (x_pos + 1, y_pos)
        if keycode[1] == 'right' and (right in boardFunctions.boardDict[position]):
            self.center = spaceToPixel(right)
            self.space = right
        elif keycode[1] == 'left' and (left in boardFunctions.boardDict[position]):
            self.center = spaceToPixel(left)
            self.space = left
        elif keycode[1] == 'up' and (up in boardFunctions.boardDict[position]):
            self.center = spaceToPixel(up)
            self.space = up
        elif keycode[1] == 'down'and (down in boardFunctions.boardDict[position]):
            self.center = spaceToPixel(down)
            self.space = down
        print(self.pos)

    def placePiece(self, space):
        self.space = space
        place = spaceToPixel(space)
        self.center = (place[0] - 10.5, place[1] - 11.25)
        print(self.center)

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
        if keycode[1] == 'w':
            quit(ClueApp())
        else:
            self.white.move(keycode) # will be player.move eventually
        return True

def spaceToPixel(space):
    """
    converts a board space (when the 0,0 space is by conservatory) 
        to a pixel (when 0,0 is the same corner)
    :param space: tuple with x first
    :return: tuple with x first
    """
    windowSize = Window.size
    spaceW = windowSize[0]*(1/26)
    spaceH = windowSize[1]*(1/27)
    x_pixel = ((space[0] + 1.5) * spaceW) 
    y_pixel = ((space[1] + 1.5) * spaceH)
    return x_pixel, y_pixel

class ClueBoard(Widget):
    pass

class ClueApp(App):
    def build(self):
        #white = CluePiece()
        game = ClueGame()
        game.white.placePiece((14,0))
        print("center", game.white.center)
        print("pos", game.white.pos)
        print("size", game.white.size)
        return game

if __name__ == '__main__':
    Config.set('graphics', 'fullscreen', '0')
    Config.set('graphics', 'width', '800')
    Config.set('graphics', 'height', '850')
    Config.set('graphics', 'resizable', 0)
    Config.write()
    ClueApp().run()