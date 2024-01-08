#define _CRT_SECURE_NO_WARNINGS 1


#include "contact3.h"

void Contact_init(Con3* ps)
{
    ps->data = NULL;
    ps->capacity = ps->size = 0;
}

void Contact_pushback(Con3* ps)
{
    assert(ps);
    if (ps->size == ps->capacity)
    {
        int newcapacity = ( ps->capacity == 0 ? 4 : 2 * ps->capacity );
        SLDataType* tmp = (SLDataType*)realloc(ps->data, newcapacity * sizeof(SLDataType));
        if (!tmp)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        ps->data = tmp;
        tmp = NULL;
        ps->capacity = newcapacity;
    }
    printf("请输入名字：");
    scanf("%s", ps->data[ps->size].name);
    printf("请输入性别：");
    scanf("%s", ps->data[ps->size].sex);
    printf("请输入年龄：");
    scanf("%d", &ps->data[ps->size].age);
    printf("请输入电话：");
    scanf("%s", ps->data[ps->size].tele);
    printf("请输入住址：");
    scanf("%s", ps->data[ps->size].addr);
    ps->size++;
}

void Contact_pushfront(Con3* ps);
void Contact_popback(Con3* ps)
{
    ps->size--;
}
void Contact_popfront(Con3* ps);
void Contact_search(Con3* ps);
void Contact_modify(Con3* ps);

void Contact_print(Con3* ps)
{
    printf("%-8s %-6s %-6s %-20s %s\n", "名字", "性别", "年龄", "电话", "住址");
    int i = 0;
    for(i = 0; i < ps->size; i++)
    {
        printf("%-8s %-6s %-6d %-20s %s\n", 
            ps->data[i].name,
            ps->data[i].sex,
            ps->data[i].age,
            ps->data[i].tele,
            ps->data[i].addr);
    }
}

void Contact_destroy(Con3* ps)
{
    free(ps->data);
    ps->data = NULL;
}


