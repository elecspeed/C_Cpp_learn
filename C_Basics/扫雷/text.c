#include "game.h"

void game()
{
	//存储雷的信息
	//1.存雷的位置
	//2.存排查出的位置
	char Where[ROWS][COLS] = {0};
	char Done[ROWS][COLS] = {0};
	//初始化
	Initiate_Board(Where, ROWS, COLS, '0');
	Initiate_Board(Done, ROWS, COLS, '*');
	//展示棋盘
	//Display_Board(Where, ROW, COL);
	Display_Board(Done, ROW, COL);
	//布置雷
	Setting_Lei(Where, ROW, COL);
	Display_Board(Where, ROW, COL);
	//扫雷
	Find_Lei(Where, Done, ROW, COL);
	Display_Board(Where, ROW, COL);
	
}
void menu()
{
	printf("**************************\n");
	printf("****  1.play  0.exit  ****\n");
	printf("**************************\n");
}
void text()
{
	int input = 0;
	srand((unsigned)time(NULL));
	
	do{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			printf("没有该选项，请重新选择！\n");
			break;
		}
	}
	while(input);
}
int main()
{
	text();
	return 0;
}
