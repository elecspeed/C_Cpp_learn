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

// 接上题，写一个函数判断两个字符串能不能互相旋转得到
// 能则返回1，不能则返回0
//  法一（暴力穷举）
// int is_left_move(char* s1, char* s2)
//{
//	assert(s1);
//	assert(s2);
//	int len1 = strlen(s1);
//	int len2 = strlen(s2);
//	if (len1 != len2) return 0;	//长度起码要相等
//
//	int i = 0;
//	for (i = 0; i < len1; i++)
//	{
//		left_move(s1, 1);
//		if (strcmp(s1, s2) == 0)	//每旋转一次就判断一次
//			return 1;
//	}
//	return 0;
// }
// 法二（队列）
// int is_left_move(const char* s1, const char* s2)
//{
//	assert(s1);
//	assert(s2);
//	int len1 = strlen(s1);
//	int len2 = strlen(s2);
//	if (len1 != len2) return 0;		//起码长度要相等
//
//	// 1.在s1指向的字符串后再加一个该字符串 tmp
//	char tmp[10000] = "\0";
//	strcpy(tmp, s1);
//	char* ptmp = strncat(tmp, tmp, len1);	//tmp后再加tmp。
//											//自加用strncat，两个字符串相加才用strcat（详见字符函数和字符串函数）
//
//	// 2.判断s2指向的字符串，是不是tmp的子串
//	//可以用库函数strstr
//	//char* p = strstr(tmp, s2);
//	//if (p)
//	//	return 1;
//	//return 0;
//
//	//或者手搓strstr原理（不是）
//	int count = 0;				//计算连续共有的字符有多少个
//	const char* ps2 = s2;				//可以直接操作s2，但后面还要归正，故再用一个变量
//	while (*ptmp)
//	{
//		if (*ptmp == *ps2)
//		{   count++; ps2++;   }				//相等则比较s2的下一个字符
//		else
//		{   count = 0; ps2 = s2;   }		//不相等则归0归正
//		ptmp++;								//不管相不相等，ptmp都要向后走
//
//		if (count == len2)				//直到连续共有的字符数等于len2，才说明tmp中有s2
//			return 1;
//	}
//	return 0;
// }
// int main()
//{
//	char str1[30] = "abcdef";
//	char str2[30] = "cdefab";
//	gets(str1);
//	gets(str2);
//
//	int ret = is_left_move(str1, str2);
//	if (ret)
//		printf("YES\n");
//	else
//		printf("NO\n");
//	return 0;
// }

// 剑指offer
// 有一个数字矩阵，矩阵的每行从左到右递增，每列从上到下递增
// 编写程序查找某个数字是否存在
// 要求：时间复杂度小于O(N)；
//
// 法一：对每行进行二分查找（略）
// 法二：发现右上角和左下角的数字有规律
// int check_arr(int arr[][3], int check, int row, int col)
//{
//	int x = 0, y = col - 1;
//	while (x < row-1 && y > 0)
//	{
//		if (arr[x][y] > check)		//右上角的数字比check大，则最右列都比check大，排除
//			y--;
//		else if (arr[x][y] < check)	//右上角的数字比check小，则第一行都比check小，排除
//			x++;
//		else
//			return 1;
//	}
//	return 0;
// }
// int main()
//{
//	int arr[3][3] = { {1,2,3}, {2,3,4}, {3,4,5} };
//	int ret = check_arr(arr, 12, 3, 3);	//存在返回1，否则返回0
//	if (ret)
//		printf("找到了\n");
//	else
//		printf("不存在\n");
//
//	return 0;
// }
// 思考：如果改成要求得到check的坐标？
// 1.如果check只存在一个，如何从函数内部带出两个数？
// 2.如果check存在多个，如何从函数内部带出多个数？
// 解决方案：地址传参
//
// void check_arr(int arr[][3], int check, int row, int col, int index[][2])
//{
//	int x = 0, y = col - 1;
//	int count = 0;					//计算check在arr内有多少个
//	while (x <= row - 1 && y >= 0)
//	{
//		if (arr[x][y] > check)		//右上角的数字比check大，则最右列都比check大，排除
//			y--;
//		else if (arr[x][y] < check)	//右上角的数字比check小，则第一行都比check小，排除
//			x++;
//		else
//		{
//			index[count][0] = x--;	//别忘了修改x和y！卡了我一个小时，c
//			index[count][1] = y--;
//			count++;
//		}
//	}
//	int i = 0;
//	for (i = count; i < row * col; i++)	//多出的index部分全改成-1
//		index[i][0] = index[i][1] = -1;
// }
// int main()
//{
//	int arr[3][3] = { {1,2,3}, {2,3,4}, {3,4,5} };
//	int k = 3;
//	int index[9][2] = { 0 };	//假设每个数字都是要找的数，则共有3*3 == 9个坐标组
//
//	//返回型参数
//	check_arr(arr, k, 3, 3, index);
//
//	int i = 0;
//	for (i = 0; i < 9; i++)
//		printf("(%d,%d)\n", index[i][0], index[i][1]);
//
//	return 0;
// }
