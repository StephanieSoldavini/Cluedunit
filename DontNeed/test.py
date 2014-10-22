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
        numComp = int(input("How many of those are computers? (0 to {}) ".format(numChar - 1)))
        if numComp not in range(numChar):
            print ("Invalid number of computers.")
            exit()
        else:           
            for people in range(numChar - numComp):
                name = input("What is player {}'s name? ".format(people))
                print ("Remaining characters:", ["{} = {}".format(a.abbr, a.name) for a in characters])
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

def assign(loc, what):
    x, y = loc
    board[x][y] = what

def fillBoard():
    
    board = createBoard(24, 25)
        
    #home locations
    assign(( 9,  0), "Green Home")
    assign((14,  0), "White Home")
    assign(( 0,  6), "Peacock Home")
    assign(( 0, 19), "Plum Home")
    assign((16, 24), "Scarlet Home")
    assign((23, 17), "Mustard Home")

    #hallway square leading to door locations
    assign(( 5,  5), "Conservatory")

    assign(( 7,  5), "Ballroom")
    assign((16,  5), "Ballroom")
    assign(( 9,  8), "Ballroom")
    assign((14,  8), "Ballroom")

    assign((19,  7), "Kitchen")

    assign(( 6,  9), "Billiard Room")
    assign(( 1, 13), "Billiard Room")

    assign((15, 12), "Dining Room")
    assign((17, 16), "Dining Room")

    assign(( 3, 13), "Library")
    assign(( 7, 16), "Library")

    assign(( 6, 20), "Study")

    assign((11, 17), "Hall")
    assign((12, 17), "Hall")
    assign(( 8, 20), "Hall")

    assign((17, 18), "Lounge")

    #plain hallway locations
    hallways = [[                                                                           ], #0
     [               6, 7,                                           19, 20                 ], #1
     [               6, 7,                   13,                     19, 20                 ], #2
     [               6, 7,                                           19, 20                 ], #3
     [               6, 7,                   13,                     19, 20                 ], #4
     [               6, 7,                   13,                     19, 20                 ], #5
     [   2, 3, 4, 5, 6, 7, 8,    10, 11, 12, 13, 14,             18, 19                     ], #6
     [1, 2, 3, 4,    6, 7, 8, 9, 10, 11, 12, 13, 14, 15,     17, 18, 19, 20, 21, 22, 23, 24 ], #7
     [1,                   8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,     21, 22, 23     ], #8
     [1,                      9,                             17                             ], #9
     [                     8, 9,                             17                             ], #10
     [                     8, 9,                                                            ], #11
     [                     8, 9,                                                            ], #12
     [                     8, 9,                             17                             ], #13
     [1,                      9, 10, 11, 12, 13, 14, 15, 16, 17                             ], #14
     [1,                   8, 9, 10, 11,     13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23     ], #15
     [1, 2, 3, 4,    6, 7, 8, 9,                         16, 17, 18, 19, 20, 21, 22, 23     ], #16
     [   2, 3, 4, 5, 6, 7, 8, 9,                             17                             ], #17
     [                  7, 8, 9,                         16, 17, 18                         ], #18
     [                     8,                            16, 17, 18                         ], #19
     [                  7, 8,                            16, 17, 18                         ], #20
     [                  7, 8,                            16, 17, 18                         ], #21
     [                  7, 8,                            16, 17, 18                         ], #22
     [                  7                                                                   ]] #23

    for h in range(len(hallways)):
        for a in hallways[h]:
            assign((h, a), "hallway")

    end = time.clock()

    rooms = ["Conservatory", "Ballroom", "Kitchen", "Billiard Room", "Dining Room", "Library", "Study", "Hall", "Lounge"]

    print (end-start)

    for row in board:
        print (row)

def move(spaces, currentLoc, destination):
    if spaces < 1:
        pass
    else:
        if currentLoc in rooms:
            """You are in a room"""
            pass
        else:
            x, y = currentLoc
        if destination in rooms:
            """You want to go to a room"""

            
def main():
    createCharacters()
    fillBoard()
    createPlayers()


main()


