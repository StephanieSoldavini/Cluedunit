import boardFunctions
import playerFunctions
import cards
import notes

##if suggestion made here previously:
##    take secret passage or roll/move
##
##suggestion or accusation
			
def main():
	boardFunctions.fillBoard()
	cards.createEverything()
	playerFunctions.createPlayers()
	
	print ("Characters:", cards.characters)
	print ("Weapons:", cards.weapons)
	print ("Rooms:", cards.rooms)
	cards.makeSolutionAndDeal(cards.characters, cards.weapons, cards.rooms, \
		playerFunctions.players)
	for p in playerFunctions.players:
		print ("{}'s cards:".format(p), p.cards)
	
	for i in range(len(playerFunctions.players)):
		p = playerFunctions.players[i]
		# Suggestion
		print ("It is {}'s turn".format(p))
		print (p.makeSuggestion())
		j = i + 1
		shown = False
		#while shown == False:
		#	playerFunctions.players[j].showCard(p)
main()


