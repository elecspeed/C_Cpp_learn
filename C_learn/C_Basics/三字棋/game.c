#include "game.h"

void InitBoard(char board[][COL], int row, int col)
{
	// 初始化棋盘
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			board[i][j] = ' ';
}
void DisplayBoard(char board[][COL], int row, int col)
{
	// 打印棋盘
	printf("  x 1   2   3  \n");
	printf("y |---|---|---|\n");
	for (int i = 0; i < row; ++i)
	{
		printf("%d |", i + 1);
		for (int j = 0; j < col; ++j)
			printf(" %c |", board[i][j]);
		printf("\n  |---|---|---|\n");
	}
}
void UserPlay(char board[][COL], int row, int col)
{
	// 用户走棋
	// 关键是处理输入
	int x, y;
	x = y = 0;
	printf("It is your turn.\n"
		   "Enter the index like x,y :");
	while (1)
	{
		scanf("%d,%d", &y, &x);
		if (x < 1 || x > row || y < 1 || y > col)
			printf("Illegal index.Please enter again:");
		else if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
			return;
		}
		else
			printf("The place is already full.\n"
				   "Please enter again:");
	}
}
void ComputerPlay(char board[][COL], int row, int col)
{
	// 电脑走棋
	// 关键是确保随机性
	printf("Computer is thinking...\n");
	int random_x, random_y;
	while (1)
	{
		random_x = rand() % row;
		random_y = rand() % col;
		// printf("%d,%d\n", random_x, random_y);
		if (board[random_x][random_y] == ' ')
		{
			board[random_x][random_y] = '#';
			return;
		}
	}
}
char Check_Win_or_Loss(char board[][COL], int row, int col)
{
	// 检查输赢的函数。
	// 返回'*'：用户赢；
	// 返回'#'：电脑赢；
	// 返回'c'：继续；
	// 返回'q'：和棋

	// 先检查有无输赢
	// 横竖检查
	for (int i = 0; i < row; ++i)
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][1];
	for (int i = 0; i < col; ++i)
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[1][i];
	// 对角线检查
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
		board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[1][1];

	// 再检查是否和棋
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (board[i][j] == ' ')
				return 'c';
	return 'q';
}
