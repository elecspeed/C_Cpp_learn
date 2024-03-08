#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>


//C语言对字符和字符串的处理很频繁，但是C语言本身没有字符串类型
//C语言的字符串通常放在 字符数组 或 字符串常量 中
//字符串常量 不能被修改

//1.strlen
// 返回字符串中'\0'前面出现的字符个数
//原理：计算字符的个数，直到遇到'\0'（不包括'\0'）
//函数声明
//size_t strlen( const char *string );

//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)
//		printf("hehe\n");
//	else
//		printf("haha\n");
//
//	return 0;
//}
//上面程序运行结果是hehe

//size_t其实是unsigned int（易错）

//手搓strlen（已讲过，三种方法）
//计数器
//递归
//指针 - 指针
//
//例（用计数器实现）
//int my_strlen(const char* str)	//返回类型用int或size_t都可以，各有千秋
//{
//	int count = 0;	//计数器
//	assert(str);
//	while (*str)
//	{
//		count++;
//		str++;
//	}
// return count;
//}



//2.strcpy
//将源字符串拷贝到目的空间（包括'\0'）
//
// 函数声明
// char *strcpy( char *strDestination, const char *strSource );
//
// 注意事项：目标空间必须足够大；字符串常量不能作目的空间
//

//手搓strcpy（已讲过，5分的代码如何改成10分）
//char* my_strcpy(char* dest, const char* sour)
//{
//	assert(dest);
//	assert(sour);
//	char* ret = dest;
// 
//	//拷贝sour指向的字符串到dest指向的空间，包括'\0'
//	while (*dest++ = *sour++) { ; }
// 
//	//返回目的空间的起始地址
//	return ret;
//}



//3.strcat
// 在字符串后面追加字符串
// 原理：从左向右找到'\0'开始追加
//
//int main()
//{
//	char arr1[30] = "hello\0xxxxxxxxx";
//	char arr2[] = "world";
//	strcat(arr1, arr2);
// 
//	//调试看结果
//	return 0;
//}

// 
// 函数声明
// char *strcat( char *strDestination, const char *strSource );
// 
// 注意事项：不能自己追加自己；其余同strcpy
//

//手搓strcat
//char* my_strcat(char* dest, const char* sour)
//{
//	assert(dest);
//	assert(sour);
//	char* ret = dest;
//
//	//1.找到目的字符串的'\0'
//	while (*dest) dest++;
//
//	//2.追加源字符串（包括'\0'）（不就是strcpy吗）
//	while (*dest++ = *sour++) { ; }
//
//	return ret;
//}



//4.strcmp
// 比较两个字符串的大小（比的是ASCII值，不是长度）
// 原理：先比第一个字符，俩字符串的第一个字符相等再接着比下一个字符，以此类推
// 
// 函数声明
// int strcmp( const char *string1, const char *string2 );
// 
// 标准规定：左>右返回>0的数，相等返回0，左<右返回<0的数
//

//手搓strcmp
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1);
//	assert(str2);
//
//	//可以但不够好的示范（其实是我写的，呜呜）
//	//while (*str1 && *str2)
//	//{
//	//	if (*str1 > *str2)
//	//		return 1;
//	//	else if (*str1 < *str2)
//	//		return -1;
//	//	str1++;
//	//	str2++;
//	//}
//	//if (*str1 > *str2)
//	//	return 1;
//	//else if (*str1 < *str2)
//	//	return -1;
//	//return 0;
//
//	//完美写法
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0') return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//
//	//也可以这样写
//	//return (*str1 - *str2);	//更贴合标准的规定
//}



//
// strcpy,strcat,strcmp不受长度限制，只以'\0'为结束标志，相对不安全
// 因此增加长度受限制的版本
// strncpy,strncat,strncmp
// 



//5.strncpy
// 
// 函数声明
// char *strncpy( char *strDest, const char *strSource, size_t count );
// 与strcpy相比多了一个count，表示在strcpy的基础上只拷贝源字符串的前count个字节（或者说字符）
// 
// 注意事项：源字符串长度小于count时，目的字符串多出的待拷贝部分用'\0'替换；其余同strcpy
//
//int main()
//{
//	char arr1[10] = "xxxxxxxx";
//	char arr2[] = "abcd";
//	strncpy(arr1, arr2, 3);
//	strncpy(arr1, arr2, 6);
//	
//	//调试看结果
//	return 0;
//}

//手搓strncpy
//char* my_strncpy(char* dest, const char* sour, unsigned int count)
//{
//	assert(dest);
//	assert(sour);
//	char* ret = dest;
//
//	//我写的
//	int i = 0;
//	for (i = 0; i < count; i++)
//		if (*dest++ = *sour)
//			sour++;
//	
//	//标准答案
//	//while (count && (*dest++ = *sour++) != '\0')    /* copy string */
//	//	count--;
//	//if (count)                              /* pad out with zeroes */
//	//	while (--count)
//	//		*dest++ = '\0';
//
//	return ret;
//}



