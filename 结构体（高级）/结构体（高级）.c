#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



//结构体类型的声明
//自引用
//结构体变量的定义和初始化
//内存对齐
//结构体传参
//结构体实现位段

//位段
// 
// 声明和结构体类似，两个不同：
// 1.成员只能是整型，且最好只有char、short、int、long中的一个，符号不做要求
// 2.段位的成员名后面有一个冒号和一个数字
//
//struct S
//{
//    int a : 2;
//    int b : 5;
//    int c : 10;
//    int d : 30;
//};
//int main()
//{
//    struct S s;
//    printf("%zd\n", sizeof(s));
//    return 0;
//}
//结果是8
//冒号加一个数字表示只取这么多个bit（因为实际情况可能用不到int的4个字节）
//那不应该是47个bit，6个字节就够了吗？

//位段的内存分配
// 1.段位的空间是按照需要以4个字节或1个字节（一个位段）来开辟的
// 2.段位的很多东西标准没有规定，不同编译器下运行结果不同

//位段的跨平台问题
// 1.int位段被当成有符号数还是无符号数不确定
// 2.int a : 17; 在32位机器上可以，在16位机器上就会出问题
// 3.段位成员是从左往右分配内存，还是从右往左分配不确定
// 4.一个位段剩余的bit容不下一个成员，对剩余的bit是舍弃还是利用不确定
// 
// vs环境下剩余的bit舍弃，再开一个位段
//

//位段的应用场景：网络传输的数据包。数据包的包头可以用位段压缩空间



//结构体传参
//建议传指针，原因：
//1.传值会再开辟一段空间，消耗性能
//2.传指针可以改变实参



//内存对齐
//struct S1
//{
//    char c1;
//    int a;
//    char c2;
//};
//struct S2
//{
//    char c1;
//    char c2;
//    int a;
//};
//int main()
//{
//    struct S1 s1 = { 0 };
//    printf("%zd\n", sizeof(s1));  //12
//    
//    struct S2 s2 = { 0 };
//    printf("%zd\n", sizeof(s2));  //8
//
//    return 0;
//}
// 结构体对齐规则
// 1.第一个成员的地址 == 结构体变量的地址（只是地址相等，访问长度不相等）
// 2.在不冲突的前提下，其他成员的地址是 从首成员地址往后的 对齐数的整数倍的 地址
//   （即如果设偏移量 = 该成员地址 - 首成员地址，则偏移量是对齐数的整数倍）
// 
// 对齐数 == 编译器默认的对齐数 与 该成员大小 的较小值
// vs默认对齐数为8，gcc无默认对齐数
// 
// 3.结构体总大小为，成员中最大对齐数的整数倍
// 4.结构体嵌套
//   内层结构体的对齐数是其本身的最大对齐数，其余同上
// 
// 意义
// 1.平台原因：有些硬件平台不能访问任意地址上的任意数据
// 2.性能原因：数据结构（尤其是栈）要尽可能在自然边界上对齐。访问未对齐的内存，处理器要访问两次
//             也即，以空间换时间
// 
// 因此，设计结构体的时候，尽量让占用空间小的成员集中在一起
//

//修改默认对齐数
//
//#pragma pack(4)     //设置默认的对齐数是4
//struct S
//{
//    char a;
//    double b;
//};
//#pragma pack()      //取消设置的默认对齐数
//
//int main()
//{
//    struct S s;
//    printf("%zd\n", sizeof s);
//    return 0;
//}

//offsetof
// Retrieves the offset of a member from the beginning of its parent structure.
// 计算偏移量
// 
// 宏声明（不是函数）
// size_t offsetof( structName, memberName );
// 
// 需要stddef库
//
//#include <stddef.h>
//struct S
//{
//    char a;
//    int b;
//    double c;
//};
//int main()
//{
//    printf("%d\n", offsetof(struct S, a));
//    printf("%d\n", offsetof(struct S, b));
//    printf("%d\n", offsetof(struct S, c));
//
//    return 0;
//}

//手搓offsetof（百度题。待续，学到宏再补上）



//结构体变量的定义和初始化（略）



//自引用
//struct Node
//{
//    int data;
// 
//    //struct Node n;    //error。如果可以，那sizeof(struct Node)是多少？
//    struct Node* next;
//};
//其中data是数据域，next是指针域



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

//匿名结构体类型（只能用一次而且还不能自引用，不建议）
//struct
//{
//    int a;
//    char b;
//}x;
//struct
//{
//    int a;
//    char b;
//}* px;
//两个匿名结构体即使成员变量一样，编译器也会当成两个不同的结构体（不能px = &x;）