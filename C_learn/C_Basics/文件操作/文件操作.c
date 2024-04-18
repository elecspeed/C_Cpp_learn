#define _CRT_SECURE_NO_WARNINGS 1

// 什么是文件，为什么需要文件
// 文件名和文件类型
// 文件缓冲区
// 文件指针
// 文件的打开与关闭
// 顺序读写和随机读写
// 文件结束的判定

#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
 * 磁盘里面放的都是文件
 *
 * > Linux 的理念之一：一切皆文件
 *
 * 之前处理的数据，其输入输出都在终端上进行。
 * 现在要将数据的输入输出转到磁盘上进行，
 * 处理的便是磁盘上的文件
 *
 * 而将数据存放到磁盘，是为了使数据持久化。
 * 首先程序想要被 CPU 运行，得先放进内存。
 *
 * > CPU - register - memory - disk
 *
 * 但内存的空间是有限的，程序在运行结束后空间就要被回收。
 * 程序执行过程中生成的数据也会随着程序的结束而被释放。
 * 相比内存，磁盘的空间更大，而读写数据的速度更慢，
 * 适合用来存储数据。
 * 因此磁盘用来存储大量数据，而内存用来“承上启下”。
 */

/*
 * 文件名：文件路径+文件名主干+文件后缀（或称拓展名）
 * 例：C:\User\test.txt
 *
 * 文件类型
 * 根据写入数据时数据的组织形式，
 * 文件被称为文本文件或二进制文件。
 * 数据不加以转换，从内存直接存入磁盘，为二进制文件；
 * 数据通过 ASCII 等编码转换，再从内存存入磁盘，则为文本文件。
 *
 * 字符只能以 ASCII 等编码存储。
 * 数值型数据可以用 ASCII 等编码存储，也可以用二进制形式存储。
 * （意思是，数值型数据以“数字字符”的形式被我们看到，
 * （那么存储时，可以用字符的存储方式存储，也可以用二进制的方式）
 */

/*
 * 文件缓冲区
 * C 标准采用“缓冲文件系统”处理文件。
 *
 * 从程序输出数据到外部（文件，终端等），
 * 或从外部输入数据到程序，
 * 都要经过缓冲区。
 *
 * 用底层硬件和操作系统的知识来解释。
 * 系统会自动在内存中，
 * 为程序的每一个正在使用的文件开辟一块“文件缓冲区”。
 * 在内存和磁盘之间往来的数据，会先存在输入缓冲区和输出缓冲区，
 * 直到缓冲区满了，
 * 才写入对应的存储区域。
 * 程序运行结束但是缓冲区未满，
 * 剩下的数据一样会被写入对应的存储区域。
 *
 * 缓冲区的大小由 C 编译系统决定。
 */

/*
 * 文件指针
 * 在缓冲文件系统中，每个被使用的文件
 * 都在内存中开辟了一块文件信息区（注意不是文件缓冲区），
 * 该文件信息区用来存放文件的相关信息
 * （如文件名，文件状态，文件位置等）。
 *
 * 而这块文件信息区不就刚好是结构体变量？！
 * 于是，系统将该结构体类型声明为 FILE。
 * 每使用一个文件，
 * 系统就创建一个 FILE 结构体变量，并自动初始化成员变量。
 * 由于这些成员变量存储着相关信息，
 * 所以当文件相关信息发生变化，
 * FILE 的成员变量也会发生变化。
 *
 * 那么，这块开辟的空间就由“文件指针”来管理。
 * （个人感觉，文件操作是针对结构体 FILE 的动态内存操作）
 */

// 观察 FILE 成员
// int main()
// {
//     // 以 "r","w","a" 三种方式打开的文件，
//     // 其 FILE 成员有什么不同
//     char *str_arr[3] = {"r", "w", "a"};
//     int i;
//     for (i = 0; i < 3; ++i)
//     {
//         FILE *pf = fopen("./test.txt", str_arr[i]);
//         if (!pf)
//             return 0;
//         else
//         {
//             printf("%s\n", pf->_base);
//             printf("%d\n", pf->_bufsiz);
//             printf("%d\n", pf->_charbuf);
//             printf("%d\n", pf->_cnt);
//             printf("%d\n", pf->_file);
//             printf("%d\n", pf->_flag);
//             printf("%s\n", pf->_ptr);
//             printf("%s\n", pf->_tmpfname);
//             fclose(pf);
//         }
//     }
//     return 0;
// }

