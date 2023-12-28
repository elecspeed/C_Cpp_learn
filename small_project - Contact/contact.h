#define _CRT_SECURE_NO_WARNINGS 1

#define MAX 1000

#define MAX_NAME 10
#define MAX_SEX 6
#define MAX_TELE 15
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>

enum Option
{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT
};


//�ṹ����������

//�˵���Ϣ����
struct PeoInfo
{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
    int age;
};
//ͨѶ¼����
struct Contact
{
    struct PeoInfo data[MAX];   //�ܹ���MAX���˵���Ϣ
    int size;                   //��ǰ��size������
};


//��������
//��ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contact* ps);

//����һ��������Ϣ��ͨѶ¼�ĺ���
void AddContact(struct Contact* ps);
 
//��ӡͨѶ¼�е���Ϣ
void ShowContact(const struct Contact* ps);

//ɾ��ָ�����ֵĺ�����Ϣ
void DelContact(struct Contact* ps);

//����ָ�����ֵĺ�����Ϣ
void SearchContact(const struct Contact* ps);

//�޸�ָ�����ֵĺ�����Ϣ
void ModifyContact(const struct Contact* ps);

//����ͨѶ¼����
void SortContact(struct Contact* ps);
