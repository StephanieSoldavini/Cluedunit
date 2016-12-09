#include <stdio.h>
#include <stdarg.h>
#include "ascii.h"
#include "location.h"

/* Transfer data from one buffer to another
 * outstream: outgoing buffer, usually stdout
 * inFile: incoming text, usually the board file
 */
void printBoard(FILE *outStream, FILE *inFile)
{
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), inFile)) {
        fprintf(outStream, "%s", buffer);
    }
}

/* Move the cursor to the designated location
 * stream: buffer to move the cursor in
 * row: y axis
 * col: x axis
 * ascii: 0 for board coords, 1 if conversion required
 */
void goTo(FILE *stream, int row, int col, int ascii)
{
    int r, c;
    if (ascii) {
        r = row;
        c = col;
    } else {
        r = 2 * row + 2;
        c = 5 * col + 3;
    }
    fprintf(stream, "\33[%d;%dH", r, c);
}

/* Clears from the current location of the cursor to the end of the stream
 * stream: buffer to be cleared
 */
void clearToEnd(FILE *stream)
{
    fprintf(stream, "\33[J");
}

/* Print the ANSI color codes to change the text color
 * Color will remain changed until updates are made
 * stream: buffer to update color in
 * fontColor: the desired color. See header file for enum values
 */
void changeTextColor(FILE *stream, color fontColor)
{
    char string[10];
    switch(fontColor) {
        case RED:
            snprintf(string, sizeof(string), "\33[0;31m");
            break;
        case GREEN:
            snprintf(string, sizeof(string), "\33[0;32m");
            break;
        case YELLOW:
            snprintf(string, sizeof(string), "\33[0;33m");
            break;
        case BLUE:
            snprintf(string, sizeof(string), "\33[1;35m");
            break;
        case PURPLE:
            snprintf(string, sizeof(string), "\33[0;35m");
            break;
        case WHITE:
            snprintf(string, sizeof(string), "\33[0;37m");
            break;
        case DEFAULT:
        default:
            snprintf(string, sizeof(string), "\33[0m");
            break;
    }
    fprintf(stream, "%s", string);
}

direction inputToDirection(int c)
{
    direction dir;
    switch (c) {
        case 'w':
            dir = DEC_ROW;
            break;
        case 'a':
            dir = DEC_COL;
            break;
        case 's':
            dir = INC_ROW;
            break;
        case 'd':
            dir = INC_COL;
            break;
        case 127: /* TODO: Define backspace */
            dir = BACK;
            break;
        default:
            dir = STAY;
            break;
    }
    return dir;
}

void goToHomeRow(FILE *stream)
{
    goTo(stream, 50, 0, 1);
}


void printToHomeRow(FILE *stream, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    goToHomeRow(stream);
    clearToEnd(stream);
    vfprintf(stream, fmt, args);
    va_end(args);
}

void printToTile(FILE *stream, color fontColor, int row, int col, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    goTo(stream, row, col, 0);
    changeTextColor(stream, fontColor);
    vfprintf(stream, fmt, args);
    changeTextColor(stream, WHITE);
    va_end(args);
}

void takeTurn(player *movingPlayer)
{
    int c;
    direction d;
    const location *prevLoc;
    roll(movingPlayer);
    do {
        printToHomeRow(OUTSTREAM, "You rolled a %d and have %d move(s) left", 
                movingPlayer->roll, movingPlayer->roll-movesMade(movingPlayer));
        c = getchar();
        prevLoc = movingPlayer->loc;
        d = move(movingPlayer, inputToDirection(c));
        if (BACK == d) {
            /* TODO: Missing edge case where prev path crosses itself */
            printToTile(OUTSTREAM, WHITE, prevLoc->row, prevLoc->col, "  ");
        } else {
            printToTile(OUTSTREAM, movingPlayer->playerColor, prevLoc->row, prevLoc->col, "x ");
        }
        printToTile(OUTSTREAM, movingPlayer->playerColor, movingPlayer->loc->row,
                movingPlayer->loc->col, movingPlayer->abbr);
        /* TODO: Ask for confirmation */
    } while (movesMade(movingPlayer) < movingPlayer->roll && c != 'q');
    while (NULL != (prevLoc = getPrevLoc(movingPlayer))) {
        printToTile(OUTSTREAM, WHITE, prevLoc->row, prevLoc->col, "  ");
    }


}

/* Puts each player in their starting location on the board
 * TODO: This should take a list of players, not hardcoded for Plum
 */
void placePlayers(player *newPlayer)
{
    printToTile(OUTSTREAM, newPlayer->playerColor, newPlayer->loc->row, 
            newPlayer->loc->col, newPlayer->abbr);
}


/* Converts a player's response into an integer for parsing.
 * Limited to one character or a number of any digits (smaller than int)
 * returns: int representation of response
 */
int getPlayerInput()
{
    int retval;
    ECHO_ON;
    CURSOR_ON(OUTSTREAM);
    fscanf(INSTREAM, "%d", &retval);
    CURSOR_OFF(OUTSTREAM);
    ECHO_OFF;
    return retval;
}
