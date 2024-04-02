#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

// int main()
// {
//     // 下面的程序运行结果是什么
//     int a[] = {1, 2, 3, 4};
//     printf("%zd\n", sizeof(a));     // 16
//     printf("%zd\n", sizeof(a + 0)); // 4/8
//     printf("%zd\n", sizeof(*&a));   // 16
//     printf("%zd\n", sizeof(&*a));   // 4/8
//
//     char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
//     printf("%zd\n", sizeof(arr));     // 6
//     printf("%zd\n", sizeof(arr + 0)); // 4/8
//     printf("%zd\n", sizeof(*arr));    // 1
//     printf("%zd\n", sizeof(&arr));    // 4/8
//     printf("%d\n", strlen(arr));      // 随机值 M
//     printf("%d\n", strlen(*arr));     // error
//     printf("%d\n", strlen(&arr));     // 随机值 M
//     printf("%d\n", strlen(&arr + 1)); // 随机值 N，N + 6 == M
//
//     // 如果换成char arr[] = "abcdef"; 呢？
//     // 或者 char* p = "abcdef"; 呢？
//
//     int b[3][4] = {0};
//     printf("%zd\n", sizeof(b));            // 48
//     printf("%zd\n", sizeof(b[0]));         // 16
//     printf("%zd\n", sizeof(b[0] + 1));     // 4/8，[0][1]的地址
//     printf("%zd\n", sizeof(*(b[0] + 1)));  // 4
//     printf("%zd\n", sizeof(b + 1));        // 4/8，第二行的地址
//     printf("%zd\n", sizeof(*(b + 1)));     // 16
//     printf("%zd\n", sizeof(*b));           // 16
//     printf("%zd\n", sizeof(*(&b[0] + 1))); // 16
//     printf("%zd\n", sizeof(b[3]));         // 16
//     return 0;
// }

// 程序运行结果是什么
// int main()
// {
//     int a[5] = {1, 2, 3, 4, 5};
//     int *ptr = (int *)(&a + 1);
//     printf("%d,%d\n", *(a + 1), *(ptr - 1)); // 2,5
//     return 0;
// }

// 程序运行结果是什么
// 注：Test 类型的大小为 32 字节
// struct Test
// {
//     int Num;
//     char *pcName;
//     short sDate;
//     char arr[6];
//     short sCh[2];
// } *p;
// int main()
// {
//     p = (struct Test *)0x100000;
//     printf("%p\n", p + 0x1);                 // 0x100020
//     printf("%p\n", (unsigned int *)p + 0x1); // 0x100004
//     printf("%p\n", (unsigned long)p + 0x1);  // 0x100001
//     return 0;
// }

// 程序运行结果是什么
// int main()
// {
//     int a[4] = {1, 2, 3, 4};
//     int *ptr1 = (int *)(&a + 1);
//     int *ptr2 = (int *)((unsigned long)a + 1);
//     printf("%#x,%#x\n", ptr1[-1], *ptr2);
//     // 0x4, 0x20000000（小端）或 0x100（大端）
//     return 0;
// }

// 程序运行结果是什么
// int main()
// {
//     int a[3][2] = {(0, 1), (2, 3), (4, 5)};
//     int *p = a[0];
//     p = a[0];
//     printf("%d\n", p[0]); // 1
//     return 0;
// }

// 程序运行结果是什么
// int main()
// {
//     int a[5][5];
//     int(*p)[4];
//     p = (int(*)[4])a;
//     printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//     // FF FF FF FC, -4
//     return 0;
// }

// 程序运行结果是什么
// int main()
// {
//     int aa[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int *ptr1 = (int *)(&aa + 1);
//     int *ptr2 = (int *)(*(aa + 1));
//     printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1)); // 10, 5
//     return 0;
// }

// 程序运行结果是什么
// int main()
// {
//     char *a[] = {"work", "at", "alibaba"};
//     char **pa = a;
//     pa++;
//     printf("%s\n", *pa); // at
//     return 0;
// }

// 程序运行结果是什么
// int main()
// {
//     char *c[] = {"enter", "new", "point", "first"};
//     char **cp[] = {c + 3, c + 2, c + 1, c};
//     char ***cpp = cp;
//     printf("%s\n", **++cpp);         // point
//     printf("%s\n", *--*++cpp + 3);   // er
//     printf("%s\n", *cpp[-2] + 3);    // st
//     printf("%s\n", cpp[-1][-1] + 1); // ew
//     return 0;
// }