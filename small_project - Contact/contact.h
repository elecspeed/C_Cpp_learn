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


//结构体类型声明

//人的信息类型
struct PeoInfo
{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
    int age;
};
//通讯录类型
struct Contact
{
    struct PeoInfo data[MAX];   //总共有MAX个人的信息
    int size;                   //当前有size个好友
};


//函数声明
//初始化通讯录的函数
void InitContact(struct Contact* ps);

//增加一个好友信息到通讯录的函数
void AddContact(struct Contact* ps);
 
//打印通讯录中的信息
void ShowContact(const struct Contact* ps);

//删除指定名字的好友信息
void DelContact(struct Contact* ps);

//查找指定名字的好友信息
void SearchContact(const struct Contact* ps);

//修改指定名字的好友信息
void ModifyContact(const struct Contact* ps);

//排序通讯录内容
void SortContact(struct Contact* ps);
