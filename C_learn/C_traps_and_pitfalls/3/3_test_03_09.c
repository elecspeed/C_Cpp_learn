#include <stdio.h>

/*
 * C 语言中异常检测函数
 */
// #include <stdlib.h>
// #include <string.h>
// #include <errno.h>
// int main()
// {
//     char *p_str = (char *)malloc(ULLONG_MAX);
//     if (!p_str)
//     {
//         perror("line 8");
//         printf("line 9: %s\n", strerror(errno));
//         printf(_strerror("line 10"));
//         // 还有 ferror 检测流错误，声明为 int ferror(FILE *)
//         exit(1);
//     }
//     printf("hh\n");

//     free(p_str);
//     p_str = NULL;

//     return 0;
// }

/*
 * 探究二维数组做形参
 */
// int func1(int arr[3][10]) { return 0; }
// int func2(int arr[][10]) { return 0; }
// int func3(int (*arr)[10]) { return 0; }
// int func4(int (*arr)[5]) { return 0; }
// int func5(int **arr) { return 0; }
// int main()
// {
//     int arr[3][10];
//     func1(arr);
//     func2(arr);
//     func3(arr);
//     func4(arr);
//     func5(arr);

//     return 0;
// }

/*
 * 内存位置 0 有什么
 */
// #include <string.h>
// int main()
// {
//     char *p = NULL;
//     printf(p);
//     printf("location 0 contains:%s\n", p);
//     puts(p);

//     int tmp = (*((int (*)())p))();
//     printf("%d", tmp);

//     (*((void (*)())0))();

//     return 0;
// }

/*
 * 探究栈区变量地址的相对位置 与 其变量声明的相对位置 的关系
 */
// int main()
// {
//     // int i = 0;
//     int a[10];
//     int i = 0;
//     for (i = 0; i <= 11; ++i)
//     {
//         a[i] = 0;
//         printf("%d ", i);
//     }

//     return 0;
// }