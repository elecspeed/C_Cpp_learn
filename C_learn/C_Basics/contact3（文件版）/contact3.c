#define _CRT_SECURE_NO_WARNINGS 1


#include "contact3.h"


static void Contact_check_IsFull(Con3* ps)
{
    if (ps->size == ps->capacity)
    {
        int newcapacity = (ps->capacity == 0 ? 4 : 2 * ps->capacity);
        PeoInfo* tmp = (PeoInfo*)realloc(ps->data, newcapacity * sizeof(PeoInfo));
        if (!tmp)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        ps->data = tmp;
        tmp = NULL;
        ps->capacity = newcapacity;
    }
}
static void Contact_addition(Con3* ps, int index)
{
    printf("请输入名字：");
    scanf("%s", ps->data[index].name);
    printf("请输入性别：");
    scanf("%s", ps->data[index].sex);
    printf("请输入年龄：");
    scanf("%d", &ps->data[index].age);
    printf("请输入电话：");
    scanf("%s", ps->data[index].tele);
    printf("请输入住址：");
    scanf("%s", ps->data[index].addr);
    ps->size++;
}
static void Move_one_by_one(Con3* ps, int start, char direction)
{
    if (direction == 'R')
    {
        //start 左边的，向右移动一个单位（不包括 start）
        int i = 0;
        for (i = start; i > 0; i--)
            memcpy(ps->data + i, ps->data + i - 1, sizeof(PeoInfo));
    }
    else if (direction == 'L')
    {
        //start 右边的，向左移动一个单位（不包括 start）
        int i = 0;
        for (i = start; i < ps->size; i++)
            memcpy(ps->data + i, ps->data + i + 1, sizeof(PeoInfo));
    }
}
static int Find_name(const char* name, Con3* ps)
{
    int i = 0;
    for (i = 0; i < ps->size; i++)
        if (strcmp(name, ps->data[i].name) == 0)
            return i;

    //找到返回对应下标，找不到返回-1
    return -1;
}
static void Print_PeoInfo(Con3* ps, int index)
{
    //打印下标为 index 的人的信息
    printf("%-8s %-6s %-6d %-20s %s\n",
        ps->data[index].name,
        ps->data[index].sex,
        ps->data[index].age,
        ps->data[index].tele,
        ps->data[index].addr);
}


void Contact_init(Con3* ps)
{
    assert(ps);
    ps->data = NULL;
    ps->capacity = ps->size = 0;

    //把文件中存放的通讯录信息，加载到通讯录中
    LoadData_to_Contact(ps);
}

void LoadData_to_Contact(Con3* ps)
{
    FILE* pfRead = fopen("contact.cat", "rb");
    if (!pfRead)
    {
        perror("LoadData_to_Contact");
        return;
    }

    //读取文件信息放到通讯录
    PeoInfo tmp = { 0 };
    while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
    {
        Contact_check_IsFull(ps);
        ps->data[ps->size] = tmp;
        ps->size++;
    }

    fclose(pfRead);
    pfRead = NULL;
}

void Contact_pushback(Con3* ps)
{
    assert(ps);

    //检查通讯录是否满了
    Contact_check_IsFull(ps);

    //在ps->size处添加
    Contact_addition(ps, ps->size);

    printf("添加成功！\n");
}
void Contact_pushfront(Con3* ps)
{
    assert(ps);

    //检查
    Contact_check_IsFull(ps);

    //在 ps->size 左边的，都向右移动一个单位（不包括 ps->size）
    Move_one_by_one(ps, ps->size, 'R');

    //在 0 处添加
    Contact_addition(ps, 0);

    printf("添加成功！\n");
}
void Contact_insert(Con3* ps, int pos)
{
    ;
}

void Contact_popback(Con3* ps)
{
    assert(ps);
    ps->size--;

    printf("删除成功！\n");
}
void Contact_popfront(Con3* ps)
{
    assert(ps);

    //在 0 右边的，都向左移动一个单位（不包括 0）
    Move_one_by_one(ps, 0, 'L');

    ps->size--;

    printf("删除成功！\n");
}
void Contact_delete(Con3* ps)
{
    assert(ps);

    char name[MAX_NAME];
    printf("请输入要删除的人的名字：");
    scanf("%s", name);

    //找名字。找到了返回下标，找不到返回-1
    int ret = Find_name(name, ps);

    if (ret == -1)
        printf("这个人不存在\n");
    else
    {
        //找到了先看一下
        printf("%-8s %-6s %-6s %-20s %s\n", "名字", "性别", "年龄", "电话", "住址");
        Print_PeoInfo(ps, ret);

        //确认是否要删除
        int input = 0;
        printf("要放弃请输入 0，否则将永久删除：");
        scanf("%d", &input);
        if (!input)
            return;

        //在 ret 右边的，都向左移动一个单位（不包括 ret）
        Move_one_by_one(ps, ret, 'L');
        ps->size--;

        printf("删除成功！\n");
    }
}

void Contact_search(Con3* ps)
{
    assert(ps);

    char name[MAX_NAME];
    printf("请输入要查找的人的名字：");
    scanf("%s", name);

    //找名字。找到了返回下标，找不到返回-1
    int ret = Find_name(name, ps);
    
    if (ret == -1)
        printf("这个人不存在\n");
    else
    {
        //找到了就打印一下
        printf("%-8s %-6s %-6s %-20s %s\n", "名字", "性别", "年龄", "电话", "住址");
        Print_PeoInfo(ps, ret);
    }
}

void Contact_modify(Con3* ps)
{
    assert(ps);
    char name[MAX_NAME];
    printf("请输入要修改的人的名字：");
    scanf("%s", name);

    //找名字。找到了返回下标，找不到返回-1
    int ret = Find_name(name, ps);

    if (ret == -1)
        printf("这个人不存在\n");
    else
    {
        //找到了先看一下
        printf("%-8s %-6s %-6s %-20s %s\n", "名字", "性别", "年龄", "电话", "住址");
        Print_PeoInfo(ps, ret);

        //确认是否要修改
        int input = 0;
        printf("要放弃请输入 0，否则继续修改：");
        scanf("%d", &input);
        if (!input)
            return;

        //修改
        printf("请输入性别：");
        scanf("%s", ps->data[ret].sex);
        printf("请输入年龄：");
        scanf("%d", &ps->data[ret].age);
        printf("请输入电话：");
        scanf("%s", ps->data[ret].tele);
        printf("请输入住址：");
        scanf("%s", ps->data[ret].addr);

        printf("修改成功！\n");
    }
}

void Contact_print(Con3* ps)
{
    assert(ps);
    printf("%-8s %-6s %-6s %-20s %s\n", "名字", "性别", "年龄", "电话", "住址");
    int i = 0;
    for (i = 0; i < ps->size; i++)
        Print_PeoInfo(ps, i);
}

void Contact_destroy(Con3* ps)
{
    assert(ps);
    free(ps->data);
    ps->data = NULL;
}

void Contact_save(Con3* ps)
{
    assert(ps);

    //打开文件
    FILE* pfWrite = fopen("contact.cat", "wb");
    if (!pfWrite)
    {
        perror("Contact_save");
        return;
    }

    //将通讯录中的数据存到文件中
    int i = 0;
    for (i = 0; i < ps->size; i++)
        fwrite(&ps->data[i], sizeof(PeoInfo), 1, pfWrite);

    fclose(pfWrite);
    pfWrite = NULL;

    printf("保存成功！\n");
}

