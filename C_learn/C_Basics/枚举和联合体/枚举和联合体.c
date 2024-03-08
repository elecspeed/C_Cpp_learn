#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//枚举，即一一列举

//枚举类型
//enum Sex
//{
//    //枚举的可能取值 - 枚举常量
//    MALE,
//    FEMALE,
//    SECRET
//};
//enum Color
//{
//    RED = 2,
//    GREEN,
//    BLUE
//};
//
//int main()
//{
//    //enum Sex s1 = 0;    //不建议
//    enum Sex s2 = MALE;
//    enum Color c = BLUE;
//
//    printf("%d %d %d\n", MALE, FEMALE, SECRET);
//    printf("%d %d %d\n", RED, GREEN, BLUE);
//
//    return 0;
//}
// 枚举常量默认从0开始往后递增1，可以人为改变
// 初始化枚举变量时，尽量使用枚举常量，不建议用int
//

//枚举的工作可以由#define完成，那为什么还要枚举？
//
//枚举的优点（跟#define相比）
// 1.使用方便，一次可以定义多个常量
// 2.通过封装防止命名污染（即名字雷同）
// 3.增加代码的可读性和可维护性
// 4.便于调试。
//   调试时已经经过预处理，#define定义的标识符已经被替换，而我们观察到的是源程序
// 5.相比#define定义的标识符，枚举有类型检查，更严谨
// 

//枚举大小的计算
// 枚举成员其实是int整型常量，那么枚举大小为 成员数 * 4
//



//联合体（或称共用体）

//和结构体类型，枚举类型一样的声明
//union un
//{
//    char c;
//    int i;
//};
//int main()
//{
//    union un u;
//    printf("%zd", sizeof(u));
//
//    printf("%p\n", &u);
//    printf("%p\n", &(u.c));
//    printf("%p\n", &(u.i));
//
//    return 0;
//}
// 联合成员共用同一块空间
// 
// 因此，联合成员不能同时改变两个或两个以上
//

//判断当前机器的大小端（“数据的存储”讲过）
//int check_sys()
//{
//    //利用指针实现
//    int a = 1;
//    return *(char*)&a;
//
//    //利用联合体实现
//    union un
//    {
//        char c;
//        int i;
//    }u;
//    u.i = 1;
//    return u.c;
//}
//int main()
//{
//    int ret = check_sys();
//    if (ret == 1)
//        printf("小端\n");
//    else
//        printf("大端\n");
//
//    return 0;
//}

//联合大小的计算
// 1.联合变量的大小，至少是最大成员的大小
// 2.联合变量的大小，是最大对齐数的整数倍
//
