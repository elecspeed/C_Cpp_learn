#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



//�ṹ�����͵�����
//������
//�ṹ������Ķ���ͳ�ʼ��
//�ڴ����
//�ṹ�崫��
//�ṹ��ʵ��λ��

//offsetof
// Retrieves the offset of a member from the beginning of its parent structure.
// ����ƫ����
// 
// �����������Ǻ�����
// size_t offsetof( structName, memberName );
// 
// ��Ҫstddef��
//
//#include <stddef.h>
//struct S
//{
//    char a;
//    int b;
//    double c;
//};
//int main()
//{
//    printf("%llu\n", offsetof(struct S, a));
//    printf("%llu\n", offsetof(struct S, b));
//    printf("%llu\n", offsetof(struct S, c));
//
//    return 0;
//}

//�ִ�offsetof��������ѧ�����ٲ��ϣ�


//�ڴ����
//struct S1
//{
//    char c1;
//    int a;
//    char c2;
//};
//struct S2
//{
//    char c1;
//    char c2;
//    int a;
//};
//int main()
//{
//    struct S1 s1 = { 0 };
//    printf("%zd\n", sizeof(s1));//12��4��char��+ 4��int��+ 4��char��
//    
//    struct S2 s2 = { 0 };
//    printf("%zd\n", sizeof(s2));//8��4������char��+ 4��int��
//
//    return 0;
//}
// �ṹ��������
// 1.��һ����Ա�ĵ�ַ == �ṹ������ĵ�ַ��ֻ�ǵ�ַ��ȣ����ʳ��Ȳ���ȣ�
// 2.�ڲ���ͻ��ǰ���£�������Ա�ĵ�ַ�Ǵ��׳�Ա��ַ����� ���������������� ��ַ
//   ����ƫ�����Ƕ���������������
// 3.�ṹ���ܴ�СΪ����Ա������������������
// 
// ������ == ������Ĭ�ϵĶ����� �� �ó�Ա��С �Ľ�Сֵ
// vsĬ�϶�����Ϊ8��gcc��Ĭ�϶�����
// 
// 4.�ṹ��Ƕ��
//   �ڲ�ṹ��Ķ��������䱾�����������������ͬ��
// 
// ����
// 1.ƽ̨ԭ����ЩӲ��ƽ̨���ܷ��������ַ�ϵ���������
// 2.����ԭ�����ݽṹ��������ջ��Ҫ����������Ȼ�߽��϶��롣����δ������ڴ棬������Ҫ��������
//             Ҳ�����Կռ任ʱ��
// 
// ��ˣ���ƽṹ���ʱ�򣬾�����ռ�ÿռ�С�ĳ�Ա������һ��
//

//�޸�Ĭ�϶�����
//
//#pragma pack(4)     //����Ĭ�ϵĶ�������4
//struct S
//{
//    char a;
//    double b;
//};
//#pragma pack()      //ȡ�����õ�Ĭ�϶�����
//
//int main()
//{
//    struct S s;
//    printf("%zd\n", sizeof s);
//    return 0;
//}



//�ṹ������Ķ���ͳ�ʼ�����ԣ�



//������
//struct Node
//{
//    int data;
// 
//    //struct Node n;    //error��������ԣ���sizeof(struct Node)�Ƕ��٣�
//    struct Node* next;
//};
//����data��������next��ָ����



//����һ��ѧ�����ͣ�ͨ��ѧ�����ʹ���ѧ������
//����ѧ�������������䣬�Ա𣬵绰...�����ԣ�
//struct Stu
//{
//    char name[20];
//    int age;
//    char sex[5];
//    char tele[12];
//};
//int main()
//{
//    //�����ṹ�����
//    struct Stu s1;
//    struct Stu s2;
//    return 0;
//}

//�����ṹ�����ͣ�ֻ����һ�ζ��һ����������ã������飩
//struct
//{
//    int a;
//    char b;
//}x, xarr[5];
//struct
//{
//    int a;
//    char b;
//}* px;
//���������ṹ�弴ʹ��Ա����һ����������Ҳ�ᵱ��������ͬ�Ľṹ�壨����px = &x;��