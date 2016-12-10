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

void printToTile(FILE *stream, int row, int col, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    goTo(stream, row, col, 0);
    vfprintf(stream, fmt, args);
    va_end(args);
}

int getDigit()
{
    int retval;
    int c = getchar();
    while (getchar() != '\n');
    retval = c - '0';
    return !(retval < 0 || retval > 9) ? retval : -1;
}


