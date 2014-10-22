import random

players = []
characters = []

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

White   = Character("Mrs. White",   "WH", "white")    
Scarlet = Character("Ms. Scarlet",  "SC", "red")
Mustard = Character("Col. Mustard", "MU", "yellow")
Green   = Character("Mr. Green",    "GR", "green") 
Peacock = Character("Mrs. Peacock", "PE", "blue")
Plum    = Character("Prof. Plum",   "PL", "purple")

def main():
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
        
main()



