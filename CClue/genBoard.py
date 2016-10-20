rooms = ["Conservatory", "Ballroom", "Kitchen", "BilliardRoom", \
         "DiningRoom", "Library", "Study", "Hall", "Lounge"]

def openFile(file):
    lst = []
    with open(file) as f:
        for line in f:
            line = line.strip()
            line = line.split(";")
            lst.append([l.strip() for l in line])
    return lst  

def createBoard(w, h):
    board = []
    for x in range(w):
      board.append([])
      for y in range(h):
        #a = x,y
        board[x].append("")
    return board

def createGrid(board):
    boardDict = {}
    # for all of the x and y values, determine if there is a
    # hallway there and make a hallway key in the dictionary
    for x in range(len(board)):
        for y in range(len(board[x])):
            if board[x][y] == "hallway":
                boardDict[(x, y)] = []
            elif "Home" in board[x][y]:   
                boardDict[(x, y)] = []


    # ask all of the hallways if they have neighbors and add
    # references to those neighbors
    for node in boardDict:
        x, y = node
        for b in [(x, y+1), (x, y-1),\
                  (x+1, y), (x-1, y)]:
            if b in boardDict:
                boardDict[(x, y)].append(b)

    # process the rooms and create keys for them and add
    # references to hallways
    roomList = openFile("rooms.txt")
    for r in roomList:
        doors = [tuple(int(f1) for f1 in f) for f in \
                 [a.strip("() ").split(",") for a in r[1:]]]
        boardDict[r[0]] = [a for a in doors]

    # add room references to the appropriate hall spaces
    for room in rooms:
        for hallway in boardDict[room]:
            boardDict[hallway].append(room)

    # add secret passage references
    boardDict["Study"].append("Kitchen")
    boardDict["Kitchen"].append("Study")
    boardDict["Conservatory"].append("Lounge")
    boardDict["Lounge"].append("Conservatory")

    return boardDict

def main():
    boardArray = createBoard(24, 25)

    homeSpaces = openFile("homeSpaces.txt")
    for places in homeSpaces:
        x = int(places[0].strip())
        y = int(places[1].strip())
        boardArray[x][y] = places[2].strip()

    hallways = openFile("hallways.txt")
    for halls in range(len(hallways)):
        x = halls
        for square in hallways[halls]:
            if square.strip() != "":
                y = int(square.strip())
                boardArray[x][y] = "hallway"

    boardDict = createGrid(boardArray);
   
    with open("boardGraph.h", 'w') as f:
        for loc in boardDict:
            adjs = 4*["NULL"] 
            if isinstance(loc, tuple):
                col = loc[1]
                row = loc[0]
                name = "hallway_r" + str(row) + "c" + str(col)
                room = "NULL"
            elif isinstance(loc, str):
                name = loc
                room = loc
                col = "NULL"
                row = "NULL"
            else:
                name = "INVALID"
                room = "INVALID"
                col = "INVALID"
                row = "INVALID"
            for i in range(len(boardDict[loc])):
                adj = boardDict[loc][i]
                if isinstance(adj, tuple):
                    adjs[i] = "&hallway_r" + str(adj[0]) + "c" + str(adj[1])
                elif isinstance(adj, str):
                    adjs[i] = "&" + adj
            f.write("const location {name} = {{{room}, {row}, {col}, {{{adj0}, {adj1}, {adj2}, {adj3}}}}};\n".format(name=name, room=room, row=row, col=col, adj0=adjs[0], adj1=adjs[1], adj2=adjs[2], adj3=adjs[3])) 


if __name__ == '__main__':
    main()
