//测试三字棋游戏
#include "game.h"

//游戏的逻辑
void game()
{
	//二维数组模拟棋盘，存放棋子
	char board[ROW][COL] = {0};
	//初始化棋盘
	Initiate_Board(board);
	//展示棋盘
	DisplayBord(board);
	//开始下棋
	while(1){
		//玩家下棋
		Player_Move(board);
		DisplayBord(board);
		if(Win(board) == '*'){
			printf("你赢了！");
			break;
		}
		//电脑下棋
		Computer_Move(board);
		DisplayBord(board);
		if(Win(board) == '#'){
			printf("电脑赢了！");
			break;
		}
		else if(Win(board) == 'Q')
		{
			printf("和棋。");
			break;
		}
	}
}
void menu()
{
	printf("*****************************\n");
	printf("****   1. play  0.exit   ****\n");
	printf("*****************************\n");
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
			printf("三字棋\n");
			game();
			break;
		case 0:
			printf("游戏结束\n");
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
