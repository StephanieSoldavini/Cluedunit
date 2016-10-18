/*
 * Module for implementation of the game board
 * @author Stephanie
 * @date 7/22/16
 */

#define BOARD_WIDTH ()
#define BOARD_HEIGHT ()
// 24x25
typedef struct location {
    location* up;
    location* down;
    location* left;
    location* right;
} location;

newBoard();
