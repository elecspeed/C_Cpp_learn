#include "game.h"

// 剩下的格子数，用来判断是否胜利
int remaining_blank = ROW_VIRTUAL * COL_VIRTUAL - MINE;

static void
CountMine(char front_board[][COL_REAL], char back_board[][COL_REAL],
		  int row, int col, int x, int y)
{
	// 递归终止
	if (x < 1 || x > row || y < 1 || y > col ||
		back_board[x][y] != '.')
		return;

	// 数周围有几颗雷
	int count = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (back_board[x - 1 + i][y - 1 + j] == '#')
				++count;
	--remaining_blank;
	if (count == 0)
	{
		front_board[x][y] = '-';
		back_board[x][y] = '-';
		// 空格，递归接着数雷
		// 左上角递归
		CountMine(front_board, back_board,
				  row, col, x - 1, y - 1);
		// 右边递归
		CountMine(front_board, back_board,
				  row, col, x, y + 1);
		// 下边递归
		CountMine(front_board, back_board,
				  row, col, x - 1, y);
	}
	else
		front_board[x][y] = '0' + count;
}
void InitBoard(char board[][COL_REAL], int row, int col, char symbol)
{
	// 用 symbol 初始化棋盘
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			board[i][j] = symbol;
}
void DisplayBoard(char board[][COL_REAL], int row, int col)
{
	// 打印棋盘
	putchar(' ');
	for (int i = 1; i < row - 1; ++i)
		printf(" %d", i);
	printf(" x\n");
	for (int i = 1; i < row - 1; ++i)
	{
		printf("%d", i);
		for (int j = 1; j < col - 1; ++j)
			printf(" %c", board[i][j]);
		putchar('\n');
	}
	printf("y\n");
}
void MakeMine(char board[][COL_REAL], int row, int col)
{
	// 随机生雷
	int random_x, random_y, mine;
	random_x = random_y = mine = 0;
	while (mine < MINE)
	{
		random_x = rand() % 9 + 1;
		random_y = rand() % 9 + 1;
		if (board[random_x][random_y] != '#')
		{
			board[random_x][random_y] = '#';
			++mine;
		}
	}
}
int ClearMine(char front_board[][COL_REAL], char back_board[][COL_REAL],
			  int row, int col)
{
	// 玩家排雷。如果踩雷返回 1，否则返回 0
	int x, y;
	x = y = 0;
	printf("Enter the index like x,y :");
	scanf("%d,%d", &y, &x);

	if (x < 1 || x > ROW_VIRTUAL ||
		y < 1 || y > COL_VIRTUAL)
		/* 处理非法输入 */
		printf("Illegal index.Please enter again.\n");
	else if (back_board[x][y] == '#')
		/* 踩雷了 */
		return 1;
	else
	{
		// 数周围有几颗雷
		CountMine(front_board, back_board,
				  row, col, x, y);
	}
}