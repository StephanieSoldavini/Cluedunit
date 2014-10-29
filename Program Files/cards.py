from functions import *
import random

characters = []
weapons = []
rooms = []

class Character:
    def __init__(self, name, abbr, location):
        self.name = name
        self.abbr = abbr
        characters.append(self)
        
    def __repr__(self):
        return self.name

class Weapon:
    def __init__(self, name, location):
        self.name = name
        self.location = location
        weapons.append(self)

    def __repr__(self):
        return self.name

class Room:
    def __init__(self, name):
        self.name = name
        rooms.append(self)
    
    def __repr__(self):
        return self.name

def createEverything():
    cards = openFile("cards")
    for card in cards:
        if card[0] == "CHARACTER":
            Character(card[1], card[2], "") 
        elif card[0] == "WEAPON":
            Weapon(card[1], "")
        elif card[0] == "ROOM":
            Room(card[1])   

class Card:
    def __init__(self, heldBy, seenBy, typeOfCard, what):
        self.heldBy = heldBy #player object
        self.seenBy = seenBy #list of player objects
        self.typeOfCard = typeOfCard
        self.what = what     #character, weapon, or room object

    def __repr__(self):
        return ("The " + str(self.what) + " card.")    

# def createCard(heldBy, what):
#     what = what.upper()
#     for w in weapons:
#         if w.name == what:
#             typeOfCard = "weapon"
#             what = w
#     for c in characters:
#         if c.abbr == what:
#             typeOfCard = "character"
#             what = c
#     for r in rooms:
#         if r.name == what:
#             typeOfCard = "room"
#             what = r         

#     return Card(heldBy, [heldBy], typeOfCard, what)

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




