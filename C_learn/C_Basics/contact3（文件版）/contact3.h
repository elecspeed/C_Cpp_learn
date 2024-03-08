#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

enum Option
{
    EXIT,
    ADD,
    DELETE,
    SEARCH,
    MODIFY,
    SHOW,
    SAVE
};

#define MAX_NAME 20
#define MAX_SEX 6
#define MAX_TELE 16
#define MAX_ADDR 30


//�����ṹ��
//�˵���Ϣ����
typedef struct PeoInfo
{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
    int age;
}PeoInfo;

//ͨѶ¼����
typedef struct Contact3
{
    PeoInfo* data;
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
void Contact_delete(Con3* ps);

//��
void Contact_search(Con3* ps);

//��
void Contact_modify(Con3* ps);

//��ӡ
void Contact_print(Con3* ps);

//����
void Contact_destroy(Con3* ps);

//����
void Contact_save(Con3* ps);

//����
void LoadData_to_Contact(Con3* ps);
