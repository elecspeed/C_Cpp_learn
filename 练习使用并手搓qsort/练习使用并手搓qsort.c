#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//函数封装
//其实是将算法原理写成函数
//在原理的基础上设计函数接口（即参数表）并根据接口调整函数内容
//如果只是一般功能的封装尚可
//可qsort自己还是递归函数（二分分治）
//难度就上来了（初学的话先写出适用于int数组的，再调整）
//
//void swap(void* a, void*b, int size)
//{
//	char tmp = '0';
//	int i = 0;
//	for(i = 0; i < size; i++)
//	{    tmp = *(char*)a;  *(char*)a = *(char*)b;  *(char*)b = tmp;    }
//}
//void my_qsort(void* base, int num, int size, int (*compar)(const void*,const void*))
//{
//	if(num <= 1) return;
//	
//	//全变成指针。通过指针来操作变量
//	void* left = base;							//左下标用指向首元素的void指针实现
//	void* right = ((char*)base+(num-1)*size);	//右下标用指向尾元素的void指针实现
//	void* tmp = base;							//指向中间数的void指针
//	
//	while(left != right)
//	{
//		while(compar(tmp, right) <= 0 && left < right)
//			right = (char*)right - size;
//		while(compar(tmp, left) >= 0 && left < right)
//			left = (char*)left + size;
//		if(left != right)
//			swap(left, right, size);			//交换元素
//	}
//	swap(tmp, left, size);
//	
//	my_qsort()
//}
//
//typedef struct book
//{
//	char name[5];
//	float price;
//}Book;
//int cmp_stru_by_price(const void* e1, const void* e2)
//{
//	if(((Book*)e1)->price > ((Book*)e2)->price)
//		return 1;
//	else if(((Book*)e1)->price < ((Book*)e2)->price)
//		return -1;
//	else
//		return 0;
//}
//int cmp_stru_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((Book*)e1)->name, ((Book*)e2)->name);
//}
//int main()
//{
//	Book b[3] = {{"a", 3.0}, {"c", 2.0}, {"b", 4.0}};
//	int sz = sizeof(b) / sizeof(b[0]);
//	
//	my_qsort(b, sz, sizeof(b[0]), cmp_stru_by_price);
//	
//	my_qsort(b, sz, sizeof(b[0]), cmp_stru_by_name);
//	
//	return 0;
//}


//手搓qsort（算法原理，函数封装）

//算法（思想：二分分治）
//
void quicksort(int* arr, int sz)
{
	if(sz <= 1) return;
	
	int left = 0, right = sz-1;	//左右下标
	int tmp = arr[0];			//存中间数
	
	while(left != right)
	{
		while(arr[right] >= tmp && left < right) right--;//从右往左找到比中间数小的
		while(arr[left] <= tmp && left < right) left++;//从左往右找到比中间数大的
		
		if(right != left)		//找到了就交换
		{
			int jj = arr[right];
			arr[right] = arr[left];
			arr[left] = jj;
		}
	}
	arr[0] = arr[left];
	arr[left] = tmp;	//最后把中间数放到中间，此时中间数左边的数都比中间数小，右边同
	
	quicksort(arr, left-1);
	quicksort(arr+left+1, sz-left-1);//以中间数为分隔，左右递归。注意区间
}
int main()
{
	int arr[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	quicksort(arr, sz);
	
	int i = 0;
	for(i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	return 0;
}



//排序结构体数组
//
//typedef struct student
//{
//	char name[10];
//	float high;
//} Stu;
//
//int cmp_str_by_high(const void*e1, const void*e2)
//{
//	if (((Stu*)e1)->high < ((Stu*)e2)->high)
//		return 1;
//	else if (((Stu*)e1)->high > ((Stu*)e2)->high)
//		return -1;
//	else
//		return 0;
//}
//int cmp_str_by_name(const void*e1, const void*e2)
//{
//	return strcmp(((Stu*)e1)->name, ((Stu*)e2)->name);
//}
//int main()
//{
//	Stu s[3] = {{"Peter", 171.3}, {"Joe", 171.2}, {"Maisi", 171.4}};
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	qsort(s, sz, sizeof(s[0]), cmp_str_by_high);//以身高排序
//
//	qsort(s, sz, sizeof(s[0]), cmp_str_by_name);//以名字排序
//
//	//调试看排序结果
//	return 0;
//}

//排序int数组
//
////回调函数的类型限定为int (const void*, const void*)
//int cmp_int(const void* e1, const void* e2)
//{
////	if(*(int*)e1 > *(int*)e2)
////		return 1;
////	else if(*(int*)e1 == *(int*)e2)
////		return 0;
////	else
////		return -1;
//	//简化
//	//return (*(int*)e1 > *(int*)e2) - (*(int*)e1 < *(int*)e2);//升序
//	return (*(int*)e1 < *(int*)e2) - (*(int*)e1 > *(int*)e2);//降序
//}
//int main()
//{
//	int arr[] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	//从qsort的定义看出，qsort可以排序任一数据类型
//	//但需要提供四个参数
//	//四个参数分别表示：排序首地址，排序长度，单个元素长度，两个元素间的比较方法
//	//其中，比较方法用回调函数实现
//	//思想：这四个参数是排序的核心要素，即只有知道这四个要素，才能进行排序
//	//升降序在回调函数内部决定
//
//	int i = 0;
//	for(i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//qsort定义
//void qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
//stdlib库
