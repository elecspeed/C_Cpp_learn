//1.创建1个1000好友的通讯录
//  姓名，年龄，性别，电话，住址...
//2.增删查改
// a.增加好友信息
// b.删除
// c.查找特定名字的好友信息
// d.修改
//3.打印好友信息
//4.排序
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
    //创建通讯录
    struct Contact con;
    //con包含 MAX个人的信息和size个好友

    //初始化通讯录
    InitContact(&con);
    int input = 0;
    do
    {
        menu();
        printf("请选择：\n");
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
            printf("退出通讯录\n");
            break;
        default:
            printf("没有该选项，请重新选择\n");
            break;
        }
    } while (input);
    return 0;
}