/*
 * 文件使用前要先打开，使用完要关闭。
 * C 语言每打开文件，都会返回文件信息区的地址（动态内存分配），
 * 相当于建立了指针和文件的联系。
 */

/*
 * fopen 函数
 * 声明
 * FILE *fopen( const char *filename, const char *mode );
 * filename：文件名，
 * mode：打开方式。
 *
 * 打开方式
 * "r"：以只读的方式打开。
 *      如果指定文件不存在或没找到，返回 NULL。
 * "w"：以只写的方式打开。
 *      存在，其内容将被清空；
 *      不存在，新建一个。
 * "a"：以只追加的方式打开。
 *      不存在先创建；
 *      只能在文件尾部写入数据。
 * "r+"：以读写的方式打开。
 *       其余同 "r"。
 * "w+"：以读写的方式打开。
 *       其余同 "w"
 * "a+"：以读写的方式打开。
 *       被追加的文件以 EOF 结尾。
 *       其余同 "a"
 * （使用 "a" 和 "a+"，原数据不会被修改）
 *
 * 后缀 t,b,c,n
 * t：以文本模式打开。涉及文本编码问题。
 * b：以二进制模式打开。
 * c：未知
 * n：未知
 */

// 打开文件 test.txt
// int main()
// {
//     // 绝对路径
//     // FILE *pf = fopen(
//     //     "C:\\Users\\elecspeed\\Desktop\\test.txt",
//     //     "r");
//     // 相对路径
//     // FILE *pf = fopen("../../test.txt", "r");
//
//     FILE *pf = fopen("test.txt", "r");
//     if (!pf)
//     {
//         // 打开失败
//         printf("%s", strerror(errno));
//         return 0;
//     }
//     // ...
//
//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

/*
 * 关闭文件
 * Closes a stream (fclose)
 * or
 * closes all open streams except for stdin,stdout,stderr
 * (_fcloseall).
 *
 * 声明
 * int fclose( FILE *stream );
 * int _fcloseall( void );
 * stream：对应的文件指针
 *
 * fclose 成功返回 0，否则返回 EOF；
 * _fcloseall 成功返回关闭的文件数，否则返回 EOF。
 */

/*
 * 文件的顺序读写
 * 函数名       功能                适用于
 * fgetc       字符输入            所有输入流
 * fputc       字符输出            所有输出流
 * fgets       文本行输入
 * fputs       文本行输出          同上
 * fscanf      格式化输入
 * fprintf     格式化输出          同上
 * fread       二进制输入          文件
 * fwrite      二进制输出          文件
 */

// int main()
// {
//     // 不同的打开方式会有不同的读写函数
//     FILE *pf = fopen("test.txt", "r");
//     if (!pf)
//     {
//         printf("%s\n", strerror(errno));
//         return 0;
//     }
//
//     // 写
//     fputc('g', pf);
//     // 读
//     int ch = fgetc(pf);
//     putchar(ch);
//
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

/*
 * 键盘和屏幕都是提供交互的设备。
 * 键盘 - 标准输入设备
 * 屏幕 - 标准输出设备
 * 二者是每个程序默认打开的两个流设备。
 * 其实，
 * 一共有三个默认打开的流设备：stdin,stdout,stderr
 * FILE* stdin
 * FILE* stdout
 * FILE* stderr
 *
 * 因此，文件读写函数可以操作标准输入输出流
 */

// int main()
// {
//     int ch = fgetc(stdin);
//     fputc(ch, stdout);
//     return 0;
// }

// 练习使用文件读写函数（略）

// 笔试题（对比下列函数）
// printf,fprintf,sprintf
// scanf,fscanf,sscanf
//
// printf 和 scanf 是针对 标准输入输出流 的 格式化输入输出函数
// fprintf 和 fscnaf 是针对 所有输入输出流 的 格式化输入输出函数
// 因此，
// printf,scanf 分别是 fprintf,fscanf 的子集。

// sscanf 和 sprintf
// struct S
// {
//     int i;
//     float f;
//     char arr[10];
// };
// typedef struct S S;
// int main()
// {
//     S s = {100, 3.14f, "abcdef"};
//     S tmp = {0};
//     char buf[1024] = {0};
//
//     sprintf(buf,
//             "%d %f %s",
//             s.i, s.f, s.arr);
//     sscanf(buf,
//            "%d %f %s",
//            &(tmp.i), &(tmp.f), tmp.arr);
//     // 调试看结果
//     return 0;
// }

/*
 * sprintf 和 sscanf
 * 声明
 * int sprintf( char *buffer, const char *format [, argument] ... );
 * 字符串格式化
 *
 * int sscanf( const char *buffer, const char *format [, argument ] ... );
 * 读取格式化字符串中的数据
 */

