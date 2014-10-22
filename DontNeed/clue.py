board=[]

for i in range(24): 
    board.append([])
    for j in range(25):
        board[i].append("")

(board[5])[9] = "Billiard Room"

for i in range(len(board)):
    print (board[i])


##
##list[1][0]
##
##[ [(0, 0), (0, 1)],
##  [(1, 0), (1, 1)], ]
##
##+-+-+
##| | |
##+-+-+
##| | |
##+-+-+
##| | |
##+-+-+
##
##
##
##
##(0,1) (1,1)
##(0,0) (1,0)
