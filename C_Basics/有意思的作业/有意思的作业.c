#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//����ˮ��һƿ��ˮ1Ԫ��������ƿ���Ի�һƿ��ˮ����20Ԫ���ܺȶ���ƿ��ˮ�����ʵ�֣�
//
//int main()
//{
//	int money = 0;
//	int total = 0;			//���ܹ��ȵ���ˮ
//	int empty = 0;			//���ƿ
//	scanf("%d", &money);	//��Ǯ
//
//	//ģ����̣���һ��
//	total = money;
//	empty = money;
//
//	while (empty>=2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//
//	//ֱ�ӷ��ֹ��ɣ�������
//	//if (money)
//	//	total = money * 2 - 1;
//	//else
//	//	total = 0;
//
//	printf("%d\n", total);
//	return 0;
//}

//���ʵ��int�����������ǰ�벿�֣�ż���ں�벿��
//
//void move(int* arr, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//
//	while (left < right)
//	{
//		while (arr[left] % 2 == 1 && left < right) left++;
//		while (arr[right] % 2 == 0 && left < right) right--;
//		if (right < left)
//		{
//			tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//
//	return 0;
//}

//ʵ��һ�����������������ַ����е�k���ַ�
//
//��һ���Կռ任ʱ�䣩
//void left_move(char* arr, int k)
//{
//	assert(arr != NULL);
//	char tmp[10000] = "0";	//��ǰk���ַ�
//
//	int i = 0;
//	for (i = 0; i < k; i++)
//		tmp[i] = arr[i];
//	while (*(arr + k) != '\0')//ʣ�µ��ַ���������ʵ�����ͷ�ǰ����ڴ棬���ٺ�����ڴ�����ǰk���ַ���
//	{
//		*arr = *(arr + k);
//		arr++;
//	}
//	for (i = 0; i < k; i++)		//�Ѵ��ǰk���ַ��ŵ�����
//		arr[i] = tmp[i];
//}
//������������⣩
//void left_move(char* arr, int k)
//{
//	assert(arr);
//	int len = strlen(arr);
//	int i = 0;
//	for (i = 0; i < k; i++)	//ÿ������һ���ַ�
//	{
//		//1
//		char tmp = arr[0];
//		//2
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//			*(arr + j) = *(arr + j + 1);
//		//3
//		*(arr+len-1) = tmp;
//	}
//}
//������������ת����
//���� ab cdef ---- ba fedc ---- cdef ab
//void reserve(char* left, char* right)	//�����ַ����ĺ���
//{
//	assert(left);
//	assert(right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_move(char* arr, int k)
//{
//	assert(arr);
//	int len = strlen(arr);
//	assert(k < len);
//	reserve(arr, arr + k - 1);		//1.�������
//	reserve(arr + k, arr + len - 1);	//2.�����ұ�
//	reserve(arr, arr + len - 1);	//3.��������
//}
//void print(char* arr) {	printf("%s\n", arr); }
//int main()
//{
//	char arr[100] = "abcdef";
//	//scanf("%s", arr);
//	int k = 0;
//	scanf("%d", &k);
//
//	left_move(arr, k);
//	print(arr);
//	return 0;
//}

