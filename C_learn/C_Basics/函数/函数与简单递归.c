#include <stdio.h>

// 练习：两道经典递归迭代题
// 汉诺塔问题
// 青蛙跳台阶问题

// 汉诺塔
// 递归实现
// void move(char x, char y)
// {
//     printf("%c -> %c ", x, y);
// }
// void hanoi(int n, char a, char b, char c) // 妙用参数改变柱子顺序
// {
//     if (n == 1)
//         move(a, c); // 将打印细节交给move实现
//     else
//     {
//         hanoi(n - 1, a, c, b); // 将a上的n-1个盘子通过c移到b
//         move(a, c);            // 把最底下的盘子从a移到c
//         hanoi(n - 1, b, a, c); // 将b上的n-1个盘子通过a移到c
//     }
// }
// void picture(int n)
// {
//     for (int i = 0; i < 3; ++i)
//         printf("*\t\t\t*\t\t\t*\n");
//     for (int i = 0; i < n; ++i)
//     {
//         putchar('*');
//         for (int j = 0; j <= i; ++j)
//             putchar('-');
//         printf("\t\t\t*\t\t\t*\n");
//     }
//     printf("A\t\t\tB\t\t\tC\n\n");
//     printf("三根柱子。A 柱从大到小摞着 %d 片圆盘。\n"
//            "现在，要把所有圆盘挪到 C 柱上。\n"
//            "规定：\n"
//            "1.在三根柱子之间一次只能移动一个盘；\n"
//            "2.无论什么时候，小盘上都不能放大盘；\n"
//            "3.完成后，盘的顺序和原来一样。\n",
//            n);
//     printf("实现顺序：\n");
// }
// int main()
// {
//     int n = 0;
//     printf("请输入盘子的数量：");
//     scanf("%d", &n);
//     picture(n);
//     hanoi(n, 'A', 'B', 'C');
//     return 0;
// }
// 设计递归函数
// 1.递归以函数为载体来实现，使用递归要考虑函数要素。
//   比如：参数个数、类型，函数返回类型等。
// 2.明确递归的核心算法，其他的细节可由其他函数实现。
// 3.设计时了解大致递归过程即可，不要纠缠细节。
//   关键要看，大问题层层转化为小问题的逻辑，
//   是否符合数学归纳法。
//   如果符合数学归纳法，递归过程一定可以实现。

// 递归与迭代
// （迭代一般指的是循环）
//
// 相关的数据结构
// 递归--栈，迭代--队列。
// 理论上递归都能用迭代实现，而迭代不一定可以转化为递归

// 求斐波那契数列第 n 项
// (思想：用三个变量存相邻三项，迭代)
// int Fib(int n)
// {
//     int a, b, c;
//     a = b = c = 1;
//     // 用 while 迭代，也可以用 for
//     while (n > 2)
//     {
//         c = a + b;
//         a = b;
//         b = c;
//         n--;
//     }
//     return c;
// }

// 递归
// 程序直接或间接调用自身的编程技巧，称为递归。
// 核心：把大规模复杂问题层层化为与原问题相似的小规模问题，
//      每层转化过程相同，直到我们设置的停止条件。
// 1.停止条件
// 2.每次递归后要接近停止条件
// 注意：大量递归可能会栈溢出（stack overflow）
//
// 递归的本质：数学归纳法
//
// 正确递归的实现过程：
// 递归前的语句，从外层递归向内层递归执行 n 次，（递，压栈）
// 递归后的语句，从内层递归向外层递归执行 n 次。（归，出栈）

// 内存空间分类
// 栈区：局部变量，函数形参等等
// 堆区：动态开辟的内存（malloc, free 等函数）
// 静态区：全局变量，静态变量

// 手搓 strlen
// 方法 1：计数器
// 方法 2：指针 - 指针
// 方法 3：不创建变量的方式
// 递归实现
// int my_strlen(char *a)
// {
//     if (*a == '\0')
//         return 0;
//     return 1 + my_strlen(a + 1);
// }
// int main()
// {
//     char arr[] = "hhh";
//     // int len = strlen(arr);
//     int len = my_strlen(arr);
//     printf("len = %d\n", len);
//     return 0;
// }

// 递归顺序打印无符号整型每位上的数字
// void print(int n)
// {
//     if (n > 9)
//         print(n / 10);
//     printf("%d ", n % 10);
// }
// int main()
// {
//     unsigned int num = 0;
//     scanf("%u", &num);
//     print(num);
//     return 0;
// }

// main 函数调用自己
// int main()
// {
//     printf("hhh ");
//     main();
//     return 0;
// }

// 函数声明的正确用法
// #include "add.h"
// 把函数声明放进头文件，函数定义放进同路径文件
//
// 意义：增加开发速度（一个源文件不能被多人同时编写），
//      功能模块化，
//      封装功能实现过程，
//      隐藏不必要的细节
//
// 函数定义和函数使用在同一个源文件的，
// 一般不需要函数声明

// #include "add.h"
// int main()
// {
//     int a = 10, b = 20;
//     int sum = Add(a, b);
//     printf("%d", sum);
//     return 0;
// }

// 函数的链式访问
// 把一个函数的返回值作为另一个函数的参数
// int main()
// {
//     // 提醒：printf 返回打印字符的个数
//     printf("%d", printf("%d", printf("%d", 43)));
//     return 0;
// }

// 自增函数
// void Add(int *p)
// {
//     // *p++;
//     // ++优先级比*高；
//     (*p)++;
// }
// int main()
// {
//     int num = 0;
//     Add(&num);
//     printf("num = %d\n", num);
//     Add(&num);
//     printf("num = %d\n", num);
//     return 0;
// }

// 手搓二分查找函数
// int binary_search(int *arr, int arr_len, int to_find)
// {
//     // 二分查找函数。找到返回下标，否则返回 -1
//     int left = 0;
//     int right = arr_len - 1;
//     // int right = sizeof(arr)/sizeof(arr[0]) - 1;
//     // 数组在传参时发生类型退化，退化为首元素地址
//     // （为了节省空间）
//     // 函数内部想使用数组长度，要在函数外传进去
//     // （字符串除外）
//
//     while (left <= right)
//     {
//         int mid = (left + right) / 2;
//         if (arr[mid] == to_find)
//             return mid;
//         else if (arr[mid] < to_find)
//             left = mid + 1;
//         else
//             right = mid - 1;
//     }
//     return -1; // 没有找到返回-1
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int input = 0;
//     printf("Enter the number to find:");
//     scanf("%d", &input);
//
//     int arr_len = sizeof(arr) / sizeof(arr[0]);
//     int index = binary_search(arr, arr_len, input);
//     if (index == -1)
//         printf("%d does not exist.\n", input);
//     else
//         printf("%d exists, its index is %d.\n", input, index);
//     return 0;
// }

// 打印素数
// #include <math.h>
// int is_prime(int a)
// {
//     // 判断素数函数，是返回 1，不是返回 0
//     if (a == 2)
//         return 1;
//     if (a < 2 || (a & 1) == 0)
//         return 0;
//     for (int i = 3; i <= sqrt(a); i += 2)
//         if (a % i == 0)
//             return 0;
//     return 1;
// }
// int main(void)
// {
//     for (int i = 1; i < 200; i++)
//         if (is_prime(i))
//             printf("%d ", i);
//     return 0;
// }
