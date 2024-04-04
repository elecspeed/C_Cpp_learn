#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

/*
 * 8.strstr
 * 在一个字符串中查找子串，找到了返回子串第一次出现的地址，没找到返回 NULL
 *
 * 声明
 * char *strstr(const char *string, const char *strCharSet);
 */

// int main()
// {
//     char arr[] = "abbbcd\0abbbcd";
//     const char *str = "bcd";
//     char *ret = strstr(arr, str);
//     if (ret == NULL)
//         printf("没找到");
//     else
//         printf("%s\n", ret);
//     return 0;
// }

// 手搓 strstr
// #include <assert.h>
// char *my_strstr(const char *str1, const char *str2)
// {
//     assert(str1);
//     assert(str2);
//     if (*str2 == '\0')
//         return (char *)str1;
//
//     // 法一：双指针
//     // 用三个指针变量，两个往后探测，一个用来标记
//     char *p1 = NULL;
//     char *p2 = NULL;           // p1 和 p2 为探测指针
//     char *curr = (char *)str1; // 当前指针，标记当前走到哪里
//
//     while (*curr) // curr 会一直往后走直到 '\0'
//     {
//         // 校准
//         p1 = curr;
//         p2 = (char *)str2;
//
//         // 用临时指针往后探测
//         while (*p1 && *p2 && *p1 == *p2)
//         {
//             p1++;
//             p2++;
//         }
//         // 探测完毕
//
//         // p2 遇到 '\0' 说明子串存在，返回当前指针
//         if (!*p2)
//             return curr;
//
//         // p2 没遇到 '\0' 而 p1 遇到，
//         // 说明 curr 往后的子串长度小于 str2 的，
//         // 再探测也没有意义，返回 NULL
//         if (!*p1)
//             return NULL;
//
//         // p1 和 p2 都没遇到 '\0'，进行新一轮探测
//         curr++;
//
//         // 那如果 p1 和 p2 都遇到 '\0' 呢？
//         // 注意，
//         // 上面三种情况已经是全部情况：
//     }
//     return NULL;
//     // 法二：kmp算法（字符串匹配算法）（略）
// }

/*
 * 9.strtok
 * 用来分割字符串（遇到分隔符就把其改为 '\0'）
 *
 * 声明
 * char *strtok( char *strToken, const char *strDelimit );
 *
 * 用法：
 * 1.第一个参数是要被分割的 str（或 NULL）
 * 2.第二个参数是分隔符的集合（即字符串）
 * 3.第一个参数是 str：
 *   把 str 的第一个分隔符改为 '\0'，并保存下一个字节的地址
 * 4.第一个参数是 NULL：
 *   函数将在上一次保存的地址后面继续查找。
 * 5.没有遇到标志符，返回 NULL；
 *   遇到了，返回这次分割出去的字符串的首地址
 */

// 练习使用 strtok
// int main()
// {
//     char arr[] = "192.168.0.100";
//     // char p[] = {'.'};
//     char p[] = ".";
//     // 注意二者区别。"." 有两个标志符：'.' 和 '\0'
//
//     char buf[1024] = {0};
//     strcpy(buf, arr);
//     // 直接对 arr 使用 strtok 会破坏数据。使用 strtok 前要拷贝一下
//
//     char *ret = strtok(buf, p);
//     printf("%s\n", ret);
//     int i = 0;
//     for (i = 0; i < 3; i++)
//     {
//         ret = strtok(NULL, p);
//         printf("%s\n", ret);
//     }
//
//     // 将上面的代码改写一下
//     // 妙用 for 循环的机制
//     char *ret = NULL;
//     for (ret = strtok(buf, p);
//          ret != NULL;
//          ret = strtok(NULL, p))
//     {
//         printf("%s\n", ret);
//     }
//     return 0;
// }
// strtok 函数内部可以记住地址，推测是用静态变量实现的

// 手搓 strtok（略）

/*
 * 10.strerror 和 _strerror
 * Get a system error message (strerror)
 * prints a user-supplied error message (_strerror)
 *
 * 声明
 * char *strerror( int errnum );
 * char *_strerror( const char *strErrMsg );（略）
 *
 * strerror
 * 将参数 errnum 映射到一条有关错误信息的字符串，然后返回首地址
 *
 * 注意：
 * _strerror 不是 C 标准的库函数，而是微软的一个拓展，
 * 对可移植性有要求的程序不能使用 _strerror。
 */

// int main()
// {
//     int i = 0;
//     char *str = NULL;
//     for (i = 0; i < 46; i++)
//     {
//         str = strerror(i);
//         printf("%s\n", str);
//     }
//     return 0;
// }

// 错误码  错误信息
//  0  -   No error
//  1  -   Operation not permitted
//  2  -   No such file or directory
//  ...
// （详见 errno 声明）

// 实际用法
// #include <errno.h>
// int main()
// {
//     // 打开文件 test.txt
//     FILE *pf = fopen("test.txt", "r");
//
//     // FILE：定义好的结构体。
//     // fopen：打开文件函数。
//     // "r"：表示以只读的方式打开
//     //
//     // 意为在当前路径下以只读的方式打开文件 test.txt，
//     // pf 接收函数返回值。
//     // 这里由于当前路径下没有 test.txt，
//     // fopen 将返回 NULL。
//     // 详见"文件操作"
//
//     if (pf == NULL)
//         printf("%s\n", strerror(errno));
//     else
//         printf("open file success\n");
//     return 0;
// }
// errno 是一个全局变量，用来存储错误码。
// 每次系统调用后都会刷新 errno，
// 因此可以根据 errno 的值，
// 来检测系统调用有没有出问题。
// （注意：是系统调用不是函数调用）
// strerror 建立了由 errno 到字符串（错误信息）的映射关系。

// 手搓 strerror（略）

/*
 * 11.字符分类函数
 * 函数	          如果参数是下列类型的字符就返回真（非零）
 * iscntrl        控制字符
 * isspace        空白字符：包括 ' ','\f','\n','\r','\t' 和 '\v'
 * isdigit        十进制数字
 * isxdigit       十六进制数字（a~f 大小写均可）
 * islower        小写字母
 * isupper        大写字母
 * isalpha        字母
 * isalnum        字母或数字
 * ispunct        任何不属于数字或字母的图形字符（不是 isalnum 的补集）
 * isgraph        任何图形字符
 * isprint        可打印字符：包括空白字符和图形字符
 */

// #include <ctype.h>
// int main()
// {
//     char a = 'j', b = '8', c = 'W';
//     int a_ret = islower(a);
//     int b_ret = isdigit(b);
//     int c_ret = isupper(c);
//     printf("%d %d %d\n", a_ret, b_ret, c_ret);
//     return 0;
// }

/*
 * 12.字符转换函数
 * int tolower( int c );
 * int toupper( int c );
 *
 * 少用。
 * 1.有函数调用花销
 * 2.对于大部分机器，字母的 ASCII 值连续。可以手搓
 */

// #include <ctype.h>
// int main()
// {
//     char ch = tolower('A');
//     putchar(ch);
//     ch = toupper('b');
//     putchar(ch);
//     putchar('\n');
//
//     char arr[] = "I Am A Student";
//     int i = 0;
//     while (arr[i])
//     {
//         if (isupper(arr[i]))
//             arr[i] = tolower(arr[i]);
//         i++;
//     }
//     printf("%s\n", arr);
//     return 0;
// }