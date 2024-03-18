#include <stdio.h>

/*
 * 返回整数的 getchar
 */

// int main()
// {
//     // char ch = 126;
//     // unsigned char ch = 126;
//     // putchar(ch);

//     int ch;
//     while ((ch = getchar()) != EOF)
//         putchar(ch);
//     return 0;
// }

/*
 * 更新顺序文件
 * 把 ./tmp.txt 里面的所有字母 a 换成字母 A
 */

// int main()
// {
//     FILE *fp = fopen("./tmp.txt", "r+");
//     if (!fp)
//     {
//         perror("fail to open tmp.txt");
//         return 0;
//     }

//     int ch;
//     while ((ch = fgetc(fp)) != EOF)
//     {
//         if (ch == 'a')
//         {
//             fseek(fp, -1, SEEK_CUR);
//             fputc('A', fp);
//             fseek(fp, 0, SEEK_CUR);
//         }
//     }

//     fclose(fp);
//     fp = NULL;
//     return 0;
// }

/*
 * 缓冲输出 && 练习使用库函数 setbuf
 * 函数声明：
 * void setbuf( FILE *stream, char *buffer );
 */

// 使用缓冲区要注意最后一次的清空
// #include <stdlib.h>
// int main()
// {
//     // char buffer[BUFSIZ];
//     char *buffer;
//     buffer = (char *)malloc(BUFSIZ);
//     // 用 setbuf 设置的缓冲区大小只能是 BUFSIZ：512。
//     // 想设置不一样的大小，用另一个函数 setvbuf。
//     // setbuf 是早期版本，setvbuf 出现后将 setbuf 重构了，
//     // 留下 setbuf 以便兼容早期的 C 代码。

//     setbuf(stdout, NULL);   // 标准输出没有缓冲区
//     setbuf(stdout, buffer); // 标准输出有缓冲区：buffer

//     int ch;
//     while ((ch = getchar()) != EOF)
//         putchar(ch);
//     return 0;
// }

/*
 * 练习使用库函数 signal
 * 函数声明：
 * void
 * (*signal(int sig, void(__cdecl *func)(int sig [, int subcode])))
 * (int sig);
 */