// struct S
// {
//     char name[8];
//     int age;
//     double score;
// };
// typedef struct S S;
// int main()
// {
//     S s1[3] = {
//         {"张三", 20, 59.9},
//         {"张三", 20, 59.9},
//         {"张三", 20, 59.9},
//     };
//     FILE *pf = fopen("test.txt", "wb");
//     if (!pf)
//         return 0;
//     fwrite(&s1, sizeof(S), 3, pf);
//     fclose(pf);
//     // 打开同目录的 test.txt 文件看结果
//
//     S s2[3] = {0};
//     pf = fopen("test.txt", "rb");
//     if (!pf)
//         return 0;
//     fread(&s2, sizeof(S), 3, pf);
//     fclose(pf);
//     pf = NULL;
//     // 调试看结果
//     return 0;
// }

// 文件的随机读写

/*
 * fseek
 * 定位文本指针的位置（注意不是文件指针）
 *
 * 声明
 * int fseek( FILE *stream, long offset, int origin );
 * stream：对应的文件指针
 * offset：偏移量，单位是字节
 * origin：起始偏移的位置，三种：
 *         SEEK_CUR，当前文本指针的位置
 *         SEEK_END，文本末
 *         SEEK_SET，文本首
 *
 * 成功返回 0，否则返回非零。
 * 对于不能定位的机器，其返回值未定义。
 */

// int main()
// {
//     FILE *pf = fopen("test.txt", "w+");
//     if (!pf)
//         return 0;
//
//     // 1.定位文本指针
//     fseek(pf, -2, SEEK_END); // SEEK_END 一般是 '\0'
//     // 2.读取文件
//     int ch = fgetc(pf);
//     printf("%c\n", ch);
//
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// ftell
//  计算文本指针相对于SEEK_SET的偏移量，单位是字节
//
//  声明
//  long ftell( FILE *stream );
//
// int main()
//{
//     FILE* pf = fopen("test.txt", "r");
//     if (!pf)
//         return 0;
//
//     //文本指针在起始位置
//     long pos = ftell(pf);
//     printf("%ld\n", pos);
//
//     //文本指针在起始位置后3个字节处
//     fseek(pf, 3, SEEK_SET);
//     pos = ftell(pf);
//     printf("%ld\n", pos);
//
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// rewind
//  让文本指针回到SEEK_SET位置
//
//  声明
//  void rewind( FILE *stream );
//
// int main()
//{
//     FILE* pf = fopen("test.txt", "r");
//     if (!pf)
//         return 0;
//
//     fseek(pf, 3, SEEK_SET);
//     rewind(pf);
//
//     int ch = fgetc(pf);
//     printf("%c\n", ch);
//
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// 文件结束的判定
//  fgetc，fgets，fread 都有返回值，以下情况说明读取结束 或 发生错误
//
//  fgetc    返回EOF（end of file，文件结束标志，值为-1）
//  fgets    返回NULL，值为0
//  fread    返回值小于实际要读的个数

// feof
//  Tests for end-of-file on a stream.
//  判断文件结束的原因（是不是读取结束）
//
//  声明
//  int feof( FILE *stream );
//
//  是读取结束，则返回非零（即返回真）
//

// ferror
//  Tests for an error on a stream.
//  判断文件结束的原因（是不是发生错误）
//
//  声明
//  int ferror( FILE *stream );
//
//  是发生错误，则返回非零（即返回真）
//

// feof 和 ferror 常常一起使用

// 先介绍perror
//  strerror - 把错误码对应的字符串 的地址返回
//  perror - 在错误信息前加上自定义说明，直接打印
//
// int main()
//{
//     FILE* pf = fopen("test2.txt", "r");
//     if (!pf)
//     {
//         //perror("");
//         perror("abcd");
//         return 0;
//     }
//     //...
//
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// 使用 feof 和 ferror
// int main()
//{
//     //打开test.txt文件
//     FILE* pf = fopen("test.txt", "r");
//     if (!pf)
//     {
//         perror("fail to open test.txt");
//         return 0;
//     }
//
//     //循环读取文件
//     int ch = 0;
//     while ((ch = fgetc(pf)) != EOF)
//         putchar(ch);
//     printf("\n");
//
//     //判断循环结束的原因
//     if (ferror(pf))
//         puts("I/O error when reading");
//     else if (feof(pf))
//         puts("End of file reached successfully");
//
//     //关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }
