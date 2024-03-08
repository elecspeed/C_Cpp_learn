//手搓qsort（算法原理-->函数封装）


//算法原理（思想：二分分治）
void quicksort_int(int* arr, int sz)	//升序
{
	if (sz <= 1) return;
	
	int left = 0, right = sz - 1;	//左右下标
	int tmp = arr[0];			//存中间数
	
	while (left != right)
	{
		while (arr[right] >= tmp && left < right) right--; //从右往左找到比中间数小的
		while (arr[left] <= tmp && left < right) left++; //从左往右找到比中间数大的
		
		if (right != left)		//找到了就交换
		{
			int jj = arr[right];
			arr[right] = arr[left];
			arr[left] = jj;
		}
	}
	arr[0] = arr[left];
	arr[left] = tmp;	//最后把中间数放到中间，此时中间数左边的数都比中间数小，右边同
	
	quicksort_int(arr, left);
	quicksort_int(arr + left + 1, sz - left - 1); //以中间数为分隔，左右递归。注意区间!
}
