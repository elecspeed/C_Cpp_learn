#include <stdio.h>
#include <string.h>

//错误分类：1.编译错误，2.链接错误，3.运行错误


//assert在assert库
//const的用法举例
//
//int main()
//{
//	int a = 10, b = 20;
//	
//	const int* p1 = &a;
//	*p1 = b;			//error，const修饰*p1表示*p1不能改变（即不能改变a），但可以指向别的变量
//	
//	int* const p2 = &a;
//	p2 = &b;			//error，const修饰p2表示p2不能改变（即只能指向a），但可以改变a
//	
//	const int* const p3 = &a;	//既不能通过*p改变a，也不能改变p（即指向别的变量）
//	
//	return 0;
//}



//那么如何写出易于调试的代码呢
//
//优秀的代码风格：效率高，可读性高，可维护性高，可拓展性高
//
//1.使用assert（断言）
//2.尽量使用const
//3.平常coding保持严谨，该空格空格，该缩进缩进，该精简精简
//4.加必要的注释
//5.多见识隐晦的bug
//示例：手搓strcpy
//
//版本一（5分，还是我自己写的，呜呜）
//void my_strcpy(char* dest, char* scr)
//{
//	while(*scr != '\0')
//	{
//		*dest = *scr;
//		dest++;
//		scr++;
//	}
//	*dest = '\0';
//}
//版本二（6分，精炼）
//void my_strcpy(char* dest, char* scr)
//{
//	while(*dest++ = *scr++){;}
//}
//版本三（7分，安全）
//void my_strcpy(char* dest, char* scr)
//{
//	if(dest && scr)
//		while(*dest++ = *scr++){;}
//}
//版本四（8分，有警报）
//#include <assert.h>
//void my_strcpy(char* dest, char* scr)
//{
//	assert(dest != NULL);
//	assert(scr != NULL);//断言。()里面为真则无事，为假则警报
//	
//	while(*dest++ = *scr++){;}
//}
//版本五（10分，就是库函数的写法）
//#include <assert.h>
//char * my_strcpy(char* dest, const char* scr) //返回复制好的字符串。用const保护*scr不被修改。
//{												//前一个变化增加了函数的功能，后一个变化便于改错
//	char* ret = dest;
//	//同版本四
//	return ret;
//}
//int main()
//{
//	char arr1[] = "#####################";
//	char arr2[] = "hello";
//	my_strcpy(arr1, arr2);
//	//my_strcpy(arr1,NULL);	//版本三，四，五
//	printf("%s", arr1);
//	printf("%s", my_strcpy(arr1,arr2));	//版本五
//	
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
////	printf("%p\n", &i);
////	printf("%p\n", arr);
//	
//	for(i = 0; i <= 11; i++)
//	{
//		printf("hh\n");
//		arr[i] = 0;
//	}
//	return 0;
//}
//
//在debug下死循环，在release下不死循环
//笔试题，出自《C陷阱和缺陷》
//
//先说为什么死循环
//1.栈区的默认使用：先使用高地址的空间，再使用低地址的空间
//2.随着数组下标增长，地址由低到高变化
//循环变量i声明在数组前面，为高地址；数组下标的增长让数组能够越界访问到i（只要越界到一定长度即可）
//不同编译器环境下i和arr的距离不同，需要越界的长度不同
//解决办法：把i声明在arr后？（不是）不要让数组越界才是硬道理
//
//再来看为什么不死循环
//试着分别在debug和release下看看i和arr的地址就能明白
//release优化的地方包括代码在内存里的分布和结构。
//因此，工作中程序员在debug下测试好的代码，有可能被测试员在release下测出bug
//对于程序员，要承认自己的代码不是最完美的；对于测试员，发现bug要及时保留证据



//调试技巧
//什么是bug
//什么是调试及重要性
//调试的步骤
//
////发现问题（程序员-->测试员-->用户）		//即发现问题
////定位错误（隔离，消除等方法）			//即找到问题
////确定错误产生的原因						//即分析问题
////提出解决办法							//即解决问题
////重新测试								//即验证结果
//
//debug和release
////debug即调试版本，包含调试信息，且不作任何优化，便于程序员调试
//
////release即发布版本，在大小和运行速度上最优化，便于用户使用
////release不能调试
//
////在内存大小和功能实现上都有差别
////debug包含调试信息，占内存大；而release进行优化，可有限度地修正代码
//
//断点：启动调试，程序会直接执行到断点处。
////注意，是按逻辑顺序执行，即如果断点在循环体内则会继续执行到下一次循环的断点
////而表面上看程序还是停留在循环体的断点处，实际上已经执行了一次循环
////断点可以设置条件
//
//调试时查看程序当前信息（临时变量，内存信息，调用堆栈，汇编信息，寄存器信息）
//
//复杂调试场景：多线程程序调试
