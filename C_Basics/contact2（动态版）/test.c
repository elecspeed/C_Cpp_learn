#define _CRT_SECURE_NO_WARNINGS 1

//1.����1��1000���ѵ�ͨѶ¼
//  ���������䣬�Ա𣬵绰��סַ...
//2.��ɾ���
// a.���Ӻ�����Ϣ
// b.ɾ��
// c.����
// d.�޸�
// ����ɾ���������������
// 
//3.��ӡ������Ϣ
//4.����
//......

#include "contact.h"

void menu()
{
    printf("********************************\n");
    printf("*****  1.add     2.del     *****\n");
    printf("*****  3.search  4.modify  *****\n");
    printf("*****  5.show    6.sort    *****\n");
    printf("*****  0.exit              *****\n");
    printf("********************************\n");
}
int main()
{
    //����ͨѶ¼
    struct Contact con;
    //con���� ָ��̬ͨѶ¼��ָ�롢ͨѶ¼����������λ���ˣ� �� size������

    //��ʼ��ͨѶ¼
    InitContact(&con);
    int input = 0;
    do
    {
        menu();
        printf("��ѡ��\n");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            AddContact(&con);
            break;
        case DEL:
            DelContact(&con);
            break;
        case SEARCH:
            SearchContact(&con);
            break;
        case MODIFY:
            ModifyContact(&con);
            break;
        case SHOW:
            ShowContact(&con);
            break;
        case SORT:
            SortContact(&con);
            break;
        case EXIT:
            //����ͨѶ¼-�ͷŶ�̬���ٵ��ڴ�
            DestroyContact(&con);
            printf("�˳�ͨѶ¼\n");
            break;
        default:
            printf("û�и�ѡ�������ѡ��\n");
            break;
        }
    } while (input);
    return 0;
}
