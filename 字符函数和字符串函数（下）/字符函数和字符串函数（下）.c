#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//8.strstr
// 在一个字符串中查找子字符串，找到了返回子字符串第一次出现的地址，没找到返回NULL
//
//int main()
//{
//	char arr1[] = "abcdefabcdef";
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
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	if (*str2 == '\0') return str1;

	//法一：用三个指针变量，两个往后探测，一个用来标记
	char* p1 = NULL;
	char* p2 = NULL;			//p1和p2临时指针
	char* curr = str1;			//当前指针，标记当前走到哪里

	while (*curr)				//curr会一直往后走直到'\0'
	{
		//校准
		p1 = curr;
		p2 = str2;

		//用临时指针往后探测
		while (*p1 && *p2 && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		//探测完毕

		//p2遇到'\0'说明子串存在，返回当前指针
		if (!*p2) return curr;

		//p2没遇到'\0'而p1遇到，说明curr往后的子串长度小于str2的，再探测也没有意义，返回NULL
		if (!*p1) return NULL;

		//p1和p2都没遇到'\0'，进行新一轮探测
		curr++;
	}
	return NULL;
}
