//手搓qsort（算法原理-->函数封装）


//函数封装
//其实是将算法原理写成函数
//在算法原理的基础上设计函数接口（即参数表）并根据接口调整函数内容
//如果只是一般功能的封装尚可
//关键是qsort自己还是递归函数（二分分治）
//难度就上来了（初学的话先写出适用于int数组的，再调整）

void swap(void* a, void*b, int size)	//交换两个元素的函数
{
	char tmp = '0';
	int i = 0;
	for(i = 0; i < size; i++)
	{
		tmp = *((char*)a + i);
		*((char*)a + i) = *((char*)b + i);
		*((char*)b + i) = tmp;
	}
}
void my_qsort(void* base, int num, int size, int (*compar)(const void*,const void*))
{
	if(num <= 1) return;
	
	//全变成指针。通过指针来操作变量
	void* left = base;							//左下标用指向首元素的void指针实现
	void* right = ((char*)base+(num-1)*size);	//右下标用指向尾元素的void指针实现
	void* tmp = base;							//指向中间数的void指针
	
	while(left != right)
	{
		while(compar(tmp, right) <= 0 && left < right)
			right = (char*)right - size;
		while(compar(tmp, left) >= 0 && left < right)
			left = (char*)left + size;
		if(left != right)
			swap(left, right, size);			//交换元素
	}
	swap(tmp, left, size);
	
	my_qsort(base, (left-base) / size, size, compar);
	my_qsort((char*)right + size, num - ((left-base)/size) - 1, size, compar);
}
