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
            printf("���ݳɹ���\n");
        }
        else
            printf("����ʧ��\n");
    }
}
void AddContact(struct Contact* ps)
{
    //���ͨѶ¼��û����
    //û����ֱ�����
    //���˾����ݺ������
    CheckCapacity(ps);

    //��������
    printf("������������");
    scanf("%s", ps->data[ps->size].name);
    printf("�������Ա�");
    scanf("%s", ps->data[ps->size].sex);
    printf("���������䣺");
    scanf("%d", &(ps->data[ps->size].age));
    printf("������绰��");
    scanf("%s", ps->data[ps->size].tele);
    printf("������סַ��");
    scanf("%s", ps->data[ps->size].addr);
    
    ps->size++;
    printf("��ӳɹ���\n");
}

static int FindByName(const struct Contact* ps, const char* pc)
{
    int i = 0;
    for (i = 0; i < ps->size; i++)
        if (!strcmp(pc, ps->data[i].name))
            return i;

    return -1;  //�Ҳ�������-1
}
void ShowContact(const struct Contact* ps)
{
    if (ps->size == 0)
    {
        printf("ͨѶ¼Ϊ��\n");
    }
    else
    {
        printf("%-10s %-6s %-6s %-18s %s\n", "����", "�Ա�", "����", "�绰", "סַ");
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
    printf("������Ҫɾ�����ѵ����֣�");
    scanf("%s", name);

    //1.�ҵ�Ҫɾ������
    // �ù��ܻ���search��modify�����г���
    // �Ǿ��ú�����װһ��
    // �ҵ��˷�����Ӧ�±꣬���򷵻�-1
    int pos = 0;
    pos = FindByName(ps, name);

    //2.ɾ��
    if (pos == -1)
        printf("Ҫɾ���ĺ��Ѳ�����\n");
    else
    {
        int j = 0;
        for (j = pos; j < ps->size - 1; j++)
            ps->data[j] = ps->data[j + 1];
        ps->size--;
        printf("ɾ���ɹ�\n");
    }
}

void SearchContact(const struct Contact* ps)
{
    char name[MAX_NAME] = "\0";
    printf("������Ҫ���Һ��ѵ����֣�");
    scanf("%s", name);

    int pos = 0;
    pos = FindByName(ps, name);
    if (pos == -1)
        printf("Ҫ���ҵ��˲�����");
    else
    {
        printf("%-10s %-6s %-6s %-18s %s\n", "����", "�Ա�", "����", "�绰", "סַ");
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
    printf("������Ҫ�޸��˵����֣�");
    scanf("%s", name);

    int pos = 0;
    pos = FindByName(ps, name);
    if (pos == -1)
        printf("Ҫ�޸ĵĺ��Ѳ�����\n");
    else
    {
        printf("������������");
        scanf("%s", ps->data[pos].name);
        printf("�������Ա�");
        scanf("%s", ps->data[pos].sex);
        printf("���������䣺");
        scanf("%d", &(ps->data[pos].age));
        printf("������绰��");
        scanf("%s", ps->data[pos].tele);
        printf("������סַ��");
        scanf("%s", ps->data[pos].addr);

        printf("�޸ĳɹ���\n");
    }

}

void SortContact(struct Contact* ps)
{
    //�ɲο�����ϰʹ�ò��ִ�qsort�����˴���
    ;
}

void DestroyContact(Contact* ps)
{
    free(ps->data);
    ps->data = NULL;
}