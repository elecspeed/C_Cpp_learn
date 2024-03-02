#include <stdio.h>

/*
 * 探究 & 和 &&，| 和 || 的细节
 */
// int main()
// {
//     int a = 10;
//     int b = 20;
//     if (4 & 1)
//     {
//         printf("4 & 1\n");
//     }
//     if (0 | 1)
//     {
//         printf("0 | 1\n");
//     }
//     // if (a == 10 & b == 20)
//     //     printf("a == 10 & b == 20\n");
//     // if (a == 0 & b == 20)
//     //     printf("a == 0 & b == 20\n");
//     // if (a == 10 | b == 0)
//     //     printf("a == 10 | b == 0\n");
//     // if (a == 0 | b == 20)
//     //     printf("a == 0 | b == 20\n");
//     return 0;
// }

/*
 * 探究词法分析器的“贪心法”
 */
// int main()
// {
//     // int a = 20;
//     // int b = 10;
//     // int c = a-- - b;
//     // printf("a = %d\n", a);
//     // printf("b = %d\n", b);
//     // printf("c = %d\n", c);
//     int a = 20;
//     int b = 10;
//     int* p = &b;
//     int c = a / *p;
//     return 0;
// }

/*
 * 探究整型常量八进制数
 */
// int main()
// {
//     int a = 098;
//     return 0;
// }
