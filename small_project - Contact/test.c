//1.����1��1000���ѵ�ͨѶ¼
//  ���������䣬�Ա𣬵绰��סַ...
//2.��ɾ���
// a.���Ӻ�����Ϣ
// b.ɾ��
// c.�����ض����ֵĺ�����Ϣ
// d.�޸�
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
    //con���� MAX���˵���Ϣ��size������

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
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            printf("�˳�ͨѶ¼\n");
            break;
        default:
            printf("û�и�ѡ�������ѡ��\n");
            break;
        }
    } while (input);
    return 0;
}
