#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 虚拟的行和列
#define ROW_VIRTUAL 9
#define COL_VIRTUAL 9
// 真实的行和列
#define ROW_REAL ROW_VIRTUAL + 2
#define COL_REAL COL_VIRTUAL + 2
// 雷的数量
#define MINE 10

// 剩下的格子数，用来判断是否胜利
extern int remaining_blank;

void InitBoard(char board[][COL_REAL], int row, int col, char symbol);

void DisplayBoard(char board[][COL_REAL], int row, int col);

void MakeMine(char board[][COL_REAL], int row, int col);

int ClearMine(char front_board[][COL_REAL], char back_board[][COL_REAL],
              int row, int col);

#endif
