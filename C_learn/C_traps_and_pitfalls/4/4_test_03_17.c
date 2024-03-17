#include <stdio.h>

/*
 * 练习 4_1
 * 编写程序测试当前机器的字节序存储模式
 */

int CheckEndian()
{
    // 检测字节序函数。
    // 大端返回 0，小端返回 1
    int check_number = 1;
    return *(char *)(&check_number);
}
int main()
{
    int res = CheckEndian();
    if (res == 1)
    {
        printf("Little Endian.\n");
    }
    else
    {
        printf("Big Endian.\n");
    }
    return 0;
}