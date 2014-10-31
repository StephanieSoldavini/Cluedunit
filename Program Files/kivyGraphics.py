import kivy
kivy.require('1.1.1')

from kivy.app import App
from kivy.uix.widget import Widget
from kivy.properties import NumericProperty, ReferenceListProperty,\
    ObjectProperty
from kivy.vector import Vector
from kivy.clock import Clock

class ClueGame(Widget):
    pass


class ClueApp(App):
    def build(self):
        game = ClueGame()
        return game


if __name__ == '__main__':
    ClueApp().run()
