#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ĳ�����ʲô����
// void GetMemory(char *p)
// {
//     p = (char *)malloc(100);
// }
// void test()
// {
//     char *str = NULL;
//     GetMemory(str);
//     strcpy(str, "hello world");
//     printf(str);
// }
// int main()
// {
//     test();
//     return 0;
// }
// �����ڲ���̬�����ڴ�
// �Ľ�
// void GetMemory(char **p)
// {
//     *p = (char *)malloc(100);
// }
// void FreeMemory(char **p)
// {
//     free(*p);
//     *p = NULL;
// }
// void test()
// {
//     char *str = NULL;
//     GetMemory(&str);
//     if (!str)
//         exit(-1);
//     strcpy(str, "hello world");
//     printf(str);
//     FreeMemory(&str);
// }
// int main()
// {
//     test();
//     return 0;
// }

// ����ĳ�����ʲô����
// char *Getmemory()
// {
//     char p[] = "hello world";
//     return p;
// }
// void test()
// {
//     char *str = NULL;
//     str = GetMemory();
//     printf(str);
// }
// int main()
// {
//     test();
//     return 0;
// }
// �������÷���ջ�ռ�ĵ�ַ
// �Ľ���ͬ�ϣ�

// ����ĳ�����ʲô����
// void GetMemory(char **p, int num)
// {
//     *p = (char *)malloc(num);
// }
// void test()
// {
//     char *str = NULL;
//     GetMemory(&str, 100);
//     strcpy(str, "hello world");
//     printf(str);
// }
// int main()
// {
//     test();
//     return 0;
// }
// �Ľ���ͬ�ϣ�

// ����ĳ�����ʲô����
// void test()
// {
//     char *str = (char *)malloc(100);
//     strcpy(str, "hello");
//     free(str);
//     if (str != NULL)
//     {
//         strcpy(str, "world");
//         printf(str);
//     }
// }
// int main()
// {
//     test();
//     return 0;
// }