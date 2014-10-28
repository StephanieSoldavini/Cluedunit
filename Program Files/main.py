import boardFunctions
import playerFunctions
import cards
import notes


players = players
# #if suggestion made here previously:
##    take secret passage or roll/move
##
##suggestion or accusation

def main():
    boardFunctions.fillBoard()
    cards.createEverything()
    playerFunctions.createPlayers()

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
        print("It is {}'s turn".format(p))
        suggestion = p.makeSuggestion()
        j = i
        shown = False
        while shown == False:
            j = (j+1)%len(players)
            shown = players[j].showCard(p, suggestion)
        print(players[j], shown)

main()


