#ifndef __ASCII_H__
#define __ASCII_H__

#include <stdio.h>
#include <stdlib.h>
#include "location.h"
#include "player.h"

#define CURSOR_ON(stream) fprintf(stream, "\33[?25h")
#define CURSOR_OFF(stream) fprintf(stream, "\33[?25l")
#define ECHO_OFF system("/bin/stty raw -echo")
#define ECHO_ON system("/bin/stty cooked echo")
#define BACKSPACE 127

#define OUTSTREAM stdout
#define INSTREAM stdin


void printBoard(FILE *outStream, FILE *inFile);
void goTo(FILE *stream, int row, int col, int ascii);
void clearToEnd(FILE *stream);
void changeTextColor(FILE *stream, color fontColor);
direction inputToDirection(int c);
void goToHomeRow(FILE *stream);
void printToHomeRow(FILE *stream, const char *fmt, ...);
int getDigit();
void printToTile(FILE *stream, color fontColor, int row, int col, const char *fmt, ...);
void takeTurn(player *movingPlayer);
void placePlayers(player *newPlayer);
int getPlayerInput();
void printHeldCards(player *thePlayer, int numCardsEach);

#endif /* __ASCII_H__ */
