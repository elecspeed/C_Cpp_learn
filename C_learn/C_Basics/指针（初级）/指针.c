#include <stdio.h>

// 指针数组
// int a, b;
// int *p[2] = {&a, &b};
//
// 数组指针
// int arr1[3], *p = arr1;
// int arr2[3][3], (*p)[3] = arr2;

// 指向指针的指针：二级指针
// int main()
// {
//     int a = 0;
//     int *p = &a;
//     int **pp = &p;
//     // 从右往左结合。
//     // 右边的 * 表明 pp 是指针，指向 int* 型变量
//     int ***ppp = &pp;
//     // 同理。
//     return 0;
// }

// 指针和数组
//
// 数组可以通过指针来操作；
// 数组名是首元素地址常量；
// （两个例外：&arr，sizeof arr）
// 数组可以开辟一段内存空间，而指针只能存放一个地址。

// 程序输出的结果是？
// int main()
// {
//     int arr[3][3] = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9},
//     };
//     int(*p)[3] = arr;
//     printf("*(*(p+1)+1)  : %d\n", *(*(p + 1) + 1));
//     printf("*(*(p+1)+1)+1: %d\n", *(*(p + 1) + 1) + 1);
//     return 0;
// }

// 数组的数组：二维数组

// 二维数组及有关指针
// int main()
// {
//     int arr[4][3];
//     // int* p = arr;
//     // int** pp = arr;
//     // 都不对，类型不匹配。
//     // p 是 int* 型，pp 是 int** 型，而 arr 是 int(*)[3] 型
//
//     int *ptr = arr[0];
//     int(*ptr_to_arr)[3] = arr;
//     int(*ptr_to_arr_2D)[4][3] = &arr;
//     // 都可以，
//     // ptr           和 arr[0] 是 int* 型，
//     // ptr_to_arr    和 arr    是 int(*)[3] 型，
//     // ptr_to_arr_2D 和 &arr   是 int(*)[4][3] 型。
//
//     // 观察指针移动长度
//     printf("arr is a 2D array.\n");
//     printf("explore the address.\n");
//     printf(" arr: %p  ----   arr+1: %p\n", arr, arr + 1);
//     printf("*arr: %p  ----  *arr+1: %p\n", *arr, *arr + 1);
//     printf("&arr: %p  ----  &arr+1: %p\n", &arr, &arr + 1);
//     return 0;
// }

// 假设
// int arr[3][3], (*p)[3] = arr;
//
// 问下面表达式的含义
// &arr, arr, *arr,
// arr[1], &arr[1],
// arr[1][1], &arr[1][1]
//
// 将下列表达式转换为对应的数组表示
// p, *p, **p, *(p+2),
// *(*p+2)+1, *(*(p+2)+1)

// 手搓 strlen
// 法一：计数器（见分支与循环）
// 法二
// int my_strlen(char *str)
// {
//     char *start = str;
//     char *end = str;
//     while (*end != '\0')
//         end++;
//     return end - start;
// }
// int main()
// {
//     char arr[] = "hello";
//     int len = my_strlen(arr);
//     printf("%d\n", len);
//     return 0;
// }

// 指针运算
// 1.指针 +（或 -）整数
//   地址向前（或向后）移动 len 个字节
//   len == 对应类型大小 * 整数
// 2.指针 - 指针
//   得到元素个数，不是字节个数（通常用于数组）
// 3.指针的关系运算
//   即地址的比较。
//   （注意：比较的指针类型不相同会报警告）
// 4.解引用
//   void 指针不能解引用
//
// 注意：
// 在 VS2022 中，void 指针不能进行 1,2,4 运算；
// 但是在 VScode,MinGW 中，void 指针可以进行 1,2 运算。

// 野指针
// 1.指针变量未初始化
// 2.指针越界访问
// 3.指针指向的空间被释放（又称悬挂指针，难发现）
// 使用前检查指针的有效性

// 指针类型的意义
// 1.解引用时能访问的字节长度
// 2.指针步长

// 指针解引用、大小端
// int main()
// {
//     // 提醒：十六进制的一位相当于二进制的四位
//     int a = 0x11223344;
//     printf("%#x\n", a);
//
//     char *p = (char *)&a;
//     *p = 0;
//     printf("%#x\n", a);
//     // 0x11223300，太神奇了。
//     return 0;
// }
// a 是倒着存的，*p 只改变了 44
// （回来再重温的时候，感觉不严谨。）
// （应该说，p 指向 a 的低地址，*p 只改变了 a 低地址上的数。）

// 每个字节都有地址，指针指向对应变量的低地址。
// 指针的大小： 32 位机上是 4 个字节，64 位机上是 8 个字节。
