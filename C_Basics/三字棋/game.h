#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void Initiate_Board(char board[ROW][COL]);

void DisplayBord(char board[ROW][COL]);

void Player_Move(char board[ROW][COL]);

void Computer_Move(char board[ROW][COL]);

char Win(char board[ROW][COL]);

