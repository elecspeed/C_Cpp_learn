#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// ö�٣���һһ�о�

// ö������
// enum Sex
// {
//     // ö�ٵĿ���ȡֵ��ö�ٳ�Ա����ö�ٳ�����
//     // ö�ٳ�Ա֮���� , �ָ�
//     MALE,
//     FEMALE,
//     SECRET
// };
// enum Color
// {
//     RED,
//     GREEN = 2,
//     BLUE
// };
// int main()
// {
//     // enum Sex s1 = 0; // ������
//     enum Sex s2 = MALE;
//     enum Color c = BLUE;
//
//     printf("%d %d %d\n", MALE, FEMALE, SECRET);
//     printf("%d %d %d\n", RED, GREEN, BLUE);
//     printf("%zd\n", sizeof(enum Sex));
//     printf("%zd\n", sizeof(enum Color));
//     return 0;
// }

/*
 * ö�ٳ�Ա���� int ���ͳ�����
 * Ĭ�ϴ� 0 ��ʼ��Ĭ����������ö�ٳ�Ա��� 1��
 * �����ֶ����ó�Ա��ֵ��
 *
 * ��ʼ��ö�ٱ���ʱ������ʹ��ö�ٳ�Ա���������� int ���ͳ�����
 *
 * ö�����͵Ĵ�С
 * sizeof(ö������) == sizeof(int)
 *
 * ö�ٵĹ��������� #define ��ɣ���Ϊʲô��Ҫö�٣�
 *
 * ö�ٵ��ŵ㣨�� #define ��ȣ�
 * 1.һ�ο��Զ���������
 * 2.ͨ����װ��ֹ������ͻ
 * 3.���Ӵ���Ŀɶ��ԺͿ�ά����
 * 4.���ڵ��ԡ�
 *   ����ʱ�Ѿ�����Ԥ����#define ����ı�ʶ���ᱻ�滻��
 *   ��ö�ٱ������ᡣ
 * 5.��� #define ����ı�ʶ����ö�������ͼ�飬���Ͻ�
 *
 * ���㣺
 * ö�ٳ�Ա�������� int ���ͳ�����
 * �� #define ����ı�ʶ���������ַ��������������ͳ����ȵȡ�
 */

// �����壨��ƹ����壩
// �ͽṹ�����ͣ�ö������һ��������
// union un
// {
//     char c;
//     int i;
// };
// int main()
// {
//     printf("%zd\n", sizeof(union un));
//
//     union un u;
//     printf("%p\n", &u);
//     printf("%p\n", &(u.c));
//     printf("%p\n", &(u.i));
//     return 0;
// }

/*
 * ���ϳ�Ա����ͬһ��ռ�
 * ��ˣ�����ͬʱ�ı��������������ϵ����ϳ�Ա
 *
 * �������͵Ĵ�С
 * ��������
 * 1.����������Ա�Ĵ�С
 * 2.��Ҫ��������Ա��������������
 */

// �жϵ�ǰ�����Ĵ�С�ˣ������ݵĴ洢��������
// int CheckEndian()
// {
//     // �жϺ�����С�˷��� 1����˷��� 0
//     // ����ָ��ʵ��
//     int a = 1;
//     return *(char *)&a;
//
//     // ����������ʵ��
//     union
//     {
//         char c;
//         int i;
//     } u;
//     u.i = 1;
//     return u.c;
// }
// int main()
// {
//     int ret = CheckEndian();
//     if (ret == 1)
//         printf("small endian.\n");
//     else
//         printf("big endian.\n");
//     return 0;
// }