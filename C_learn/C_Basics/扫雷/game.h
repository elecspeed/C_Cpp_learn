#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2

#define Lei_Munber 80

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Initiate_Board(char board[ROWS][COLS], int rows, int cols, char qz);

void Display_Board(char board[ROWS][COLS], int rows, int cols);

void Setting_Lei(char Where[ROWS][COLS], int row, int col);

void Find_Lei(char Where[ROWS][COLS], char Done[ROWS][COLS], int row, int col);


