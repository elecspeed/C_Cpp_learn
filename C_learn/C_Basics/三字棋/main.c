#include "game.h"

void game()
{
	// 游戏的逻辑
	// 创建棋盘
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		UserPlay(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (Check_Win_or_Loss(board, ROW, COL) == '*')
		{
			printf("You win!\n");
			return;
		}
		else if (Check_Win_or_Loss(board, ROW, COL) == 'q')
		{
			printf("Stalemate.\n");
			return;
		}
		ComputerPlay(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (Check_Win_or_Loss(board, ROW, COL) == '#')
		{
			printf("Computer win!\n");
			return;
		}
	}
}
void menu()
{
	printf("********************************\n");
	printf("******  0. exit   1.play  ******\n");
	printf("********************************\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("Enter your choise:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
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
	test();
	return 0;
}