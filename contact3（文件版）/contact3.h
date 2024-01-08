#define _CRT_SECURE_NO_WARNINGS 1




#include <stdio.h>
#include <assert.h>
#include <stdlib.h>





//�����ṹ��
//�˵���Ϣ����
typedef struct PeoInfo
{
    char name[10];
    char sex[6];
    char tele[16];
    char addr[30];
    int age;
}PeoInfo;

typedef PeoInfo SLDataType;

//ͨѶ¼����
typedef struct Contact3
{
    SLDataType* data;
    int size;       //��ǰ���Ѹ���
    int capacity;   //ͨѶ¼��ǰ������
}Con3;


//��������
//��ʼ��
void Contact_init(Con3* ps);

//��
void Contact_pushback(Con3* ps);
void Contact_pushfront(Con3* ps);
void Contact_insert(Con3* ps, int pos);      //�ɲ�������λ�ã��ù�������

//ɾ
void Contact_popback(Con3* ps);
void Contact_popfront(Con3* ps);
void Contact_delete(Con3* ps, int pos);       //��ɾ������λ�ã��ù�������

//��
void Contact_search(Con3* ps);

//��
void Contact_modify(Con3* ps);

//��ӡ
void Contact_print(Con3* ps);

//����
void Contact_destroy(Con3* ps);


