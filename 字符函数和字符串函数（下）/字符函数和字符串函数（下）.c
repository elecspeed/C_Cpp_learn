#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//8.strstr
// ��һ���ַ����в������ַ������ҵ��˷������ַ�����һ�γ��ֵĵ�ַ��û�ҵ�����NULL
//
//int main()
//{
//	char arr1[] = "abcdefabcdef";
//	char arr2[] = "def";
//	char* ret = strstr(arr1, arr2);
//	if (ret == NULL)
//		printf("û�ҵ�");
//	else
//		printf("%s\n", ret);
//	return 0;
//}

// 
// ����
// char *strstr( const char *string, const char *strCharSet );
// 

//�ִ�strstr
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	if (*str2 == '\0') return str1;

	//��һ��������ָ���������������̽�⣬һ���������
	char* p1 = NULL;
	char* p2 = NULL;			//p1��p2��ʱָ��
	char* curr = str1;			//��ǰָ�룬��ǵ�ǰ�ߵ�����

	while (*curr)				//curr��һֱ������ֱ��'\0'
	{
		//У׼
		p1 = curr;
		p2 = str2;

		//����ʱָ������̽��
		while (*p1 && *p2 && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		//̽�����

		//p2����'\0'˵���Ӵ����ڣ����ص�ǰָ��
		if (!*p2) return curr;

		//p2û����'\0'��p1������˵��curr������Ӵ�����С��str2�ģ���̽��Ҳû�����壬����NULL
		if (!*p1) return NULL;

		//p1��p2��û����'\0'��������һ��̽��
		curr++;
	}
	return NULL;
}
