import kivy
kivy.require('1.1.1')

from kivy.app import App
from kivy.uix.widget import Widget
from kivy.properties import NumericProperty, ReferenceListProperty,\
    ObjectProperty
from kivy.vector import Vector
from kivy.clock import Clock
from kivy.config import Config

class ClueGame(Widget):
    white = ObjectProperty(None)
    
    def __init__(self, **kwargs):
        super(PongGame, self).__init__(**kwargs)
        self._keyboard = Window.request_keyboard(self._keyboard_closed, self)
        self._keyboard.bind(on_key_down=self._on_keyboard_down)

    def _keyboard_closed(self):
        self._keyboard.unbind(on_key_down=self._on_keyboard_down)
        self._keyboard = None

    def _on_keyboard_down(self, keyboard, keycode, text, modifiers):
        if keycode[1] == 'right':
            self.white.center_x += 10
        elif keycode[1] == 'left':
            self.white.center_x -= 10
        elif keycode[1] == 'up':
            self.white.center_y += 10
        elif keycode[1] == 'down':
            self.white.center_y -= 10
        return True


        

class CluePiece(Widget):
    def move(self):


class ClueApp(App):
    def build(self):
        game = ClueGame()
        return game

size = str(850)

if __name__ == '__main__':
    Config.set('graphics', 'fullscreen', '0')
    Config.set('graphics', 'width', size)
    Config.set('graphics', 'height', size)
    Config.write()
    ClueApp().run() 
