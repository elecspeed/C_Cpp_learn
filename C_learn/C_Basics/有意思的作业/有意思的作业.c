#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/*
 * ����ˮ��
 * һƿ��ˮ 1 Ԫ��������ƿ���Ի�һƿ��ˮ��
 * �� 20 Ԫ���ʣ��ܺȶ���ƿ��ˮ
 */

// int main()
// {
//     int money = 0;
//     int total = 0;       // �ܹ��ȵ���ˮ
//     int empty = 0;       // ��ƿ��
//     scanf("%d", &money); // ��Ǯ
//
//     // ��һ��ģ�����
//     total = money > 0 ? money : 0; // ����ˮ
//     empty = total;                 // �����ȫ������
//     while (empty >= 2)
//     {
//         total += empty >> 1;
//         empty = empty >> 1 + (empty & 1);
//     }
//
//     // ������ֱ�ӷ��ֹ���
//     // if (money > 0)
//     //     total = money * 2 - 1;
//     // else
//     //     total = 0;
//
//     printf("%d\n", total);
//     return 0;
// }

/*
 * ��ż�ּ�
 * ������ǰ�벿�֣�ż���ں�벿��
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
 * ����ʵ�֣������ַ����е� k ���ַ�
 */

// #include <string.h>
// #include <assert.h>
// void reserve(char *left, char *right)
// {
//     // �����ַ���
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
//     // ��һ���������
//     // int i, j;
//     // i = j = 0;
//     // for (i = 0; i < k; i++)
//     // {
//     //     // ÿ������һ���ַ�
//     //     char tmp = str[0];
//     //     for (j = 0; j < len - 1; j++)
//     //         str[j] = str[j + 1];
//     //     str[len - 1] = tmp;
//     // }
//
//     // �������Կռ任ʱ��
//     // �ȱ���ǰ k ���ַ���
//     // ʣ�µ��ַ�������
//     // ���Ѵ��ǰ k ���ַ��ŵ����档
//     // ���൱��ֱ�Ӱ�ǰ k ���ַ��ŵ����棩
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
//     // ������������ת��
//     // ���� ab cdef ---- ba fedc ---- cdef ab
//     // 1.�������
//     // 2.�����ұ�
//     // 3.��������
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

// �����⣬
// ����ʵ�֣��ж������ַ����ܲ��ܻ�����ת�õ�
// ���򷵻� 1�������򷵻� 0
// #include <string.h>
// #include <assert.h>
// int is_left_move(char *str1, char *str2)
// {
//     assert(str1);
//     assert(str2);
//     int len1 = strlen(str1);
//     int len2 = strlen(str2);
//     if (len1 != len2)
//         return 0; // ���볤��Ҫ���
//
//     // ��һ���������
//     // ��ת����һ���ַ�����
//     // ÿ����ת���ж������ַ����Ƿ���ȡ�
//     // int i = 0;
//     // for (i = 0; i < len1; i++)
//     // {
//     //     left_move(str1, 1);
//     //     if (strcmp(str1, str2) == 0)
//     //         return 1;
//     // }
//     // return 0;
//
//     // ����������
//     // �� str1 �ַ�����׷�������� tmp �洢��
//     char tmp[10000];
//     strcpy(tmp, str1);
//     strcat(tmp, str1);
//
//     // ��� str1 �� str2 ���Ի�����ת�õ���
//     // ��ô str2 �� tmp ���Ӵ�.
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

// ��ָoffer
// ��һ�����־��󣬾����ÿ�д����ҵ�����ÿ�д��ϵ��µ���
// ��д�������ĳ�������Ƿ����
// Ҫ��ʱ�临�Ӷ�С�� O(N)

// ��һ����ÿ�н��ж��ֲ��ң��ԣ�
// �������������ϽǺ����½ǵ������й���
// int check_arr(int arr[][3], int row, int col, int num)
// {
//     // ���ڷ����棬���򷵻ؼ�
//     // ȡ���Ͻǵ�����
//     int x = 0, y = col - 1;
//     while (x <= row - 1 && y >= 0)
//     {
//         if (arr[x][y] > num)
//             // ���Ͻǵ����ֱ� num ���������ж��� num ���ų���
//             y--;
//         else if (arr[x][y] < num)
//             // ���Ͻǵ����ֱ� num С�����һ�ж��� num С���ų���
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

// ˼�������Ҫ��õ� num �����ꣿ
// ��� num ���ڣ���δӺ����ڲ�������������
// ��� num ��ֹһ���أ�
// �����������ַ����

// void check_arr(
//     int arr[][3],
//     int row,
//     int col,
//     int num,
//     int index[][2])
// {
//     int x = 0;
//     int y = col - 1;
//     int count = 0; // �洢 num �� arr �ڵĸ���
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
//     // index ����Ĳ���ȫ�ĳ� -1
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
//     // index �� num �����ꡣ
//     // ������ num �ھ����ڿ��ܵĸ���
//     // �����ڳ��Ϳ�Ľ�Сֵ
//
//     // �����Ͳ���
//     check_arr(arr, 3, 3, k, index);
//
//     // ��ӡ num �ھ����е�����
//     int i = 0;
//     for (i = 0; i < 3; i++)
//         printf("(%d,%d)\n", index[i][0], index[i][1]);
//     return 0;
// }