#include <stdio.h>
#include "ascii.h"

void printBoard(FILE *outStream, FILE *inFile)
{
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), inFile)) {
        fprintf(outStream, "%s", buffer);
    }
}

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

void clearToEnd(FILE *stream)
{
    fprintf(stream, "\33[J");
}

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

            


