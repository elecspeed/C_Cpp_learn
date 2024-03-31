#include "game.h"

void game()
{
    // 游戏的逻辑
    // 创建棋盘
    // front_board：棋盘前端，存储未知格子和数字；
    // back_board：棋盘后端，存储随机地雷。
    char front_board[ROW_REAL][COL_REAL];
    char back_board[ROW_REAL][COL_REAL];

    InitBoard(front_board, ROW_REAL, COL_REAL, '*');
    InitBoard(back_board, ROW_REAL, COL_REAL, '.');
    DisplayBoard(front_board, ROW_REAL, COL_REAL);
    // DisplayBoard(back_board, ROW_REAL, COL_REAL);
    SetMine(back_board, ROW_REAL, COL_REAL, MINE);
    // DisplayBoard(back_board, ROW_REAL, COL_REAL);
    ClearMine(front_board, back_board, ROW_REAL, COL_REAL);
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
        scanf("%d", &input);
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