import random
import notes
import cards

players = []
characters = cards.characters 

class Player:
    def __init__(self, name, character, order, location):
        self.name = name
        self.character = character
        self.order = order
        self.location = location
        players.append(self)
        
    def __repr__(self):
        return self.name + " as " + str(self.character)

    def __str__(self):
        return str(self.character)  

    ## go to a room if:
    ##   you have it
    ##   never seen
    ##   NOT if seen from someone else

    ##find closest room that fits above condition, that is destination

    ##if a piece is in a location, make that location impassable 

    def move(self, spaces, destination):
        inNewRoom = False
        # find the closest doors of current room and detination room

        while spaces > 0 and inNewRoom == False:
            if location in rooms:
                """You are in a room"""
                # pick a door closest to destination
                # move out of that door
                pass
            else:
                """You are on the board"""
                x, y = location
                if board[x][y] in rooms:
                    """You are on a door space"""
                    # do you want to go into that room? 
                        # move piece in that direction
                        # inNewRoom = True
                    # else
                        # move piece in a different direction
                    pass
                else:
                    """You are in a hallway space"""
                    # check the y of the destination        
            spaces -= 1    
            if destination in rooms:
                """You want to go to a room"""  

    def makeSuggestion(self):
        ## These inputs need to find the objects they reference
        who = input("Who? ")
        what = input("What? ")
        where = input("Where? ") #should be location
        return notes.suggest(who, what, where, self)

    def showCard(self, showTo):
        pass            



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
                charName = input("What character will you be? ").capitalize()
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

#createCharacters()

#createPlayers()

#print (players[0].makeSuggestion("Plum", "Candlestick", "Conservatory"))            