//�����⣬дһ�������ж������ַ����ܲ��ܻ�����ת�õ�
//���򷵻�1�������򷵻�0
// ��һ��������٣�
//int is_left_move(char* s1, char* s2)
//{
//	assert(s1);
//	assert(s2);
//	int len1 = strlen(s1);
//	int len2 = strlen(s2);
//	if (len1 != len2) return 0;	//��������Ҫ���
//
//	int i = 0;
//	for (i = 0; i < len1; i++)
//	{
//		left_move(s1, 1);
//		if (strcmp(s1, s2) == 0)	//ÿ��תһ�ξ��ж�һ��
//			return 1;
//	}
//	return 0;
//}
//���������У�
//int is_left_move(const char* s1, const char* s2)
//{
//	assert(s1);
//	assert(s2);
//	int len1 = strlen(s1);
//	int len2 = strlen(s2);
//	if (len1 != len2) return 0;		//���볤��Ҫ���
//
//	// 1.��s1ָ����ַ������ټ�һ�����ַ��� tmp
//	char tmp[10000] = "\0";
//	strcpy(tmp, s1);
//	char* ptmp = strncat(tmp, tmp, len1);	//tmp���ټ�tmp��
//											//�Լ���strncat�������ַ�����Ӳ���strcat������ַ��������ַ���������
//	
//	// 2.�ж�s2ָ����ַ������ǲ���tmp���Ӵ�
//	//�����ÿ⺯��strstr
//	//char* p = strstr(tmp, s2);
//	//if (p)
//	//	return 1;
//	//return 0;
//	
//	//�����ִ�strstrԭ�����ǣ�
//	int count = 0;				//�����������е��ַ��ж��ٸ�
//	const char* ps2 = s2;				//����ֱ�Ӳ���s2�������滹Ҫ������������һ������
//	while (*ptmp)
//	{
//		if (*ptmp == *ps2)
//		{   count++; ps2++;   }				//�����Ƚ�s2����һ���ַ�
//		else
//		{   count = 0; ps2 = s2;   }		//��������0����
//		ptmp++;								//�����಻��ȣ�ptmp��Ҫ�����
//	
//		if (count == len2)				//ֱ���������е��ַ�������len2����˵��tmp����s2
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[30] = "cdefab";
//	gets(arr1);
//	gets(arr2);
//
//	int ret = is_left_move(arr1, arr2);
//	if (ret)
//		printf("YES\n");
//	else
//		printf("NO\n");
//	return 0;
//}

//��ָoffer
//��һ�����־��󣬾����ÿ�д����ҵ�����ÿ�д��ϵ��µ���
//��д�������ĳ�������Ƿ����
//Ҫ��ʱ�临�Ӷ�С��O(N)��
//
//��һ����ÿ�н��ж��ֲ��ң��ԣ�
//�������������ϽǺ����½ǵ������й���
//int check_arr(int arr[][3], int check, int row, int col)
//{
//	int x = 0, y = col - 1;
//	while (x < row-1 && y > 0)
//	{
//		if (arr[x][y] > check)		//���Ͻǵ����ֱ�check���������ж���check���ų�
//			y--;
//		else if (arr[x][y] < check)	//���Ͻǵ����ֱ�checkС�����һ�ж���checkС���ų�
//			x++;
//		else
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { {1,2,3}, {2,3,4}, {3,4,5} };
//	int ret = check_arr(arr, 12, 3, 3);	//���ڷ���1�����򷵻�0
//	if (ret)
//		printf("�ҵ���\n");
//	else
//		printf("������\n");
//
//	return 0;
//}
//˼��������ĳ�Ҫ��õ�check�����ꣿ
//1.���checkֻ����һ������δӺ����ڲ�������������
//2.���check���ڶ������δӺ����ڲ������������
//�����������ַ����
//
//void check_arr(int arr[][3], int check, int row, int col, int index[][2])
//{
//	int x = 0, y = col - 1;
//	int count = 0;					//����check��arr���ж��ٸ�
//	while (x <= row - 1 && y >= 0)
//	{
//		if (arr[x][y] > check)		//���Ͻǵ����ֱ�check���������ж���check���ų�
//			y--;
//		else if (arr[x][y] < check)	//���Ͻǵ����ֱ�checkС�����һ�ж���checkС���ų�
//			x++;
//		else
//		{
//			index[count][0] = x--;	//�������޸�x��y��������һ��Сʱ��c
//			index[count][1] = y--;
//			count++;
//		}
//	}
//	int i = 0;
//	for (i = count; i < row * col; i++)	//�����index����ȫ�ĳ�-1
//		index[i][0] = index[i][1] = -1;
//}
//int main()
//{
//	int arr[3][3] = { {1,2,3}, {2,3,4}, {3,4,5} };
//	int k = 3;
//	int index[9][2] = { 0 };	//����ÿ�����ֶ���Ҫ�ҵ���������3*3 == 9��������
//	
//	//�����Ͳ���
//	check_arr(arr, k, 3, 3, index);
//
//	int i = 0;
//	for (i = 0; i < 9; i++)
//		printf("(%d,%d)\n", index[i][0], index[i][1]);
//	
//	return 0;
//}

