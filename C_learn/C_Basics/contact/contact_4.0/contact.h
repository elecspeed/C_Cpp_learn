#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 15
#define MAX_SEX 7
#define MAX_AGE 4
#define MAX_TELEPHONE 15
#define MAX_ADDRESS 20

enum Option
{
    EXIT,
    DISPLAY,
    ADD,
    ERASE,
    SEARCH,
    MODIFY,
    SAVE
};

struct person
{
    // 人类型
    char _name[MAX_NAME];
    char _sex[MAX_SEX];
    char _age[MAX_AGE];
    char _telephone[MAX_TELEPHONE];
    char _address[MAX_ADDRESS];
};
typedef struct person person;
#define SIZE_PERSON (sizeof(person))
struct contact
{
    // 通讯录类型
    person *_data; // 人的信息
    int _capacity; // 数组容量
    int _size;     // 数组元素个数，即联系人个数
};
typedef struct contact contact;
#define SIZE_CONTACT (sizeof(contact))

void InitContact(contact *cont);
void DisplayContact(contact *cont);
void AddContact(contact *cont);
void EraseContact(contact *cont);
void SearchContact(contact *cont);
void ModifyContact(contact *cont);
void SaveContact(contact *cont);
void DestroyContact(contact *cont);

#endif