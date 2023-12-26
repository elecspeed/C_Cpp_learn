#define _CRT_SECURE_NO_WARNINGS 1

//结构体类型的声明
//自引用
//结构体变量的定义和初始化
//内存对齐
//结构体传参
//结构体实现位段

//自引用
struct Node
{
    int data;
    struct Node n;
};



//匿名结构体类型（只能用一次）
struct
{
    int a;
    char b;
}x, xarr[5];
struct
{
    int a;
    char b;
}* px;
//两个匿名结构体即使成员变量一样，编译器也会当成两个不同的结构体（不能px = &x;）


//声明一个学生类型，通过学生类型创建学生变量
//描述学生：姓名，年龄，性别，电话...（属性）
//struct Stu
//{
//    char name[20];
//    int age;
//    char sex[5];
//    char tele[12];
//};
//int main()
//{
//    //创建结构体变量
//    struct Stu s1;
//    struct Stu s2;
//    return 0;
//}
