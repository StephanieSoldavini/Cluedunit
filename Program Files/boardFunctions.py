import random
from functions import *
from time import *

rooms = ["Conservatory", "Ballroom", "Kitchen", "Billiard Room", \
         "Dining Room", "Library", "Study", "Hall", "Lounge"]

###---Function definitions---

def createBoard(w, h):
    board = []
    for x in range(w):
      board.append([])
      for y in range(h):
        #a = x,y
        board[x].append("")
    return board

def addToBoard(lst, board):
    for places in lst:
        x = int(places[0].strip())
        y = int(places[1].strip())
        board[x][y] = places[2].strip()

def fillBoard():
    board = createBoard(24, 25)

    #rooms = openFile("rooms")
    #addToBoard(rooms, board)

    homeSpaces = openFile("homeSpaces")
    addToBoard(homeSpaces, board)

    #plain hallway locations
    hallways = openFile("hallways")

    for halls in range(len(hallways)):
        x = halls
        for square in hallways[halls]:
            if square.strip() != "":
                y = int(square.strip())
                board[x][y] = "hallway"

    #for row in board:
    #    print (row)
    print ("Board created!")
    return board

boardDict = {}

def createGrid(board):
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
    roomList = openFile("rooms")
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


def bfs(graph, start, end):
    # maintain a queue of paths
    queue = []
    # push the first path into the queue
    queue.append([start])
    while queue:
        # get the first path from the queue
        path = queue.pop(0)
        # get the last nBode from the path
        node = path[-1]
        # path found
        if node == end:
            return path
        # enumerate all adjacent nodes, construct a new path and push it into the queue
        for adjacent in graph.get(node, []):
            if adjacent not in path:
                new_path = list(path)
                new_path.append(adjacent)
                queue.append(new_path)


board = fillBoard()
boardDict = createGrid(board)

#DEBUG
# for key in boardDict:
#     print (key, "-->", boardDict[key])
# start = input("Starting location: ")
# end = input("Ending location: ")
#
# print(bfsCheck(boardDict, start, end))




















