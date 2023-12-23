#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>


//C���Զ��ַ����ַ����Ĵ����Ƶ��������C���Ա���û���ַ�������
//C���Ե��ַ���ͨ������ �ַ����� �� �ַ������� ��
//�ַ������� ���ܱ��޸�

//1.strlen
// �����ַ�����'\0'ǰ����ֵ��ַ�����
//ԭ�������ַ��ĸ�����ֱ������'\0'��������'\0'��
//��������
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
//����������н����hehe

//size_t��ʵ��unsigned int���״�

//�ִ�strlen���ѽ��������ַ�����
//������
//�ݹ�
//ָ�� - ָ��
//
//�����ü�����ʵ�֣�
//int my_strlen(const char* str)	//����������int��size_t�����ԣ�����ǧ��
//{
//	int count = 0;	//������
//	assert(str);
//	while (*str)
//	{
//		count++;
//		str++;
//	}
// return count;
//}



//2.strcpy
//��Դ�ַ���������Ŀ�Ŀռ䣨����'\0'��
//
// ��������
// char *strcpy( char *strDestination, const char *strSource );
//
// ע�����Ŀ��ռ�����㹻���ַ�������������Ŀ�Ŀռ�
//

//�ִ�strcpy���ѽ�����5�ֵĴ�����θĳ�10�֣�
//char* my_strcpy(char* dest, const char* sour)
//{
//	assert(dest);
//	assert(sour);
//	char* ret = dest;
// 
//	//����sourָ����ַ�����destָ��Ŀռ䣬����'\0'
//	while (*dest++ = *sour++) { ; }
// 
//	//����Ŀ�Ŀռ����ʼ��ַ
//	return ret;
//}



//3.strcat
// ���ַ�������׷���ַ���
// ԭ�����������ҵ�'\0'��ʼ׷��
//
//int main()
//{
//	char arr1[30] = "hello\0xxxxxxxxx";
//	char arr2[] = "world";
//	strcat(arr1, arr2);
// 
//	//���Կ����
//	return 0;
//}

// 
// ��������
// char *strcat( char *strDestination, const char *strSource );
// 
// ע����������Լ�׷���Լ�������ͬstrcpy
//

//�ִ�strcat
//char* my_strcat(char* dest, const char* sour)
//{
//	assert(dest);
//	assert(sour);
//	char* ret = dest;
//
//	//1.�ҵ�Ŀ���ַ�����'\0'
//	while (*dest) dest++;
//
//	//2.׷��Դ�ַ���������'\0'����������strcpy��
//	while (*dest++ = *sour++) { ; }
//
//	return ret;
//}



//4.strcmp
// �Ƚ������ַ����Ĵ�С���ȵ���ASCIIֵ�����ǳ��ȣ�
// ԭ���ȱȵ�һ���ַ������ַ����ĵ�һ���ַ�����ٽ��ű���һ���ַ����Դ�����
// 
// ��������
// int strcmp( const char *string1, const char *string2 );
// 
// ��׼�涨����>�ҷ���>0��������ȷ���0����<�ҷ���<0����
//

//�ִ�strcmp
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1);
//	assert(str2);
//
//	//���Ե������õ�ʾ������ʵ����д�ģ����أ�
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
//	//����д��
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
//	//Ҳ��������д
//	//return (*str1 - *str2);	//�����ϱ�׼�Ĺ涨
//}



//
// strcpy,strcat,strcmp���ܳ������ƣ�ֻ��'\0'Ϊ������־����Բ���ȫ
// ������ӳ��������Ƶİ汾
// strncpy,strncat,strncmp
// 



//5.strncpy
// 
// ��������
// char *strncpy( char *strDest, const char *strSource, size_t count );
// ��strcpy��ȶ���һ��count����ʾ��strcpy�Ļ�����ֻ����Դ�ַ�����ǰcount���ֽڣ�����˵�ַ���
// 
// ע�����Դ�ַ�������С��countʱ��Ŀ���ַ�������Ĵ�����������'\0'�滻������ͬstrcpy
//
//int main()
//{
//	char arr1[10] = "xxxxxxxx";
//	char arr2[] = "abcd";
//	strncpy(arr1, arr2, 3);
//	strncpy(arr1, arr2, 6);
//	
//	//���Կ����
//	return 0;
//}

//�ִ�strncpy
//char* my_strncpy(char* dest, const char* sour, unsigned int count)
//{
//	assert(dest);
//	assert(sour);
//	char* ret = dest;
//
//	//��д��
//	int i = 0;
//	for (i = 0; i < count; i++)
//		if (*dest++ = *sour)
//			sour++;
//	
//	//��׼��
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
// ��������
// char *strncat( char *strDest, const char *strSource, size_t count );
// ��ʾ��strcat�Ļ�����ֻ����Դ�ַ�����ǰcount���ֽ�
// 
// ע�����Դ�ַ����ĳ��ȴ���count��׷������ٲ���һ��'\0'������С��count��׷�ӵ�'\0'��ֹͣ
//           ��׷�Ӳ��ֵĺ�������һ��'\0'
//
//int main()
//{
//	char arr1[10] = "x\0xxxxxxx";
//	char arr2[] = "abcd";
//	strncat(arr1, arr2, 3);
//	strncat(arr1, arr2, 6);
//
//	//���Կ����
//	return 0;
//}

//�ִ�strncat
char* my_strncat(char* dest, const char* sour, unsigned int count)
{
	assert(dest);
	assert(sour);
	char* ret = dest;


}



//7.strncmp
// 
// ��������
// int strncmp( const char *string1, const char *string2, size_t count );
// ��ʾ��strcmp�Ļ����ϣ�ֻ���������ַ�����ǰcount���ֽ�
//