//6.strncat
// 
// 函数声明
// char *strncat( char *strDest, const char *strSource, size_t count );
// 表示在strcat的基础上只追加源字符串的前count个字节
// 
// 注意事项：源字符串的长度大于count，追加完会再补加一个'\0'；长度小于count，追加到'\0'就停止
//           即追加部分的后面总有一个'\0'
//
//int main()
//{
//	char arr1[10] = "x\0xxxxxxx";
//	char arr2[] = "abcd";
//	strncat(arr1, arr2, 3);
//	strncat(arr1, arr2, 6);
//
//	//调试看结果
//	return 0;
//}

//手搓strncat
//char* my_strncat(char* dest, const char* sour, unsigned int count)
//{
//	assert(dest);
//	assert(sour);
//	char* ret = dest;
//
//	//我写的
//	while (*dest)	//找到目的字符串的'\0'
//		dest++;
//	 
//	while (*dest++ = *sour++ && --count);	//追加sour字符串直到遇到'\0'或达到count个字符
//	if (count == 0)
//		*dest = '\0';					//如果到count个字符还没有遇到'\0'，就补追一个'\0'
//	return ret;
//
//	//标准答案
//	//while (*dest++)
//	//	;
//	//dest--;
//
//	//while (count--)
//	//	if ((*dest++ = *sour++) == 0)
//	//		return(ret);
//
//	//*front = '\0';
//	//return ret;
//}



//7.strncmp
// 
// 函数声明
// int strncmp( const char *string1, const char *string2, size_t count );
// 表示在strcmp的基础上，只比较两个字符串的前count个字节
// 
// 标准规定同strcmp
//

//手搓strncmp
//int my_strncmp(const char* str1, const char* str2, unsigned int count)
//{
//	assert(str1);
//	assert(str2);
//
//	//找到了7种情况
//	//我写的
//	//if (!count) return 0;		//小心极端情况！
//
//	//while (*str1 == *str2)
//	//{
//	//	if (*str1 == '\0' || --count == 0)
//	//		return 0;
//	//	str1++;
//	//	str2++;
//	//}
//	//return (*str1 - *str2);
//
//	//标准答案
//    //size_t x = 0;
//    //if (!count)             //处理极端情况
//    //    return 0;
//
//    ////以四个字节为单位处理
//    //if (count >= 4)
//    //{
//    //    /* unroll by four */
//    //    for (; x < count - 4; x += 4)
//    //    {
//    //        str1 += 4;
//    //        str2 += 4;
//
//    //        if (*(str1 - 4) == 0 || *(str1 - 4) != *(str2 - 4))
//    //        {
//    //            return(*(unsigned char*)(str1 - 4) - *(unsigned char*)(str2 - 4));
//    //        }
//
//    //        if (*(str1 - 3) == 0 || *(str1 - 3) != *(str2 - 3))
//    //        {
//    //            return(*(unsigned char*)(str1 - 3) - *(unsigned char*)(str2 - 3));
//    //        }
//
//    //        if (*(str1 - 2) == 0 || *(str1 - 2) != *(str2 - 2))
//    //        {
//    //            return(*(unsigned char*)(str1 - 2) - *(unsigned char*)(str2 - 2));
//    //        }
//
//    //        if (*(str1 - 1) == 0 || *(str1 - 1) != *(str2 - 1))
//    //        {
//    //            return(*(unsigned char*)(str1 - 1) - *(unsigned char*)(str2 - 1));
//    //        }
//    //    }
//    //}
//    ///* residual loop */
//    //for (; x < count; x++)
//    //{
//    //    if (*str1 == 0 || *str1 != *str2)
//    //    {
//    //        return(*(unsigned char*)str1 - *(unsigned char*)str2);
//    //    }
//    //    str1 += 1;
//    //    str2 += 1;
//    //}
//    //return 0;
//
//    //把标准答案简化了一下
//    if (!count) return 0;       //处理极端情况
//
//    while (count--)
//    {
//        if (*str1 == 0 || *str1 != *str2)
//        {
//            return (*(unsigned char*)str1 - *(unsigned char*)str2);
//        }
//        str1++;
//        str2++;
//    }
//    return 0;
//    //简化版的标准答案和我写的是两种不同的实现逻辑（画流程图方便观察）
//    //我的是：比较的字符相等则进入循环接着比较，否则退出循环返回差值。
//    //        进入循环后，检查count和刚才比较的字符，
//    //        只要count==0或刚才比较的字符已经是'\0'了，就表明比较结束，返回0。
//    //        否则比较下一对字符
//    //简化版：只要比较次数没到count，就进入循环接着比，否则返回0。
//    //        进入循环后，检查比较的字符是否相等且不为'\0'，
//    //        相等且不为'\0'就接着比，否则返回差值
//    //        （注意‘*str1 == 0 || *str1 != *str2’的补集为‘*str1 != 0 && *str1 == *str2’）
//    // 
//    // 两种逻辑均能满足找到的7种情况
//    // 但实现原理不同，遇到新的情况时得到的结果就可能不同
//    // 没有孰优孰劣，只看哪个能适应新情况
//    //
//}