#include <stdio.h>

/*
 * 探究：函数在定义或声明前被调用
 * （编译器：mingw64，操作系统：window11，编辑器：vscode）
 */

// 注：直接报错
// int main()
// {
//     double a = 1.1, b = 1.2;
//     // double add();
//     // double square();
//     printf("a + b == %f\n", add(a, b));
//     printf("a + b == %d\n", add(a, b));
//     printf("a * a == %f\n", square(a));
//     printf("b * b == %f\n", square(b));
//     return 0;
// }
// double add(double x, double y) { return x + y; }
// double square(double x) { return x * x; }

/*
 * 探究：函数声明省略参数
 */

// int main()
// {
//     int add();
//     int a = 5, b = 10;
//     printf("a + b == %d\n", add(a, b));
//     // printf("? + ? == %d\n", add()); // 结果未知

//     double square();
//     double c = 1.1;
//     printf("c * c == %.4f\n", square(c));
//     // printf("? * ? == %.4f\n", square()); // 结果为 0

//     return 0;
// }
// int add(int x, int y) { return x + y; }
// double square(double x) { return x * x; }
// // int add(short x, short y) { ... }
// // int add(char x, char y) { ... }
// // double square(float x) { ... }
// 带有 float、short 或者 char 参数的函数，声明时不能省略参数

/*
 * 探究早期函数定义形式
 */

// 还是能兼容的
// int Isdigit(ch)
// char ch;
// {
//     return ch == '0' || ch == '1' ||
//            ch == '2' || ch == '3' ||
//            ch == '4' || ch == '5' ||
//            ch == '6' || ch == '7' ||
//            ch == '8' || ch == '9';
// }
// int main()
// {
//     char ch = '9';
//     printf("%d\n", Isdigit(ch));
//     return 0;
// }

/*
 * 有关大小端的 bug
 */

// int main()
// {
//     int i;
//     char ch;
//     for (i = 0; i < 5; ++i)
//     {
//         scanf("%d", &ch);
//         printf("%d ", i);
//     }
//     return 0;
// }

/*
 * 检测外部类型
 */

extern int n;
// ./4_test_03_16(2).c 还有 long n;

int main()
{
    n = 1;
    printf("%d\n", n);
    return 0;
}