#include <stdio.h>

//指针数组		int* p[3] = {&a, &b, &c};
//数组指针		int* p = arr1;			//指向一维数组首元素
//				int (*p)[4] = arr2;		//指向二维数组首元素，即第0行

//二级指针，指向指针的指针
//int main()
//{
//	int a = 0;
//	int* p = &a;
//	int** pp = &p;		//第二颗星表明pp是指针，int和第一颗星表明pp存储的是int类型指针的地址
//	//int*** ppp = &pp;
//	
//	return 0;
//}


//数组和指针有联系，数组可以通过指针来访问，数组名是首元素地址
//但数组可以开辟一段内存空间，而指针只能存放一个地址

//指针和数组
//数组名是首元素地址（两个例外：&arr，sizeof arr）
//int arr[3][3];
//int (*p)[3] = arr;				//p存储行的地址，[3]表示指向的二维数组有3列
//问 &arr，arr，*arr，arr[1]，arr[1][1]，&arr[1][1]，&arr[1]分别是什么意思
//问 p，*p，**p，*(p+2)，*(*p+2)+1，*(*(p+2)+1)对应的arr表达？
//
//int main()
//{
//	int arr[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
//	
////	int* p1 = arr;
////	int** pp = arr;		//不可，类型不匹配。p1是int*型，pp是int**型，而arr是int(*)[3]型
//	int* p1 = arr[0];
//	int (*p)[3] = arr;
//	int (*pp)[4][3] = &arr;	//可，p1和arr[0]是int*型，p和arr是int(*)[3]型，pp和&arr是int(*)[4][3]型
//	
//	printf("  &arr: %p\t  &arr+1: %p\n", &arr, &arr+1);
//	printf("arr[0]: %p\tarr[0]+1: %p\n\n", arr[0], arr[0]+1);
//	
//	printf("&arr[0][0]: %p\t&arr[0][0]+1: %p\n\n", &arr[0][0], &arr[0][0]+1);
//	
//	printf("     p: %p\t     p+1: %p\n", p, p+1);
//	printf("    *p: %p\t    *p+1: %p\n", *p, *p+1);
//	printf("*(p+1): %p\t*(p+1)+1: %p\n\n", *(p+1), *(p+1)+1);
//	
//	printf("*(*(p+1)+1): %d\t*(*(p+1)+1)+1: %d\n\n", *(*(p+1)+1), *(*(p+1)+1)+1);
//	printf("发现arr[0]，&arr[0][0]，*p三者等价\n");
//	
//	return 0;
//}


//手搓strlen(循环与分支讲过法一：计数器)
//法二
//
//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while(*end != '\0')
//	{
//		end++;
//	}
//	return end - start;
//}
//int main()
//{
//	char arr[] = "hello";
//	int len = my_strlen(arr);
//	
//	printf("%d\n", len);
//	return 0;
//}


//指针运算（不是解引用）
//1.指针+-整数		即地址向前后移动
//2.指针-指针		得到元素个数，不是字节个数（通常只在同一块空间才这样干）
//3.指针的关系运算	即地址的比较
//注意：C标准允许数组指针可以和挨着数组后的地址比较，但不能和挨着数组前的地址比较

//野指针
//1.指针变量未初始化
//2.指针越界访问
//3.指针指向的空间被释放（难发现）
//使用前检查指针的有效性

//指针类型的意义
//1.解引用时能访问的字节长度
//2.指针步长
//
//int main()
//{
//	int a = 0x11223344;			//十六进制的一位相当于二进制的四位
//	char* p = (char *)&a;
//	
//	*p = 0;
//	printf("%#x", a);		//0x11223300,太神奇了。a是倒着存的，*p只改变了44
//	return 0;
//}


//每个字节都有地址，指针指向的是对应变量的低地址
//指针的大小在32位机上是4个字节，64位机上是8个字节
