#define _CRT_SECURE_NO_WARNINGS 1

//�ṹ�����͵�����
//������
//�ṹ������Ķ���ͳ�ʼ��
//�ڴ����
//�ṹ�崫��
//�ṹ��ʵ��λ��

//������
struct Node
{
    int data;
    struct Node n;
};



//�����ṹ�����ͣ�ֻ����һ�Σ�
struct
{
    int a;
    char b;
}x, xarr[5];
struct
{
    int a;
    char b;
}* px;
//���������ṹ�弴ʹ��Ա����һ����������Ҳ�ᵱ��������ͬ�Ľṹ�壨����px = &x;��


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
