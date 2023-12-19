#include <stdio.h>

//快速排序
void paixu(int arr[], int )
{
	int mid = (left + right)/2;
	while(arr[left] < arr[mid])
		left++;
	while(arr[right] > arr[mid])
		right--;
}
int main()
{
	int arr[10000] = {0};
	int n = 0, i = 0;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	int left = 0, right = n;
	paixu(arr, left, right);
	
	return 0;
}

//冒泡排序(N*N , ...)
//int main()
//{
//	int arr[101] = {0};
//	int n = 0, i = 0, j = 0, t = 0, flag = 0;	//n：要排多少数，i,j：循环变量，t两数交换，flag：标记
//	
//	scanf("%d", &n);
//	for(i = 1; i < n; i++)
//		scanf("%d", &arr[i]);
//	
//	for(i = 1; i < n; i++)
//	{
//		for(j = 1; j < n-i; j++)
//		{
//			flag = 1;			//假设已经有序
//			if(arr[j]<arr[j+1])
//			{
//				t = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = t;
//				flag = 0;		//进入if说明无序
//			}
//		}
//		if(flag) break;			//没进入if则已经有序，退出循环
//	}
//	for(i = 1; i < n; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}

//桶排序(N+M , 浪费空间)
//int main()
//{
//	int arr[100] = {0};
//	int n = 0, i = 0, t = 0;//n：要排多少数，i：循环变量，t：存输入的数
//	
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) 
//	{
//		scanf("%d", &t);
//		arr[t]++;
//	}
//	for (i = 0; i < 100 && n > 0; i++) 
//	{
//		for (int j = 0; j < arr[i]; j++) 
//		{
//			printf("%d ", i);
//			n--;
//		}
//	}
//	return 0;
//}
