#include "game.h"

void game()
{
	// 游戏的逻辑
	// 创建棋盘
	// front_board：前端棋盘，存储未知格子和数字；
	// back_board：后端棋盘，存储随机地雷。
	char front_board[ROW_REAL][COL_REAL];
	char back_board[ROW_REAL][COL_REAL];
	// 初始化棋盘
	InitBoard(front_board, ROW_REAL, COL_REAL, '*');
	InitBoard(back_board, ROW_REAL, COL_REAL, '.');
	// 打印棋盘
	DisplayBoard(front_board, ROW_REAL, COL_REAL);
	// DisplayBoard(back_board, ROW_REAL, COL_REAL);
	// 随机生雷
	MakeMine(back_board, ROW_REAL, COL_REAL);
	DisplayBoard(back_board, ROW_REAL, COL_REAL);
	// 玩家排雷
	int ret = 0;
	while (remaining_blank > 0)
	{
		ret = ClearMine(back_board, front_board, ROW_REAL, COL_REAL);
		if (ret == 1)
		{
			// 踩雷了
			// 先与用户交互，再把雷的分布展示出来
			printf("Oh,it seems that you triggered a mine.\n"
				   "Don't be sad, you can try it again.\n");
			for (int i = 1; i < ROW_REAL - 1; ++i)
				for (int j = 1; j < COL_REAL - 1; ++j)
					if (back_board[i][j] == '#')
						front_board[i][j] = '#';
			DisplayBoard(front_board, ROW_REAL, COL_REAL);
			return;
		}
		DisplayBoard(back_board, ROW_REAL, COL_REAL);
	}
}
void menu()
{
	printf("*******************************\n");
	printf("******  1.play   0.exit  ******\n");
	printf("*******************************\n");
}
void test1()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("Enter your choise:");
		scanf("%x", &input);
		switch (input)
		{
		case 1:
			printf("Welcome to minesweeper!\n");
			game();
			break;
		case 0:
			printf("Game out.\n");
			break;
		default:
			printf("The choise does not exist!\n");
			break;
		}
	} while (input);
}
int main()
{
	test1();
	return 0;
}