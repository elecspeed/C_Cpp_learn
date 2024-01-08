#define _CRT_SECURE_NO_WARNINGS 1

#include "contact3.h"


void test()
{
    Con3 con;

    Contact_init(&con);
    Contact_pushback(&con);
    Contact_pushback(&con);
    Contact_print(&con);

    Contact_popback(&con);


    Contact_destroy(&con);
}
int main()
{
    //Con3 con = { NULL, 0, 0 };
    //do
    //{
    //    Contact_head_insert(&con);
    //}
    test();

    return 0;
}


