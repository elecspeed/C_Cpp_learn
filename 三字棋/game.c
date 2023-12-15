#include "game.h"

void Initiate_Board(char board[ROW][COL])
{
	for(int i=0; i<ROW; i++)
	{
		for(int j=0; j<COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBord(char board[ROW][COL])
{
	for(int i = 0; i<ROW; i++)
	{
		for(int j=0; j<COL; j++)
		{
			printf(" %c ", board[i][j]);
			if(j < COL-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if(i < ROW-1)
		{
			for(int j=0; j<COL; j++)
			{
				printf("---");
				if(j < COL-1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void Player_Move(char board[ROW][COL])
{
	int x, y;
	x = y = 0;
	printf("玩家走\n");
	while(1){
		printf("请输入格子的坐标（范围：x--1~3，y--1~3）：");
		scanf("%d%d", &x, &y);
		
		//判断坐标合法性
		if(x<1 || x>COL || y<1 || y>ROW)
		{
			printf("坐标不对\n");
		}
		else
		{
			if(board[x-1][y-1] != ' ')
			{
				printf("该格子已经有棋\n");
			}
			else
			{
				board[x-1][y-1] = '*';
				break;
			}
		}
	}
	
}
void Computer_Move(char board[ROW][COL])
{
	int x = 0, y = 0;
	
	printf("电脑走\n");
	
	while(1){
		
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if(board[x-1][y-1] == ' ')
		{
			board[x-1][y-1] = '#';
			break;
		}
	}
}
//返回*玩家赢，返回#电脑赢，返回Q和棋，返回C继续
char Win(char board[ROW][COL])
{
	//横三列
	for(int i=0; i<ROW; i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] ==board [i][2])
		{
			return board[i][0];
		}
	}
	//竖三列
	for(int i=0; i<COL; i++)
	{
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			return board[0][i];
		}
	}
	//对角线
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[0][0];
	}
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return board[2][0];
	}
	//和棋
	for(int i=0; i<ROW; i++)
	{
		for(int j=0; j<COL; j++)
		{
			if(board[i][j] == ' ')
			{
				return 'C';
			}
		}
	}
	return 'Q';
}
