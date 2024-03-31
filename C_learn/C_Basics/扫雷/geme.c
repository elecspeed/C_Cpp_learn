#include "game.h"

// 剩下的格子数，用来判断是否胜利
static int remaining_blank = ROW_VIRTUAL * COL_VIRTUAL - MINE;

static void
CountMine(char front_board[][COL_REAL], char back_board[][COL_REAL],
          int row, int col, int x, int y)
{
    // 递归终止
    if (x < 1 || x > row - 2 || y < 1 || y > col - 2 ||
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
        front_board[x][y] = back_board[x][y] = ' ';
        // 空格，递归接着数雷
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                CountMine(front_board, back_board,
                          row, col, x - 1 + i, y - 1 + j);
    }
    else
        back_board[x][y] = front_board[x][y] = '0' + count;
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
void SetMine(char board[][COL_REAL], int row, int col, int mine)
{
    // 随机生雷
    int random_x, random_y;
    random_x = random_y = 0;
    while (mine > 0)
    {
        random_x = rand() % (row - 2) + 1;
        random_y = rand() % (col - 2) + 1;
        if (board[random_x][random_y] != '#')
        {
            board[random_x][random_y] = '#';
            --mine;
        }
    }
}
void ClearMine(char front_board[][COL_REAL], char back_board[][COL_REAL],
               int row, int col)
{
    // 玩家排雷。
    printf("There are %d mines in total.\n", MINE);
    int x, y;
    x = y = 0;
    while (remaining_blank > 0)
    {
        // 游戏的核心部分：游戏过程、判断输赢
        // 玩家输入
        printf("Enter the index like x,y :");
        scanf("%d,%d", &y, &x);
        while (x < 1 || x > row - 2 || y < 1 || y > col - 2 ||
               front_board[x][y] != '*')
        {
            /* 处理非法输入 */
            printf("-----------------------------------------\n"
                   "Illegal index.\n"
                   "Please enter again.\n");
            printf("Enter the index like x,y :");
            scanf("%d,%d", &y, &x);
        }
        // 判断是否触雷
        if (back_board[x][y] == '#')
        {
            // 踩雷了
            // 先与用户交互，再把雷的分布展示出来
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                   "Oh,\n"
                   "it seems that you triggered a mine.\n"
                   "Don't be sad,\n"
                   "you can try it again.\n");
            DisplayBoard(back_board, ROW_REAL, COL_REAL);
            return;
        }
        else
        {
            // 没踩雷
            // 数周围有几颗雷
            CountMine(front_board, back_board, row, col, x, y);
            DisplayBoard(front_board, ROW_REAL, COL_REAL);
        }
    }
    printf("*****************************************\n"
           "          Congratulations!\n");
}