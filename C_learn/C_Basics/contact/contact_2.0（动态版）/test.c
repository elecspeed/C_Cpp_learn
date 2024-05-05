#define _CRT_SECURE_NO_WARNINGS 1

//1.创建1个1000好友的通讯录
//  姓名，年龄，性别，电话，住址...
//2.增删查改
// a.增加好友信息
// b.删除
// c.查找
// d.修改
// 其中删查改用名字作索引
// 
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
    //con包含 指向动态通讯录的指针、通讯录的容量（单位是人） 和 size个好友

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
            //销毁通讯录-释放动态开辟的内存
            DestroyContact(&con);
            printf("退出通讯录\n");
            break;
        default:
            printf("没有该选项，请重新选择\n");
            break;
        }
    } while (input);
    return 0;
}
