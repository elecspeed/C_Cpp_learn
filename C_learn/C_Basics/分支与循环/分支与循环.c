#include <stdio.h>

// 关机程序
// #include <stdlib.h>
// #include <string.h>
// int main(void)
// {
//     char input[20] = {0};
//     system("shutdown -s -t 60");
//     // system 函数，执行系统命令，stdlib 库。
//     // shutdown -s -t 60：win 系统命令，表示 60 秒后关机。
//     // 可以在 win 命令行下试试（坏笑）。

// again:
//     printf("请注意！！！\n"
//            "你的电脑将在 1 分钟内关机。如果输入：我是猪，就取消关机\n"
//            "请输入：\n");
//     scanf("%s", input);
//     if (strcmp(input, "我是猪") == 0) // strcmp，字符串比较函数，string 库
//         system("shutdown -a");
//     else
//         goto again;
//     return 0;
// }

// goto：用于一步跳出多重循环，除此之外少用。

/*
 * 生成随机数
 *
 * 伪随机数是由随机种子根据一定的算法计算出来的数值，
 * 算法一定，随机种子一定，产生的随机数就是固定的。
 * 因此称为“伪”随机数。
 *
 * srand 函数，设置随机起始点（即随机种子）
 * void srand(unsigned int seed);
 *
 * rand 函数，返回 0~RAND_MAX 以内的伪随机数
 * （RAND_MAX 的值为 32767）
 * int rand(void);
 *
 * srand 函数给 rand 函数设置随机种子（本质是静态变量）。
 * 如果在 srand 前调用 rand，则默认 srand(1)。
 * 随机种子由程序员自己设定，
 * 随机算法则由库文件写好，直接使用。
 * 前面提到，
 * 算法一定，随机种子一定，产生的随机数就是固定的。
 * 没错，保持随机种子不变，
 * 每次编译后得到的随机数也保持不变。
 * 怎么办？
 * 拿时间差来设置随机种子。
 * 时间差 == 当前计算机的时间 - 计算机的起始时间(1979.1.1.0:0:0)
 * 单位是秒。
 *
 * time 函数，返回时间差，同时将时间差赋给 *timer。
 * （timer 可以是 NULL）
 * time_t time(time_t* timer)
 */

// 探究随机数、随机种子、时间差
// #include <stdlib.h>
// #include <windows.h>
// #include <time.h>
// int main()
// {
//     // srand(0);
//     while (1)
//     {
//         printf("%d ", rand());
//         Sleep(250);
//     }
//
//     time_t timer = 0;
//     while (1)
//     {
//         time(&timer);
//         printf("%d\n", timer);
//         Sleep(250);
//     }
//     return 0;
// }

// 猜数字游戏
// 1.生成一个随机数
// 2.猜数字
// #include <stdlib.h>
// #include <time.h>
// void game()
// {
//     // 1.生成一个随机数
//     int ret = 0;
//     ret = rand() % 100; // 生成 0~99 以内的随机数
//     // printf("%d\n", ret);
//
//     // 2.猜数字
//     while (1)
//     {
//         int guess = 0;
//         printf("请猜数字：");
//         scanf("%d", &guess);
//
//         if (guess > ret)
//             printf("猜大了\n");
//         else if (guess < ret)
//             printf("猜小了\n");
//         else
//         {
//             printf("恭喜你，猜中了\n");
//             break;
//         }
//     }
// }
// void menu()
// {
//     printf("*************************************\n");
//     printf("********   1.play   0.exit   ********\n");
//     printf("*************************************\n");
// }
// int main(void)
// {
//     int input = 0;
//     srand((unsigned int)time(NULL));
//     do
//     {
//         menu();
//         printf("请选择：");
//         scanf("%d", &input);
//         switch (input)
//         {
//         case 1:
//             game();
//             break;
//         case 0:
//             printf("游戏退出\n");
//             break;
//         default:
//             printf("选择错误\n");
//             break;
//         }
//     } while (input);
//     return 0;
// }

