import time
import random

players = []
characters = []

##---Class definitions---

class Player:
    def __init__(self, name, character, order, location):
        self.name = name
        self.character = character
        self.order = order
        self.location = location
        players.append(self)
        
    def __repr__(self):
        return self.name + " as " + str(self.character)

class Character:
    def __init__(self, name, abbr, color):
        self.name = name
        self.abbr = abbr
        self.color = color
        characters.append(self)
        
    def __repr__(self):
        return self.name

###---Function definitions---

def createCharacters():
    White   = Character("Mrs. White",   "WH", "white")    
    Scarlet = Character("Ms. Scarlet",  "SC", "red")
    Mustard = Character("Col. Mustard", "MU", "yellow")
    Green   = Character("Mr. Green",    "GR", "green") 
    Peacock = Character("Mrs. Peacock", "PE", "blue")
    Plum    = Character("Prof. Plum",   "PL", "purple")    

def createPlayers():
    numChar = int(input("Enter number of players (3 to 6): "))
    if numChar < 3 or numChar > 6:
        print ("Invalid number of players.")
        exit()
    else:
        numComp = int(input("How many of those are computers? (0 to {}) " \
            .format(numChar - 1)))
        if numComp not in range(numChar):
            print ("Invalid number of computers.")
            exit()
        else:           
            for people in range(numChar - numComp):
                name = input("What is player {}'s name? ".format(people))
                print ("Remaining characters:", \
                        ["{} = {}".format(a.abbr, a.name) for a in characters])
                charName = input("What character will you be? ")
                for x in characters:
                    if x.abbr == charName:
                        character = x
                        characters.remove(x)
                Player(name, character, 0, None)
                
            for c in range(numComp):
                name = "Comp{}".format(c)
                character = characters[random.randint(0, len(characters) - 1)]
                Player(name, character, 0, None)
                
                characters.remove(character)
            print (players)     

def createBoard(w, h):
    board = []  
    for x in range(w):
      board.append([])
      for y in range(h):
        #a = x,y
        board[x].append("")
    return board

def fillBoard():
    
    board = createBoard(24, 25)
    importantPlaces = []

    with open("importantPlaces.txt", encoding = "utf-8") as f:
        for line in f:
            importantPlaces.append(line.split(","))
    
    for places in importantPlaces:
        x = int(places[0].strip())
        y = int(places[1].strip())
        board[x][y] = places[2].strip()

    #plain hallway locations
    hallways = []
    
    with open("hallways.txt", encoding = "utf-8") as g:
        for line in g:
            hallways.append(line.split(","))

    for halls in range(len(hallways)):
        x = halls
        for square in hallways[halls]:
            if square.strip() != "":
                y = int(square.strip())
                board[x][y] = "hallway"
    
    for row in board:
        print (row)

rooms = ["Conservatory", "Ballroom", "Kitchen", "Billiard Room", \
         "Dining Room", "Library", "Study", "Hall", "Lounge"]

##if suggestion made here previously:
##    take secret passage or roll/move
##
##suggestion or accusation

## go to a room if:
##   you have it
##   never seen
##   NOT if seen from someone else

##find closest room that fits above condition, that is destination

##if a piece is in a location, make that location impassable 

def move(spaces, currentLoc, destination):
    while spaces > 0:
        if currentLoc in rooms:
            """You are in a room"""
            #pick a door
            #
            pass
        else:
            """You are on the board"""
            x, y = currentLoc
            
        if destination in rooms:
            """You want to go to a room"""
            
def main():
    createCharacters()
    fillBoard()
    createPlayers()

main()


