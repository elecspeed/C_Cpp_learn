#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//8.strstr
// 在一个字符串中查找子字符串，找到了返回子字符串第一次出现的地址，没找到返回NULL
//
//int main()
//{
//	char arr1[] = "abcdddefabcdef";
//	char arr2[] = "def";
//	char* ret = strstr(arr1, arr2);
//	if (ret == NULL)
//		printf("没找到");
//	else
//		printf("%s\n", ret);
//	return 0;
//}

// 
// 声明
// char *strstr( const char *string, const char *strCharSet );
// 

//手搓strstr
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1);
//	assert(str2);
//	if (*str2 == '\0') return (char*)str1;
//
//	//法一：用三个指针变量，两个往后探测，一个用来标记（就是照着标准答案来写的，我写的太low了）
//	//char* p1 = NULL;
//	//char* p2 = NULL;			//p1和p2临时指针
//	//char* curr = (char*)str1;			//当前指针，标记当前走到哪里
//
//	//while (*curr)				//curr会一直往后走直到'\0'
//	//{
//	//	//校准
//	//	p1 = curr;
//	//	p2 = (char*)str2;
//
//	//	//用临时指针往后探测
//	//	while (*p1 && *p2 && *p1 == *p2)
//	//	{
//	//		p1++;
//	//		p2++;
//	//	}
//	//	//探测完毕
//
//	//	//p2遇到'\0'说明子串存在，返回当前指针
//	//	if (!*p2) return curr;
//
//	//	//p2没遇到'\0'而p1遇到，说明curr往后的子串长度小于str2的，再探测也没有意义，返回NULL
//	//	if (!*p1) return NULL;
//
//	//	//p1和p2都没遇到'\0'，进行新一轮探测
//	//	curr++;
//
//	//	//那如果p1和p2都遇到'\0'呢？
//	//	//子串存在，返回当前指针
//	//	//注意上面三种情况已经包含全部情况：
//	//	// p1遇到'\0'（不管p2遇到没）；
//	//	// p1没遇到p2遇到；
//	//	// p1p2都没遇到
//	//}
//	//return NULL;
//
//	//法二：kmp算法（字符串匹配算法）（略）
//}



//9.strtok
// 用来分割字符串（遇到标志符就把其改为'\0'）
// 
// 声明
// char *strtok( char *strToken, const char *strDelimit );
// 
// 用法：
// 1.第一个参数传参时，传的是要被分割的str（或NULL）
// 2.第二个参数传参时，传的是标志符的集合（也是字符串）
// 3.第一个参数不是NULL：函数会把传进来的str的第一个标记改为'\0'，并保存该标记的下一个字符的地址
// 4.第一个参数是NULL：函数将在保存的地址往后继续查找。
// 5.没有遇到标志符，返回NULL
//   遇到了，返回分割出去的一部分字符串的首地址
//
//int main()
//{
//	char arr[] = "192.168.0.100";
//	//char p[] = {'.'};
//	char p[] = ".";			//注意二者区别。"."有两个标志符，'.'和'\0'
//
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);		//直接对arr使用strtok会破坏数据。使用strtok前要拷贝一下
//
//	//char* ret = strtok(buf, p);
//	//printf("%s\n", ret);
//	//
//	//int i = 0;
//	//for (i = 0; i < 3; i++)
//	//{
//	//	ret = strtok(NULL, p);
//	//	printf("%s\n", ret);
//	//}
//
//	//将上面的代码改写一下
//	char* ret = NULL;
//	for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	//妙用for循环的机制
//
//	return 0;
//}
// 
// strtok函数内部可以记住地址，推测是用静态变量实现的
//

//手搓strtok（略）



//10.strerror和_strerror
// Get a system error message (strerror) or prints a user-supplied error message (_strerror).
// 
// 声明
// char *strerror( int errnum );
// char *_strerror( const char *strErrMsg );（略）
// 
// 返回错误码errnum对应的错误信息（把错误码转换成能理解的错误信息，然后返回）
//
//int main()
//{
//	int i = 0;
//	char* str = NULL;
//	for (i = 0; i < 46; i++)
//	{
//		str = strerror(i);
//		printf("%s\n", str);
//	}
//	return 0;
//}
// 
//错误码  错误信息
// 0  -   No error
// 1  -   Operation not permitted
// 2  -   No such file or directory
// ...（详见errno声明）

//实际用法
//#include <errno.h>
//int main()
//{
//	//char* str = strerror(errno);
//	//printf("%s\n", str);
//	//errno是一个全局变量，用来存错误码
//	//C库函数在执行过程中，发生了错误，就会把对应的错误码，赋值给errno
//
//	//打开文件test.txt
//	FILE* pf = fopen("test.txt", "r");
//
//	//FILE：定义好的结构体。
//	//fopen:打开文件函数。
//	//"r"：表示以只读的方式打开
//	// 
//	//意为在本路径下以只读的方式打开文件test.txt，pf接收函数返回值
//	//详见"文件操作"
//
//
//	if (pf == NULL)
//		printf("%s\n", strerror(errno));
//	else
//		printf("open file success\n");
//	return 0;
//}

//手搓strerror（略）



//11.字符分类函数
// 函数	          如果参数是下列类型的字符就返回非零
// iscntrl        控制字符
// isspace        空白字符：包括空格、换页'\f'、换行'\n'、回车'\r'、制表符'\t'和垂直制表符'\v'
// isdigit        十进制数字
// isxdigit       十六进制数字（a-f大小写均可）
// islower        小写字母
// isupper        大写字母
// isalpha        字母
// isalnum        字母或数字
// ispunct        任何不属于数字或字母的图形字符（不是isalnum的补集）
// isgraph        任何图形字符
// isprint        可打印字符：包括空白字符和图形字符
//
//#include <ctype.h>
//
//int main()
//{
//    //char ch = 'j';
//    //int ret = islower(ch);
//
//    //char ch = '8';
//    //int ret = isdigit(ch);
//
//    char ch = 'W';
//    int ret = isupper(ch);
//
//    printf("%d\n", ret);
//    return 0;
//} 



//12.字符转换函数
// int tolower( int c );
// int toupper( int c );
//
//#include <ctype.h>
//
//int main()
//{
//    //char ch = tolower('A');
//    //putchar(ch);
//
//    //ch = toupper('b');
//    //putchar(ch);
//
//    char arr[] = "I Am A Student";
//    int i = 0;
//    while (arr[i])
//    {
//        if (isupper(arr[i]))
//            arr[i] = tolower(arr[i]);
//        i++;
//    }
//
//    printf("%s\n", arr);
//    return 0;
//}
