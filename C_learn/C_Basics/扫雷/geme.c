#include "game.h"

void Initiate_Board(char board[ROWS][COLS], int rows, int cols, char qz)
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			board[i][j] = qz;		//初始化棋子
		}
	}
}
void Display_Board(char board[ROWS][COLS], int row, int col)
{
	//打印横坐标
	printf("  ");
	for(int i=1; i<=row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	//打印纵坐标和棋盘
	for(int i=1; i <= row; i++)
	{
		printf("%d ", i);
		for(int j=1; j <= col; j++)
		{
			printf("%c ", board[i][j]);	
		}
		printf("\n");
	}
}
void Setting_Lei(char Where[ROWS][COLS], int row, int col)
{
	//准备雷数
	int count = Lei_Munber;
	
	while(count)
	{
		//准备随机坐标
		int x = rand() % col + 1;
		int y = rand() % row + 1;
		
		if(Where[y][x] == '0')
		{
			Where[y][x] = '1';		//'1'为雷
			count--;
		}
	}
}
int get_lei_count(char Where[ROWS][COLS], int x, int y)
{
	return Where[y-1][x-1]+
		Where[y-1][x]+
		Where[y-1][x+1]+
		Where[y][x-1]+
		Where[y][x+1]+
		Where[y+1][x-1]+
		Where[y+1][x]+
		Where[y+1][x+1] - 8*'0';
}
void Find_Lei(char Where[ROWS][COLS], char Done[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int lei_count = 0;
	int win = 0;
	
	while(win < row*col - Lei_Munber)	//直到所有没雷的格子都被发现	
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if(x<0 || x>col || y<0 || y>row)	//非法输入
		{
			printf("该坐标不存在\n");
		}
		else								//合法输入
		{
			if(Where[y][x] == '1')			//1.踩雷
			{
				printf("不好意思，你被炸死了\n");
				break;
			}
			else							//2.没有踩雷
			{
				lei_count = get_lei_count(Where, x, y);
				Done[y][x] = lei_count + '0';					//附近雷的个数
				Display_Board(Done, row, col);			//展示Done
				win++;
			}
		}
	}
	if(win == row*col - Lei_Munber){
		printf("恭喜你，你胜利了！\n");
	}
}

