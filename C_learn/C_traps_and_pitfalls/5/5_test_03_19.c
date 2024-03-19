#include <stdio.h>

/*
 * 程序异常中止，输出缓冲区的内容可能会丢失
 */
// int main()
// {
//     char buf[BUFSIZ];
//     setbuf(stdout, buf);
//     int i;
//     for (i = 0; i < 10000; ++i)
//         printf("%d ", i);

//     // 1 / 0;
//     fflush(stdout);
//     return 0;
// }

/*
 * getchar 是宏？
 *
 * Without stdio.h, 'getchar' and 'putchar' will be
 * seen as function, which is slower than macro.
 * We can check them by testing the time they cost.
 */

// #define EOF -1
// int main()
// {
//     int ch;
//     while ((ch = getchar()) != EOF)
//         putchar(ch);
//     return 0;
// }
// Fail. My OS is too smart. There is little difference in time.
