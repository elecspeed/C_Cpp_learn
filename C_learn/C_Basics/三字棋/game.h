#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void InitBoard(char board[][COL], int row, int col);
void DisplayBoard(char board[][COL], int row, int col);
void UserPlay(char board[][COL], int row, int col);
void ComputerPlay(char board[][COL], int row, int col);
char Check_Win_or_Loss(char board[][COL], int row, int col);

#endif