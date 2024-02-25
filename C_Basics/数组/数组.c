#include <stdio.h>
#include <string.h>


//数组不完全初始化,剩下的默认初始化为0（注意字符数组的'\0'也是0)

/*		选择排序（升序）	  */
//
//void paixu(int arr[], int sz)
//{
//	for(int i = 0; i < sz-1; i++)		//比较n-1趟
//	{
//		int index = i, flag = 1;
//		int a;
//		
//		for(int j = i+1; j<sz; j++)		//一趟比较过后找到最小值下标
//		{
//			if(arr[index] > arr[j])
//			{
//				index = j;
//				flag = 0;
//			}
//		}
//		if(flag == 0){
//			a = arr[index];					//最小值放在前面
//			arr[index] = arr[i];
//			arr[i] = a;
//		}
//	}
//}

/*		冒泡排序（升序）	  */
//
//void paixu(int* p, int sz)
//{
//	int a = 0;
//	
//	for(int i=0; i<sz-1; i++)			//sz-1趟
//	{
//		int flag = 1;					//假设已经有序
//		
//		for(int j=0; j < sz-1-i; j++)	//一趟两两比较
//		{
//			if(p[j] > p[j+1])			//相邻两项比较，把大的放到后面
//			{
//				a = p[j];
//				p[j] = p[j+1];
//				p[j+1] = a;
//				flag = 0;				//其实无序
//			}
//		}
//		if(flag == 1){					//一趟比较过后，若有序则退出
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[] = {1,3,5,4,7,9,6,2,3,5,7,8,9,3};
//	int sz = sizeof arr / sizeof arr[0];
//	
//	paixu(arr, sz);
//	for(int i=0; i<sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



//二维乃至多维数组在内存中都是连续存储
//二维数组可看作一维数组的数组
//[]下标访问运算符
//sizeof arr / sizeof arr[0]获得数组长度，strlen则常用于字符数组
//数组名是指向数组首地址的常量指针（即地址不能改变，例如不能arr++等。详见指针）
//如果假设int* const p = arr;则p[1],arr[1],*(p + 1),*(arr +1)四者等价
//例外：1.sizeof(arr):数组长度	2.&arr:取整个数组的地址


//int main()
//{
//	char arr[] = "abcdef";
////for(int i=0; i<strlen(arr); i++)	//一般不这么写，strlen返回的是无符号整型。也可以用sizeof
//	int len = strlen(arr);
//	for(int i=0; i<len; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	return 0;
//}


/*
int main()
{
int arr[10] = {0};
int* p = NULL;
int sz = sizeof arr / sizeof arr[0];

for(int i=0; i<sz; i++){
printf("&arr[%d] = %p\n", i, &arr[i]);
}
printf("%lld\n", sizeof(p));
return 0;
}
*/
