#define _CRT_SECURE_NO_WARNINGS 1




#include <stdio.h>
#include <assert.h>
#include <stdlib.h>





//声明结构体
//人的信息类型
typedef struct PeoInfo
{
    char name[10];
    char sex[6];
    char tele[16];
    char addr[30];
    int age;
}PeoInfo;

typedef PeoInfo SLDataType;

//通讯录类型
typedef struct Contact3
{
    SLDataType* data;
    int size;       //当前好友个数
    int capacity;   //通讯录当前的容量
}Con3;


//声明函数
//初始化
void Contact_init(Con3* ps);

//增
void Contact_pushback(Con3* ps);
void Contact_pushfront(Con3* ps);
void Contact_insert(Con3* ps, int pos);      //可插入任意位置，该功能暂无

//删
void Contact_popback(Con3* ps);
void Contact_popfront(Con3* ps);
void Contact_delete(Con3* ps, int pos);       //可删除任意位置，该功能暂无

//查
void Contact_search(Con3* ps);

//改
void Contact_modify(Con3* ps);

//打印
void Contact_print(Con3* ps);

//销毁
void Contact_destroy(Con3* ps);


