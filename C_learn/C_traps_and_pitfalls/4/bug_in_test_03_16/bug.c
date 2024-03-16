#include <stdio.h>

/*
 * 从 test_03_16 发现的一个 bug
 * （编译器：mingw64，操作系统：window11，编辑器：vscode）
 */

int main()
{
    double a = 1.1, square();

    printf("%.2f\n", square());
    // bug 出现，结果打印 1.21
    // 没有传参，但结果却是 a * a

    return 0;
}
double square(double x)
{
    return x * x;
}
