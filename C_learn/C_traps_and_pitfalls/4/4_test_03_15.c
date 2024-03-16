#include <stdio.h>

/*
 * 全局变量（或外部变量）的声明与定义
 * （编译器：mingw64，操作系统：window11，编辑器：vscode）
 */

int a;
// a = 0;
// 警告。不能在所有函数外部赋值

int b;
int b;
int c;
int c;
int c = 1;
// 允许重复定义，但至多只能有一个初始化

extern int d;
// extern 表明 d 定义在别处。一定要有 d 的定义！
// 在当前环境下，如果 d 未定义，则程序生成失败，且检测不到错误
// 在链接部分出现的错误往往检测不到！

int main()
{
    printf("a == %d\n", a);
    printf("b == %d\n", b);
    printf("c == %d\n", c);
    printf("d == %d\n", d);
    ++d;
    printf("d == %d\n", d);
    return 0;
}