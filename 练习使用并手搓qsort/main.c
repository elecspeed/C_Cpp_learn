#include "my_qsort.h"

int main()
{
	test1();	//练习使用qsort（排序int数组）
	test2();	//练习使用qsort（排序结构体数组）
	test3();	//利用int数组初步实现快速排序算法：quicksort_int
//				  仿造quicksort_int写my_qsort
	test4();	//用my_qsort排序结构体数组

	return 0;
}


//test1，qsort排序int数组
//
//回调函数的类型限定为int (*)(const void*, const void*)
int cmp_int(const void* e1, const void* e2)
{
//	if(*(int*)e1 > *(int*)e2)
//		return 1;
//	else if(*(int*)e1 == *(int*)e2)
//		return 0;
//	else
//		return -1;
	
	//简化
	//return (*(int*)e1 > *(int*)e2) - (*(int*)e1 < *(int*)e2);//升序
	return (*(int*)e1 < * (int*)e2) - (*(int*)e1 > *(int*)e2); //降序
}
void test1()
{
	int arr[] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
	int sz = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	//升降序在回调函数内部决定

	int i = 0;
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
}


//test2，qsort排序结构体数组
typedef struct student
{
	char name[10];
	float high;
} Stu;

int cmp_stru_by_high(const void*e1, const void*e2)
{
	if (((Stu*)e1)->high < ((Stu*)e2)->high)
		return 1;
	else if (((Stu*)e1)->high > ((Stu*)e2)->high)
		return -1;
	else
		return 0;
}
int cmp_stru_by_name(const void*e1, const void*e2)
{
	return strcmp(((Stu*)e1)->name, ((Stu*)e2)->name);
}
void test2()
{
	Stu s[3] = {{"Peter", 170.1}, {"Joe", 171.1}, {"Maisi", 172.1}};
	int sz = sizeof(s) / sizeof(s[0]);

	qsort(s, sz, sizeof(s[0]), cmp_stru_by_high);	//以身高排序

	qsort(s, sz, sizeof(s[0]), cmp_stru_by_name);	//以名字排序

	//调试看排序结果
}


//test3，quicksort_int排序int数组
void test3()
{
	int arr[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
	int sz = sizeof(arr) / sizeof(arr[0]);

	quicksort_int(arr, sz);

	int i = 0;
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
}


//test4，my_qsort排序结构体数组
typedef struct book
{
	char name[5];
	float price;
} Book;

int cmp_Book_by_price(const void* e1, const void* e2)
{
	if (((Book*)e1)->price > ((Book*)e2)->price)
		return 1;
	else if (((Book*)e1)->price < ((Book*)e2)->price)
		return -1;
	else
		return 0;
}
int cmp_Book_by_name(const void* e1, const void* e2)
{
	return strcmp(((Book*)e1)->name, ((Book*)e2)->name);
}
void test4()
{
	Book b[3] = {{"a", 3.0}, {"c", 2.0}, {"b", 4.0}};
	int sz = sizeof(b) / sizeof(b[0]);

	my_qsort(b, sz, sizeof(b[0]), cmp_Book_by_price);	//以价格排序

	my_qsort(b, sz, sizeof(b[0]), cmp_Book_by_name);	//以名字排序

	//调试看排序结果
}

