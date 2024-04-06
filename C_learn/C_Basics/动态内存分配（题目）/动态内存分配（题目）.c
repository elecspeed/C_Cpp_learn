#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 下面的程序有什么问题
// void GetMemory(char *p)
// {
//     p = (char *)malloc(100);
// }
// void test()
// {
//     char *str = NULL;
//     GetMemory(str);
//     strcpy(str, "hello world");
//     printf(str);
// }
// int main()
// {
//     test();
//     return 0;
// }
// 函数内部动态开辟内存
// 改进
// void GetMemory(char **p)
// {
//     *p = (char *)malloc(100);
// }
// void FreeMemory(char **p)
// {
//     free(*p);
//     *p = NULL;
// }
// void test()
// {
//     char *str = NULL;
//     GetMemory(&str);
//     if (!str)
//         exit(-1);
//     strcpy(str, "hello world");
//     printf(str);
//     FreeMemory(&str);
// }
// int main()
// {
//     test();
//     return 0;
// }

// 下面的程序有什么问题
// char *Getmemory()
// {
//     char p[] = "hello world";
//     return p;
// }
// void test()
// {
//     char *str = NULL;
//     str = GetMemory();
//     printf(str);
// }
// int main()
// {
//     test();
//     return 0;
// }
// 函数调用返回栈空间的地址
// 改进（同上）

// 下面的程序有什么问题
// void GetMemory(char **p, int num)
// {
//     *p = (char *)malloc(num);
// }
// void test()
// {
//     char *str = NULL;
//     GetMemory(&str, 100);
//     strcpy(str, "hello world");
//     printf(str);
// }
// int main()
// {
//     test();
//     return 0;
// }
// 改进（同上）

// 下面的程序有什么问题
// void test()
// {
//     char *str = (char *)malloc(100);
//     strcpy(str, "hello");
//     free(str);
//     if (str != NULL)
//     {
//         strcpy(str, "world");
//         printf(str);
//     }
// }
// int main()
// {
//     test();
//     return 0;
// }