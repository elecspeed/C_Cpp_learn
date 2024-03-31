#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 虚拟的行和列
#define ROW_VIRTUAL 9
#define COL_VIRTUAL 9
// 实际的行和列
#define ROW_REAL ROW_VIRTUAL + 2
#define COL_REAL COL_VIRTUAL + 2
// 雷的数量
#define MINE 10

void InitBoard(char board[][COL_REAL], int row, int col, char symbol);

void DisplayBoard(char board[][COL_REAL], int row, int col);

void SetMine(char board[][COL_REAL], int row, int col, int mine);

void ClearMine(char front_board[][COL_REAL], char back_board[][COL_REAL],
               int row, int col);

#endif