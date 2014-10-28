from functions import *
import random

characters = []
weapons = []
rooms = []

class Character:
    def __init__(self, name, abbr, color, location):
        self.name = name
        self.abbr = abbr
        self.color = color
        characters.append(self)
        
    def __repr__(self):
        return self.name

def createCharacters():
    White   = Character("Mrs. White",   "Wh", "white",  "")
    Scarlet = Character("Ms. Scarlet",  "Sc", "red",    "")
    Mustard = Character("Col. Mustard", "Mu", "yellow", "")
    Green   = Character("Mr. Green",    "Gr", "green",  "")
    Peacock = Character("Mrs. Peacock", "Pe", "blue",   "")
    Plum    = Character("Prof. Plum",   "Pl", "purple", "")
    

class Weapon:
    def __init__(self, name, location):
        self.name = name
        self.location = location
        weapons.append(self)

    def __repr__(self):
        return self.name

def createWeapons():
    wrench      = Weapon("Wrench",      "")
    candlestick = Weapon("Candlestick", "") 
    leadPipe    = Weapon("Lead Pipe",   "")
    revolver    = Weapon("Revolver",    "") 
    rope        = Weapon("Rope",        "") 
    knife       = Weapon("Knife",       "")

class Room:
    def __init__(self, name):
        self.name = name
        rooms.append(self)
    
    def __repr__(self):
        return self.name

def createRooms():
    roomSpaces = openFile("inRoom")
    for room in roomSpaces:
        name = room[0].strip()
        Room(name)

def createEverything():
    createCharacters()
    createWeapons()
    createRooms()

class Card:
    def __init__(self, heldBy, seenBy, typeOfCard, what):
        self.heldBy = heldBy #player object
        self.seenBy = seenBy #list of player objects
        self.typeOfCard = typeOfCard
        self.what = what     #character, weapon, or room object

    def __repr__(self):
        return ("The " + str(self.what) + " card.")    

def createCard(heldBy, what):
    what = what.capitalize()
    for w in weapons:
        if w.name == what:
            typeOfCard = "weapon"
            what = w
    for c in characters:
        if c.abbr == what:
            typeOfCard = "character"
            what = c
    for r in rooms:
        if r.name == what:
            typeOfCard = "room"
            what = r         

    return Card(heldBy, [heldBy], typeOfCard, what)

def makeSolutionAndDeal(characters, weapons, rooms, players):
    tempChars = characters[:]
    tempWeaps = weapons[:]
    tempRooms = rooms[:]
    solution = []
    solution.append(tempChars.pop(random.randint(0, (len(tempChars) - 1))))
    solution.append(tempWeaps.pop(random.randint(0, (len(tempWeaps) - 1))))
    solution.append(tempRooms.pop(random.randint(0, (len(tempRooms) - 1))))
    cards = tempChars + tempWeaps + tempRooms
    while cards != []:
        for p in players:
            if cards != []:
                p.cards.append(cards.pop(random.randint(0, (len(cards) - 1))))
    print ("Solution:", solution)


# createEverything()
# makeSolutionAndDeal(characters, weapons, rooms, [a, b, c])    




