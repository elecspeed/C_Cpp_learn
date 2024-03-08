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
    printf("���������֣�");
    scanf("%s", ps->data[index].name);
    printf("�������Ա�");
    scanf("%s", ps->data[index].sex);
    printf("���������䣺");
    scanf("%d", &ps->data[index].age);
    printf("������绰��");
    scanf("%s", ps->data[index].tele);
    printf("������סַ��");
    scanf("%s", ps->data[index].addr);
    ps->size++;
}
static void Move_one_by_one(Con3* ps, int start, char direction)
{
    if (direction == 'R')
    {
        //start ��ߵģ������ƶ�һ����λ�������� start��
        int i = 0;
        for (i = start; i > 0; i--)
            memcpy(ps->data + i, ps->data + i - 1, sizeof(PeoInfo));
    }
    else if (direction == 'L')
    {
        //start �ұߵģ������ƶ�һ����λ�������� start��
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

    //�ҵ����ض�Ӧ�±꣬�Ҳ�������-1
    return -1;
}
static void Print_PeoInfo(Con3* ps, int index)
{
    //��ӡ�±�Ϊ index ���˵���Ϣ
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

    //���ļ��д�ŵ�ͨѶ¼��Ϣ�����ص�ͨѶ¼��
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

    //��ȡ�ļ���Ϣ�ŵ�ͨѶ¼
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

    //���ͨѶ¼�Ƿ�����
    Contact_check_IsFull(ps);

    //��ps->size�����
    Contact_addition(ps, ps->size);

    printf("��ӳɹ���\n");
}
void Contact_pushfront(Con3* ps)
{
    assert(ps);

    //���
    Contact_check_IsFull(ps);

    //�� ps->size ��ߵģ��������ƶ�һ����λ�������� ps->size��
    Move_one_by_one(ps, ps->size, 'R');

    //�� 0 �����
    Contact_addition(ps, 0);

    printf("��ӳɹ���\n");
}
void Contact_insert(Con3* ps, int pos)
{
    ;
}

void Contact_popback(Con3* ps)
{
    assert(ps);
    ps->size--;

    printf("ɾ���ɹ���\n");
}
void Contact_popfront(Con3* ps)
{
    assert(ps);

    //�� 0 �ұߵģ��������ƶ�һ����λ�������� 0��
    Move_one_by_one(ps, 0, 'L');

    ps->size--;

    printf("ɾ���ɹ���\n");
}
void Contact_delete(Con3* ps)
{
    assert(ps);

    char name[MAX_NAME];
    printf("������Ҫɾ�����˵����֣�");
    scanf("%s", name);

    //�����֡��ҵ��˷����±꣬�Ҳ�������-1
    int ret = Find_name(name, ps);

    if (ret == -1)
        printf("����˲�����\n");
    else
    {
        //�ҵ����ȿ�һ��
        printf("%-8s %-6s %-6s %-20s %s\n", "����", "�Ա�", "����", "�绰", "סַ");
        Print_PeoInfo(ps, ret);

        //ȷ���Ƿ�Ҫɾ��
        int input = 0;
        printf("Ҫ���������� 0����������ɾ����");
        scanf("%d", &input);
        if (!input)
            return;

        //�� ret �ұߵģ��������ƶ�һ����λ�������� ret��
        Move_one_by_one(ps, ret, 'L');
        ps->size--;

        printf("ɾ���ɹ���\n");
    }
}

void Contact_search(Con3* ps)
{
    assert(ps);

    char name[MAX_NAME];
    printf("������Ҫ���ҵ��˵����֣�");
    scanf("%s", name);

    //�����֡��ҵ��˷����±꣬�Ҳ�������-1
    int ret = Find_name(name, ps);
    
    if (ret == -1)
        printf("����˲�����\n");
    else
    {
        //�ҵ��˾ʹ�ӡһ��
        printf("%-8s %-6s %-6s %-20s %s\n", "����", "�Ա�", "����", "�绰", "סַ");
        Print_PeoInfo(ps, ret);
    }
}

void Contact_modify(Con3* ps)
{
    assert(ps);
    char name[MAX_NAME];
    printf("������Ҫ�޸ĵ��˵����֣�");
    scanf("%s", name);

    //�����֡��ҵ��˷����±꣬�Ҳ�������-1
    int ret = Find_name(name, ps);

    if (ret == -1)
        printf("����˲�����\n");
    else
    {
        //�ҵ����ȿ�һ��
        printf("%-8s %-6s %-6s %-20s %s\n", "����", "�Ա�", "����", "�绰", "סַ");
        Print_PeoInfo(ps, ret);

        //ȷ���Ƿ�Ҫ�޸�
        int input = 0;
        printf("Ҫ���������� 0����������޸ģ�");
        scanf("%d", &input);
        if (!input)
            return;

        //�޸�
        printf("�������Ա�");
        scanf("%s", ps->data[ret].sex);
        printf("���������䣺");
        scanf("%d", &ps->data[ret].age);
        printf("������绰��");
        scanf("%s", ps->data[ret].tele);
        printf("������סַ��");
        scanf("%s", ps->data[ret].addr);

        printf("�޸ĳɹ���\n");
    }
}

void Contact_print(Con3* ps)
{
    assert(ps);
    printf("%-8s %-6s %-6s %-20s %s\n", "����", "�Ա�", "����", "�绰", "סַ");
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

    //���ļ�
    FILE* pfWrite = fopen("contact.cat", "wb");
    if (!pfWrite)
    {
        perror("Contact_save");
        return;
    }

    //��ͨѶ¼�е����ݴ浽�ļ���
    int i = 0;
    for (i = 0; i < ps->size; i++)
        fwrite(&ps->data[i], sizeof(PeoInfo), 1, pfWrite);

    fclose(pfWrite);
    pfWrite = NULL;

    printf("����ɹ���\n");
}

