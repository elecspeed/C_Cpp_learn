#define _CRT_SECURE_NO_WARNINGS 1

#define MAX 100

#define MAX_NAME 20
#define MAX_SEX 6
#define MAX_TELE 15
#define MAX_ADDR 20


#include <stdio.h>
#include <string.h>


//�ṹ����������
struct PeoInfo
{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
    int age;
};
struct Contact
{
    struct PeoInfo data[MAX];
    int size;
};


//��������
void InitContact(struct Contact* ps);

