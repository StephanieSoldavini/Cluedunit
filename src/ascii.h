#ifndef __ASCII_H__
#define __ASCII_H__

#include <stdio.h>
#include "location.h"
#include "player.h"

#define CURSOR_ON(stream) fprintf(stream, "\33[?25h")
#define CURSOR_OFF(stream) fprintf(stream, "\33[?25l")
#define ECHO_OFF system("/bin/stty raw -echo")
#define ECHO_ON system("/bin/stty cooked echo")


void printBoard(FILE *outStream, FILE *inFile);
void goTo(FILE *stream, int row, int col, int ascii);
void clearToEnd(FILE *stream);
void changeTextColor(FILE *stream, color fontColor);
direction inputToDirection(int c);
void goToHomeRow(FILE *stream);
void printToHomeRow(FILE *stream, const char *fmt, ...);
void printToTile(FILE *stream, int row, int col, const char *fmt, ...);

#endif /* __ASCII_H__ */
