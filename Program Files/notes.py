suggestions = []


class Suggestion:
    def __init__(self, who, what, where, byWhom, whoCantShow, whoShows):
        self.who = who
        self.what = what
        self.where = where
        self.byWhom = byWhom
        self.whoCantShow = whoCantShow
        self.whoShows = whoShows
        suggestions.append(self)

    def __repr__(self):
        return str(self.byWhom) + " suggests " + self.who + " with the " + \
               self.what + " in the " + self.where + "."

class Notes:
    def __init__(self, have, ownGuess, ):
        pass


def suggest(who, what, where, byWhom):
    return Suggestion(who, what, where, byWhom, "", "")



# print (Suggestion("Plum", "Candlestick", "Conservatory", "Scarlet", "", ""))

#print (suggestions)

# You make a suggestion
# Can the person to the left show?
    # Yes
        # Record their card
        # 
    # No
        # They have none of the three
        # Can the next person to the left show?
            # Yes


# for p in players:
#     if p.canshow(suggestion):
#         
#         return p
#     else:
#         p does not have any of the suggested cards                
