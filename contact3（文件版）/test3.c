#define _CRT_SECURE_NO_WARNINGS 1

#include "contact3.h"


void menu()
{
    printf("*******************************\n");
    printf("*****  1.add    2.delete  *****\n");
    printf("*****  3.search 4.modify  *****\n");
    printf("*****  5.show   6.save    *****\n");
    printf("*****  0.exit             *****\n");
    printf("*******************************\n");
}
int main()
{
    printf("欢迎来到通讯录！\n");
    Con3 con;

    //初始化通讯录
    Contact_init(&con);
    int input = 0;
    do
    {
        menu();
        printf("请选择：");
        scanf("%d", &input);
        switch(input)
        {
        case ADD:
            Contact_pushback(&con);
            break;
        case DELETE:
            Contact_delete(&con);
            break;
        case SEARCH:
            Contact_search(&con);
            break;
        case MODIFY:
            Contact_modify(&con);
            break;
        case SHOW:
            Contact_print(&con);
            break;
        case SAVE:
            Contact_save(&con);
            break;
        case EXIT:
            Contact_save(&con);
            Contact_destroy(&con);
            printf("退出通讯录\n");
            break;
        default:
            printf("没有该选项\n");
            break; 
        }
    } while (input);

    return 0;
}

