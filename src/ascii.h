#ifndef __ASCII_H__
#define __ASCII_H__

#include <stdio.h>
#include "location.h"

typedef enum {RED, GREEN, YELLOW, BLUE, PURPLE, WHITE, DEFAULT} color;

void printBoard(FILE *outStream, FILE *inFile);
void goTo(FILE *stream, int row, int col, int ascii);
void clearToEnd(FILE *stream);
void changeTextColor(FILE *stream, color fontColor);
direction inputToDirection(int c);
void goToHomeRow(FILE *stream);
void printToHomeRow(FILE *stream, const char *fmt, ...);
void printToTile(FILE *stream, int row, int col, const char *fmt, ...);

#endif /* __ASCII_H__ */