// 打印乘法口诀表
// int main(void)
// {
//     int i = 0;
//     for (i = 1; i <= 9; i++)
//     {
//         int j = 0;
//         for (j = 1; j <= i; j++)
//             printf("%d*%d=%-2d ", i, j, i * j); // -2：左对齐
//         printf("\n");
//     }
//     return 0;
// }

// 100 以内数字 4 出现的次数
// int main(void)
// {
//     int count = 0;
//     for (int i = 1; i < 100; i++)
//     {
//         if (i % 10 == 4)
//             count++;
//         if (i / 10 == 4)
//             count++;
//     }
//     printf("%d\n", count);
//     return 0;
// }

// 找最大公约数
// int main(void)
// {
//     int m, n, r;
//     scanf("%d%d", &m, &n);
//     while (r = m % n)
//     {
//         m = n;
//         n = r;
//     }
//     printf("最大公约数是：%d", n);
//     return 0;
// }

// 输入密码
// #include <string.h>
// int main(void)
// {
//     char Password[20] = {0};
//     for (int i = 0; i < 3; i++)
//     {
//         printf("请输入密码:");
//         scanf("%s", &Password);
//
//         // if (Password == "123456") // 错误。
//         if (strcmp(Password, "123456") == 0)
//         {
//             printf("密码正确\n");
//             break;
//         }
//         if (i == 2)
//             printf("密码锁定");
//         else
//             printf("密码错误，还有 %d 次机会\n", 2 - i);
//     }
//     return 0;
// }

// 输出延迟和清屏的效果
// #include <windows.h>
// #include <stdlib.h>
// int main(void)
// {
//     char A[] = "Welcome to NUJPT!!!!";
//     char B[] = "####################";
//
//     int left = 0;
//     // int right = sizeof(A) / sizeof(A[0]) - 2;
//     int right = strlen(A) - 1;
//
//     while (left <= right)
//     {
//         system("cls"); // system，执行系统命令的函数，stdlib 库
//         B[left] = A[left];
//         B[right] = A[right];
//         printf("%s\n", B);
//         Sleep(1000); // 延迟 1 秒，window 库
//         ++left;
//         --right;
//     }
//     // system("pause");
//     return 0;
// }

// 二分查找
// int main(void)
// {
//     int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 有序数列
//     int k;                                     // 要找的数
//     int left = 0;                              // 左下标
//     int right = sizeof(A) / sizeof(A[0]) - 1;  // 右下标
//     int mid;                                   // 中间下标
//
//     scanf("%d", &k);
//     while (left <= right)
//     {
//         mid = (left + right) / 2;
//         if (k < A[mid])
//             right = mid - 1;
//         else if (k > A[mid])
//             left = mid + 1;
//         else
//         {
//             printf("找到了，下标是%d\n", mid);
//             break;
//         }
//     }
//     if (left > right)
//         printf("不存在\n");
//     return 0;
// }

/*
 * 分支与循环
 *
 * 关键字
 * if, switch, for, while, do...while, continue, break
 */

// int main(void)
// {
//     char str[100] = {0};
//     char ch;
//     int i = 0;
//     while ((ch = getchar()) != '\n')
//     {
//         // 从标准输入中的一行读取字符，只写入数字
//         if (ch > '9' || ch < '0')
//             continue;
//         str[i] = ch;
//         i++;
//     }
//     printf("%s", str);
//
//     // 从标准输入读取，写入标准输出。
//     while ((ch = getchar()) != EOF)
//         putchar(ch);
//     // windows 下，标准输入的 ctrl+z 相当于 EOF。
//     // EOF 即 end of file, 值为 -1。
//     return 0;
// }

/*
 * 良好的代码风格
 * 缓冲区以及三种输入方式 gets, scanf, getchar，常见的代码如上。
 * 建议：尽量不在 for 内部改变循环控制变量，防止失去控制。
 * for(;;) 无限循环。
 * for 可以有两个循环控制变量。
 * do...while 相当于至少执行一次的 while
 */
