
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

        if keycode[1] == 'right':
            self.white.center_x += self.width*(.0375)
        elif keycode[1] == 'left':
            self.white.center_x -= self.width*(.0375)
        elif keycode[1] == 'up':
            self.white.center_y += self.height*(.03775)
        elif keycode[1] == 'down':
            self.white.center_y -= self.height*(.03775)
        elif keycode[1] == 'w':
            quit(ClueApp())   
        print("new center", self.white.center)
        return True

    def placePiece(self):
        print(Window.size)
        space = (1,6)
        self.white.center = (52 -13.5 + (space[0] + .5) * 37.5) * \
            (Window.size[0]/1000), (15 -13.5 + (space[1] + .5) * 37.96) * \
            (Window.size[1]/1000)

        print("center", self.white.center)

def spaceToPixel(space):
    """
    converts a board space (when the 0,0 space is by conservatory) to a 
        pixel (when 0,0 is the same corner)
    :param space: tuple with x first
    :return: tuple with x first
    """
    x_pixel = (55 + (space[0] + .5) * 37.5) * (Window.size[0]/1000)
    y_pixel = (15 + (space[1] + .5) * 37.96) * (Window.size[1]/1000)
    print("Without scaling", x_pixel, y_pixel)
    return x_pixel, y_pixel
        
class CluePiece(Widget):
    def move(self):
        pass

class ClueBoard(Widget):
    pass

class ClueApp(App):
    def build(self):
        game = ClueGame()
        game.placePiece()
        return game

def quit(app):
    app.stop()

size = str(850)

if __name__ == '__main__':
    Config.set('graphics', 'fullscreen', '0')
    Config.set('graphics', 'width', size)
    Config.set('graphics', 'height', size)
    Config.set('graphics', 'resizable', 0)
    Config.write()
    ClueApp().run() 
