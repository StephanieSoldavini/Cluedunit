import boardFunctions
import playerFunctions
import cards
import notes
import random

players = playerFunctions.players
# #if suggestion made here previously:
##    take secret passage or roll/move
##
##suggestion or accusation

def main():
    boardFunctions.fillBoard()
    cards.createEverything()
    test = input("Do you want to use premade players? (Y/N)").capitalize()
    playerFunctions.createPlayersTest(test)

    print("Characters:", cards.characters)
    print("Weapons:", cards.weapons)
    print("Rooms:", cards.rooms)
    cards.makeSolutionAndDeal(cards.characters, cards.weapons, cards.rooms, \
                              players)
    for p in players:
        print("{}'s cards:".format(p), p.cards)

    for i in range(len(players)):
        p = players[i]
        # Suggestion
        print ()
        print("##### It is {}'s turn. #####".format(p))
        if p.human:
            suggestion = p.makeSuggestion()
            show(p, i, suggestion)
        else:
            #ai.makesug
            suggestion = notes.suggest( \
                cards.characters[random.randrange(0, len(cards.characters))], \
                cards.weapons[random.randrange(0, len(cards.weapons))], \
                cards.rooms[random.randrange(0, len(cards.rooms))], p)
            print(suggestion)
            show(p, i, suggestion)

def show(p, i ,suggestion):
    j = i + 1
    shown = False
    while shown == False and j != i:
        j = (j+1)%len(players)
        shown = players[j - 1].showCard(p, suggestion)
    if shown:
        print("{} shows {} to {}".format(players[j - 1], shown, players[i]))
    else:
        print("No one can show.")


main()


