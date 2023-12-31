#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContact(struct Contact* ps)
{
    ps->data = (struct PeoInfo*)calloc(DEFAULT_SZ, sizeof(struct PeoInfo));
    if (!ps->data)
        return;

    ps->capacity = DEFAULT_SZ;
    ps->size = 0;
}

static void CheckCapacity(struct Contact* ps)
{
    if (ps->size == ps->capacity)
    {
        ps->capacity += 2;
        struct PeoInfo* ptmp = (struct PeoInfo*)realloc(ps->data, (ps->capacity) * sizeof(PeoInfo));
        if (ptmp)
        {
            ps->data = ptmp;
            ptmp = NULL;
            printf("扩容成功！\n");
        }
        else
            printf("扩容失败\n");
    }
}
void AddContact(struct Contact* ps)
{
    //检测通讯录有没有满
    //没满就直接添加
    //满了就扩容后再添加
    CheckCapacity(ps);

    //增加数据
    printf("请输入姓名：");
    scanf("%s", ps->data[ps->size].name);
    printf("请输入性别：");
    scanf("%s", ps->data[ps->size].sex);
    printf("请输入年龄：");
    scanf("%d", &(ps->data[ps->size].age));
    printf("请输入电话：");
    scanf("%s", ps->data[ps->size].tele);
    printf("请输入住址：");
    scanf("%s", ps->data[ps->size].addr);
    
    ps->size++;
    printf("添加成功！\n");
}

static int FindByName(const struct Contact* ps, const char* pc)
{
    int i = 0;
    for (i = 0; i < ps->size; i++)
        if (!strcmp(pc, ps->data[i].name))
            return i;

    return -1;  //找不到返回-1
}
void ShowContact(const struct Contact* ps)
{
    if (ps->size == 0)
    {
        printf("通讯录为空\n");
    }
    else
    {
        printf("%-10s %-6s %-6s %-18s %s\n", "姓名", "性别", "年龄", "电话", "住址");
        int i = 0;
        for (i = 0; i < ps->size; i++)
        {
            printf("%-10s %-6s %-6d %-18s %s\n",
                ps->data[i].name,
                ps->data[i].sex,
                ps->data[i].age,
                ps->data[i].tele,
                ps->data[i].addr);
        }
    }
}

void DelContact(struct Contact* ps)
{
    char name[MAX_NAME] = "\0";
    printf("请输入要删除好友的名字：");
    scanf("%s", name);

    //1.找到要删除好友
    // 该功能还在search，modify函数中出现
    // 那就用函数封装一下
    // 找到了返回相应下标，否则返回-1
    int pos = 0;
    pos = FindByName(ps, name);

    //2.删除
    if (pos == -1)
        printf("要删除的好友不存在\n");
    else
    {
        int j = 0;
        for (j = pos; j < ps->size - 1; j++)
            ps->data[j] = ps->data[j + 1];
        ps->size--;
        printf("删除成功\n");
    }
}

void SearchContact(const struct Contact* ps)
{
    char name[MAX_NAME] = "\0";
    printf("请输入要查找好友的名字：");
    scanf("%s", name);

    int pos = 0;
    pos = FindByName(ps, name);
    if (pos == -1)
        printf("要查找的人不存在");
    else
    {
        printf("%-10s %-6s %-6s %-18s %s\n", "姓名", "性别", "年龄", "电话", "住址");
        printf("%-10s %-6s %-6d %-18s %s\n",
            ps->data[pos].name,
            ps->data[pos].sex,
            ps->data[pos].age,
            ps->data[pos].tele,
            ps->data[pos].addr);
    }
}

void ModifyContact(const struct Contact* ps)
{
    char name[MAX_NAME] = "\0";
    printf("请输入要修改人的名字：");
    scanf("%s", name);

    int pos = 0;
    pos = FindByName(ps, name);
    if (pos == -1)
        printf("要修改的好友不存在\n");
    else
    {
        printf("请输入姓名：");
        scanf("%s", ps->data[pos].name);
        printf("请输入性别：");
        scanf("%s", ps->data[pos].sex);
        printf("请输入年龄：");
        scanf("%d", &(ps->data[pos].age));
        printf("请输入电话：");
        scanf("%s", ps->data[pos].tele);
        printf("请输入住址：");
        scanf("%s", ps->data[pos].addr);

        printf("修改成功！\n");
    }

}

void SortContact(struct Contact* ps)
{
    //可参考“练习使用并手搓qsort”，此处略
    ;
}

void DestroyContact(Contact* ps)
{
    free(ps->data);
    ps->data = NULL;
}