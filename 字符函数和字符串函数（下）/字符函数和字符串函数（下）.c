#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//8.strstr
// ��һ���ַ����в������ַ������ҵ��˷������ַ�����һ�γ��ֵĵ�ַ��û�ҵ�����NULL
//
//int main()
//{
//	char arr1[] = "abcdddefabcdef";
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
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1);
//	assert(str2);
//	if (*str2 == '\0') return (char*)str1;
//
//	//��һ��������ָ���������������̽�⣬һ��������ǣ��������ű�׼����д�ģ���д��̫low�ˣ�
//	//char* p1 = NULL;
//	//char* p2 = NULL;			//p1��p2��ʱָ��
//	//char* curr = (char*)str1;			//��ǰָ�룬��ǵ�ǰ�ߵ�����
//
//	//while (*curr)				//curr��һֱ������ֱ��'\0'
//	//{
//	//	//У׼
//	//	p1 = curr;
//	//	p2 = (char*)str2;
//
//	//	//����ʱָ������̽��
//	//	while (*p1 && *p2 && *p1 == *p2)
//	//	{
//	//		p1++;
//	//		p2++;
//	//	}
//	//	//̽�����
//
//	//	//p2����'\0'˵���Ӵ����ڣ����ص�ǰָ��
//	//	if (!*p2) return curr;
//
//	//	//p2û����'\0'��p1������˵��curr������Ӵ�����С��str2�ģ���̽��Ҳû�����壬����NULL
//	//	if (!*p1) return NULL;
//
//	//	//p1��p2��û����'\0'��������һ��̽��
//	//	curr++;
//
//	//	//�����p1��p2������'\0'�أ�
//	//	//�Ӵ����ڣ����ص�ǰָ��
//	//	//ע��������������Ѿ�����ȫ�������
//	//	// p1����'\0'������p2����û����
//	//	// p1û����p2������
//	//	// p1p2��û����
//	//}
//	//return NULL;
//
//	//������kmp�㷨���ַ���ƥ���㷨�����ԣ�
//}



//9.strtok
// �����ָ��ַ�����������־���Ͱ����Ϊ'\0'��
// 
// ����
// char *strtok( char *strToken, const char *strDelimit );
// 
// �÷���
// 1.��һ����������ʱ��������Ҫ���ָ��str����NULL��
// 2.�ڶ�����������ʱ�������Ǳ�־���ļ��ϣ�Ҳ���ַ�����
// 3.��һ����������NULL��������Ѵ�������str�ĵ�һ����Ǹ�Ϊ'\0'��������ñ�ǵ���һ���ַ��ĵ�ַ
// 4.��һ��������NULL���������ڱ���ĵ�ַ����������ҡ�
// 5.û��������־��������NULL
//   �����ˣ����طָ��ȥ��һ�����ַ������׵�ַ
//
//int main()
//{
//	char arr[] = "192.168.0.100";
//	//char p[] = {'.'};
//	char p[] = ".";			//ע���������"."��������־����'.'��'\0'
//
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);		//ֱ�Ӷ�arrʹ��strtok���ƻ����ݡ�ʹ��strtokǰҪ����һ��
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
//	//������Ĵ����дһ��
//	char* ret = NULL;
//	for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	//����forѭ���Ļ���
//
//	return 0;
//}
// 
// strtok�����ڲ����Լ�ס��ַ���Ʋ����þ�̬����ʵ�ֵ�
//

//�ִ�strtok���ԣ�



//10.strerror��_strerror
// Get a system error message (strerror) or prints a user-supplied error message (_strerror).
// 
// ����
// char *strerror( int errnum );
// char *_strerror( const char *strErrMsg );���ԣ�
// 
// ���ش�����errnum��Ӧ�Ĵ�����Ϣ���Ѵ�����ת���������Ĵ�����Ϣ��Ȼ�󷵻أ�
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
//������  ������Ϣ
// 0  -   No error
// 1  -   Operation not permitted
// 2  -   No such file or directory
// ...�����errno������

//ʵ���÷�
//#include <errno.h>
//int main()
//{
//	//char* str = strerror(errno);
//	//printf("%s\n", str);
//	//errno��һ��ȫ�ֱ����������������
//	//C�⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬��ֵ��errno
//
//	//���ļ�test.txt
//	FILE* pf = fopen("test.txt", "r");
//
//	//FILE������õĽṹ�塣
//	//fopen:���ļ�������
//	//"r"����ʾ��ֻ���ķ�ʽ��
//	// 
//	//��Ϊ�ڱ�·������ֻ���ķ�ʽ���ļ�test.txt��pf���պ�������ֵ
//	//���"�ļ�����"
//
//
//	if (pf == NULL)
//		printf("%s\n", strerror(errno));
//	else
//		printf("open file success\n");
//	return 0;
//}

//�ִ�strerror���ԣ�



//11.�ַ����ຯ��
// ����	          ����������������͵��ַ��ͷ��ط���
// iscntrl        �����ַ�
// isspace        �հ��ַ��������ո񡢻�ҳ'\f'������'\n'���س�'\r'���Ʊ��'\t'�ʹ�ֱ�Ʊ��'\v'
// isdigit        ʮ��������
// isxdigit       ʮ���������֣�a-f��Сд���ɣ�
// islower        Сд��ĸ
// isupper        ��д��ĸ
// isalpha        ��ĸ
// isalnum        ��ĸ������
// ispunct        �κβ��������ֻ���ĸ��ͼ���ַ�������isalnum�Ĳ�����
// isgraph        �κ�ͼ���ַ�
// isprint        �ɴ�ӡ�ַ��������հ��ַ���ͼ���ַ�
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



//12.�ַ�ת������
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
