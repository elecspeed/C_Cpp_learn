#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/*
 * 喝汽水。
 * 一瓶汽水 1 元，两个空瓶可以换一瓶汽水。
 * 给 20 元，问：能喝多少瓶汽水
 */

// int main()
// {
//     int money = 0;
//     int total = 0;       // 总共喝的汽水
//     int empty = 0;       // 空瓶数
//     scanf("%d", &money); // 给钱
//
//     // 法一：模拟过程
//     total = money > 0 ? money : 0; // 买汽水
//     empty = total;                 // 把买的全部喝完
//     while (empty >= 2)
//     {
//         total += empty >> 1;
//         empty = empty >> 1 + (empty & 1);
//     }
//
//     // 法二：直接发现规律
//     // if (money > 0)
//     //     total = money * 2 - 1;
//     // else
//     //     total = 0;
//
//     printf("%d\n", total);
//     return 0;
// }

/*
 * 奇偶分家
 * 奇数在前半部分，偶数在后半部分
 */

// void move(int *arr, int nums)
// {
//     int left = 0;
//     int right = nums - 1;
//     int tmp = 0;
//
//     while (left < right)
//     {
//         while ((arr[left] & 1) == 1 && left < right)
//             left++;
//         while ((arr[right] & 1) == 0 && left < right)
//             right--;
//         if (left < right)
//         {
//             tmp = arr[left];
//             arr[left] = arr[right];
//             arr[right] = tmp;
//         }
//     }
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int nums = sizeof(arr) / sizeof(arr[0]);
//     move(arr, nums);
//
//     for (int i = 0; i < nums; i++)
//         printf("%d ", arr[i]);
//     return 0;
// }

/*
 * 函数实现：左旋字符串中的 k 个字符
 */

// #include <string.h>
// #include <assert.h>
// void reserve(char *left, char *right)
// {
//     // 逆序字符串
//     while (left < right)
//     {
//         char tmp = *left;
//         *left++ = *right;
//         *right-- = tmp;
//     }
// }
// void left_move(char *str, int k)
// {
//     assert(str);
//     int len = strlen(str);
//     assert(k < len);
//
//     // 法一：暴力求解
//     // int i, j;
//     // i = j = 0;
//     // for (i = 0; i < k; i++)
//     // {
//     //     // 每次左旋一个字符
//     //     char tmp = str[0];
//     //     for (j = 0; j < len - 1; j++)
//     //         str[j] = str[j + 1];
//     //     str[len - 1] = tmp;
//     // }
//
//     // 法二：以空间换时间
//     // 先保存前 k 个字符，
//     // 剩下的字符左旋，
//     // 最后把存的前 k 个字符放到后面。
//     // （相当于直接把前 k 个字符放到后面）
//     // char tmp[10000];
//     // int i = 0;
//     // for (i = 0; i < k; i++)
//     //     tmp[i] = str[i];
//     // while (str[k])
//     // {
//     //     *str = str[k];
//     //     str++;
//     // }
//     // for (i = 0; i < k; i++)
//     //     str[i] = tmp[i];
//
//     // 法三：三步反转法
//     // 发现 ab cdef ---- ba fedc ---- cdef ab
//     // 1.逆序左边
//     // 2.逆序右边
//     // 3.逆序整体
//     reserve(str, str + k - 1);
//     reserve(str + k, str + len - 1);
//     reserve(str, str + len - 1);
// }
// int main()
// {
//     char str[100] = "abcdef";
//     int k = 0;
//     scanf("%d", &k);
//     left_move(str, k);
//     printf(str);
//     return 0;
// }

// 接上题，
// 函数实现：判断两个字符串能不能互相旋转得到
// 能则返回 1，不能则返回 0
// #include <string.h>
// #include <assert.h>
// int is_left_move(char *str1, char *str2)
// {
//     assert(str1);
//     assert(str2);
//     int len1 = strlen(str1);
//     int len2 = strlen(str2);
//     if (len1 != len2)
//         return 0; // 起码长度要相等
//
//     // 法一：暴力穷举
//     // 旋转其中一个字符串，
//     // 每次旋转后判断两个字符串是否相等。
//     // int i = 0;
//     // for (i = 0; i < len1; i++)
//     // {
//     //     left_move(str1, 1);
//     //     if (strcmp(str1, str2) == 0)
//     //         return 1;
//     // }
//     // return 0;
//
//     // 法二：队列
//     // 在 str1 字符串后追加自身，用 tmp 存储。
//     char tmp[10000];
//     strcpy(tmp, str1);
//     strcat(tmp, str1);
//
//     // 如果 str1 和 str2 可以互相旋转得到，
//     // 那么 str2 是 tmp 的子串.
//     char *p = strstr(tmp, str2);
//     if (p)
//         return 1;
//     return 0;
// }
// int main()
// {
//     char str1[10] = "aaa";
//     char str2[10] = "aaaa";
//     int ret = is_left_move(str1, str2);
//     if (ret)
//         printf("YES\n");
//     else
//         printf("NO\n");
//     return 0;
// }

// 剑指offer
// 有一个数字矩阵，矩阵的每行从左到右递增，每列从上到下递增
// 编写程序查找某个数字是否存在
// 要求：时间复杂度小于 O(N)

// 法一：对每行进行二分查找（略）
// 法二：发现右上角和左下角的数字有规律
// int check_arr(int arr[][3], int row, int col, int num)
// {
//     // 存在返回真，否则返回假
//     // 取右上角的坐标
//     int x = 0, y = col - 1;
//     while (x <= row - 1 && y >= 0)
//     {
//         if (arr[x][y] > num)
//             // 右上角的数字比 num 大，则最右列都比 num 大，排除。
//             y--;
//         else if (arr[x][y] < num)
//             // 右上角的数字比 num 小，则第一行都比 num 小，排除。
//             x++;
//         else
//             return 1;
//     }
//     return 0;
// }
// int main()
// {
//     int arr[3][3] = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9},
//     };
//     int ret = check_arr(arr, 3, 3, 7);
//     if (ret)
//         printf("find.\n");
//     else
//         printf("not exist.\n");
//     return 0;
// }

// 思考：如果要求得到 num 的坐标？
// 如果 num 存在，如何从函数内部带出两个数？
// 如果 num 不止一个呢？
// 解决方案：地址传参

// void check_arr(
//     int arr[][3],
//     int row,
//     int col,
//     int num,
//     int index[][2])
// {
//     int x = 0;
//     int y = col - 1;
//     int count = 0; // 存储 num 在 arr 内的个数
//     while (x <= row - 1 && y >= 0)
//     {
//         if (arr[x][y] > num)
//             y--;
//         else if (arr[x][y] < num)
//             x++;
//         else
//         {
//             index[count][0] = x--;
//             index[count][1] = y--;
//             count++;
//         }
//     }
//     // index 多出的部分全改成 -1
//     int i = 0;
//     for (i = count; i < row * col; i++)
//         index[i][0] = index[i][1] = -1;
// }
// int main()
// {
//     int arr[3][3] = {
//         {1, 2, 3},
//         {2, 3, 4},
//         {3, 4, 5},
//     };
//     int k = 1;
//     int index[3][2] = {0};
//     // index 存 num 的坐标。
//     // 理论上 num 在矩阵内可能的个数
//     // 不多于长和宽的较小值
//
//     // 返回型参数
//     check_arr(arr, 3, 3, k, index);
//
//     // 打印 num 在矩阵中的坐标
//     int i = 0;
//     for (i = 0; i < 3; i++)
//         printf("(%d,%d)\n", index[i][0], index[i][1]);
//     return 0;
// }