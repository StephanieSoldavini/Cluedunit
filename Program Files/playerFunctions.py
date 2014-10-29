import random
import notes
import cards

players = []
characters = cards.characters
weapons = cards.weapons
rooms = cards.rooms


class Player:
    def __init__(self, name, character, human, order, location, cards):
        self.name = name
        self.character = character
        self.human = human #boolean
        self.order = order
        self.location = location
        self.cards = cards
        players.append(self)

    def __repr__(self):
        return self.name + " as " + str(self.character)

    def __str__(self):
        return str(self.character)

        # # go to a room if:

    # #   you have it
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
        who = findObject(input("Who? "))
        what = findObject(input("What? "))
        where = findObject(input("Where? "))  #should be location
        return notes.suggest(who, what, where, self)

    def showCard(self, showTo, sug):
        sugSet = {sug.who, sug.what, sug.where}
        #DEBUG
        #print("Suggestion set:", sugSet)
        hasSet = set(self.cards)
        #DEBUG
        print("{} has:".format(self), hasSet)
        canShow = hasSet & sugSet
        #DEBUG
        print("{} can show:".format(self), canShow)
        if canShow:
            if self.human:
                if len(canShow) > 1:
                    cardToShow = input("You can show {}. Which one would you like to? ".format(canShow)).capitalize()
                else:
                    cardToShow = canShow
                    input("{} must show {}. Hit enter to do so ".format(self.character, canShow))
            else:
                cardToShow = random.sample(canShow, 1)
            return cardToShow
            #ai.pickcard()
        else:
            return False


def findObject(what):
    what = what.upper()
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

    return what

def createPlayers(numChar, numComp):
    tempChars = characters[:]
    for people in range(numChar - numComp):
        name = input("What is player {}'s name? ".format(people))
        print("Remaining characters:", \
              ["{} = {}".format(a.abbr, a.name) for a in tempChars])
        charName = input("What character will you be? ").upper()
        for x in tempChars:
            if x.abbr == charName:
                character = x
                tempChars.remove(x)
        Player(name, character, True, 0, None, [])

    for c in range(numComp):
        name = "Comp{}".format(c)
        character = tempChars[random.randint(0, len(tempChars) - 1)]
        Player(name, character, False, 0, None, [])
        tempChars.remove(character)
    print(players)


        # createCharacters()
def createPlayersTest(test):
    tempChars = characters[:]
    if test == "N":
        numChar = int(input("Enter number of players (3 to 6): "))
        if numChar < 3 or numChar > 6:
            print("Invalid number of players.")
            createPlayers()
        else:
            numComp = int(input("How many of those are computers? (0 to {}): "
                                .format(numChar)))
            if numComp not in range(numChar + 1):
                print("Invalid number of computers.")
                createPlayers()
            createPlayers(numChar, numComp)
    else:
        #creates 3 human players so I don't have to for testing
        numChar = 3
        for c in range(numChar):
            name = "Player{}".format(c)
            character = tempChars[random.randint(0, len(tempChars) - 1)]
            Player(name, character, True, 0, None, [])
            tempChars.remove(character)
        print(players)

# createPlayers()

#print (players[0].makeSuggestion("Plum", "Candlestick", "Conservatory"))            
