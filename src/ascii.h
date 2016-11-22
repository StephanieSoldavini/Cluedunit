#include <stdio.h>

typedef enum {RED, GREEN, YELLOW, BLUE, PURPLE, WHITE} color;

void printBoard(FILE *outStream, FILE *inFile);
void goTo(FILE *stream, int row, int col, int ascii);
void clearToEnd(FILE *stream);
void changeTextColor(FILE *stream, color fontColor);

