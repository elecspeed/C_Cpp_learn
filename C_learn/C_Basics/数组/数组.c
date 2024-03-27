#include <stdio.h>

// 选择排序（升序）
//

// void paixu(int arr[], int sz)
// {
//     int index; // 数组下标
//     int tmp;
//     for (int i = 0; i < sz - 1; i++) // 比较 n-1 趟
//     {
//         index = i;
//         for (int j = i + 1; j < sz; j++)
//             if (arr[index] > arr[j])
//                 index = j;
//
//         // 一趟比较过后找到最小值下标。
//         // 然后交换，最小值放在前面。
//         tmp = arr[index];
//         arr[index] = arr[i];
//         arr[i] = tmp;
//     }
// }

// 冒泡排序（升序）
//

// void paixu(int *p, int sz)
// {
//     int a = 0;
//     for (int i = 0; i < sz - 1; i++)         // sz-1趟
//     {
//         int flag = 1; // 假设已经有序
//         for (int j = 0; j < sz - 1 - i; j++) // 一趟
//         {
//             // 相邻两项比较，把大的放到后面
//             if (p[j] > p[j + 1])
//             {
//                 a = p[j];
//                 p[j] = p[j + 1];
//                 p[j + 1] = a;
//                 flag = 0; // 其实无序
//             }
//         }
//         // 一趟比较过后，若有序则退出
//         if (flag == 1)
//             break;
//     }
// }
// int main()
// {
//     int arr[] = {1, 5, 5, 2, 2, 8, 8, 6, 6, 6};
//     int sz = sizeof arr / sizeof arr[0];
//     paixu(arr, sz);
//     for (int i = 0; i < sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// 二维乃至多维数组在内存中都是连续存储
// 二维数组可看作一维数组的数组
// []下标访问运算符
// sizeof arr / sizeof arr[0]获得数组长度，strlen则常用于字符数组
// 数组名是指向数组首地址的常量指针（即地址不能改变，例如不能arr++等。详见指针）
// 如果假设int* const p = arr;则p[1],arr[1],*(p + 1),*(arr +1)四者等价
// 例外：1.sizeof(arr):数组长度	2.&arr:取整个数组的地址
// 数组不完全初始化,剩下的默认初始化为0（注意字符数组的'\0'也是0)
//

// #include <string.h>
// int main()
// {
//     char arr[] = "abcdef";
//     // 两种写法。
//     // strlen 返回的是无符号整型，写法一可能出错。
//
//     for (int i = 0; i < strlen(arr); i++)
//         printf("%c ", arr[i]);
//
//     int len = strlen(arr);
//     for (int i = 0; i < len; i++)
//         printf("%c ", arr[i]);
//     return 0;
// }

// int main()
// {
//     int arr[10] = {0};
//     int *p = NULL;
//     int sz = sizeof arr / sizeof arr[0];

//     for (int i = 0; i < sz; i++)
//     {
//         printf("&arr[%d] = %p\n", i, &arr[i]);
//     }
//     printf("%zd\n", sizeof(p));
//     return 0;
// }
