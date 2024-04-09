#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 结构体类型的声明
// 自引用
// 结构体变量的定义和初始化
// 内存对齐
// 结构体传参
// 结构体实现位段

// 声明一个学生类型
// 描述学生：姓名，年龄，性别，电话...（属性）
// struct Stu
// {
//     char name[15];
//     int age;
//     char sex[7];
//     char telephone[13];
// };
// int main()
// {
//     // 通过学生类型创建结构体变量
//     struct Stu s1;
//     struct Stu s2;
//     return 0;
// }

// 匿名结构体类型（不建议）
// struct
// {
//     int a;
//     char b;
// } anonymousStruct;
// struct
// {
//     int a;
//     char b;
// } *ptr;
// 1.只能声明一次变量
// 2.不能自引用
// 3.两个匿名结构体即使成员变量一样，
//   编译器也会视其为两个不同的结构体。

// 自引用
// struct Node
// {
//     int data;
//     struct Node *next;
//
//     // struct Node n;
//     // 错误。如果我们将错就错，试问 sizeof(struct Node) 是多少？
// };
// 其中 data 是数据域，next 是指针域。
// 结构体的自引用常用来实现复杂数据结构。

// 结构体变量的定义和初始化（略）

// 内存对齐
// struct S1
// {
//     char c1;
//     int a;
//     char c2;
// };
// struct S2
// {
//     char c1;
//     char c2;
//     int a;
// };
// int main()
// {
//     printf("%zd\n", sizeof(struct S1)); // 12
//     printf("%zd\n", sizeof(struct S2)); // 8
//     return 0;
// }

/*
 * 结构体对齐规则
 * 1.第一个成员的地址 == 结构体变量的地址
 * 2.(char*)其他成员地址 - (char*)首成员地址 == 偏移量，
 *   要求：偏移量是对齐数的整数倍
 *
 * > 对齐数有两个：
 * > 编译器默认的对齐数、成员对齐数。
 * > 其中，
 * > 成员对齐数 == 编译器默认的对齐数 与 该成员大小 的较小值
 * >
 * > 常见编译器的对齐数
 * > vs 默认对齐数为 8，gcc 无默认对齐数
 *
 * 3.结构体的总大小为，最大的成员对齐数 的整数倍
 * 4.结构体嵌套
 *   内层结构体的对齐数 == 其内部最大的成员对齐数，其余同上。
 *
 * 意义
 * 1.平台原因：有些硬件平台不能访问任意地址上的任意数据
 * 2.性能原因：数据结构（尤其是栈）要尽可能在自然边界上对齐。
 *            访问未对齐的内存，处理器要访问两次
 *
 * 因此，设计结构体的时候，尽量让占用空间小的成员集中在一起
 */

// 修改编译器的默认对齐数
// #pragma pack(4) // 设置默认对齐数：4
// struct S1
// {
//     char a;
//     double b;
// };
// #pragma pack() // 取消设置
// struct S2
// {
//     char a;
//     double b;
// };
// int main()
// {
//     printf("%zd\n", sizeof(struct S1)); // 12
//     printf("%zd\n", sizeof(struct S2)); // 16
//     return 0;
// }

/*
 * offsetof
 * Retrieves the offset in bytes of a member from
 * the beginning of its parent structure.
 *
 * 宏声明（不是函数）
 * #define offsetof( structName, memberName );
 *
 * 需要 stddef.h 库
 */

// #include <stddef.h>
// struct S
// {
//     char a;
//     int b;
//     double c;
// };
// int main()
// {
//     printf("%zd\n", offsetof(struct S, a));
//     printf("%zd\n", offsetof(struct S, b));
//     printf("%zd\n", offsetof(struct S, c));
//     return 0;
// }

// 手搓 offsetof（百度题）
// #define OFFSETOF(structName, memberName) \
//     (size_t) & (((structName *)0)->memberName)

// 结构体传参
// 建议传指针，理由：
// 1.传值会再开辟一段空间，消耗性能
// 2.传指针可以改变实参

// 位段
struct S
{
    int a : 2;
    int b : 5;
    int c : 10;
    int d : 30;
};
int main()
{
    struct S s = {0, 0, 0, 0};
    printf("%zd\n", sizeof(struct S)); // 8
    // 调试观察
    return 0;
}

/*
 * 位段
 * C 语言允许在一个结构体中以位为单位，
 * 指定其成员所占内存长度。
 * 这种结构体称为位段（或位域）。
 *
 * 声明和结构体类似，两个不同：
 * 1.成员只能是整型，
 *   且最好都是 char 或 short,int,long 中的一个，
 *   signed 还是 unsigned 无所谓。
 * 2.位段的成员名后面跟着一个冒号和一个数字。
 *
 * 冒号加一个数字，表示只取对应个 bit
 * （因为实际情况可能用不到 int 的 4 个字节）
 * 那不应该是 47 个 bit，6 个字节就够了吗？
 *
 * 位段的内存分配
 * 1.位段的空间是以一个位段为单位（1 或 4 个字节）开辟的。
 * 2.位段的很多东西标准没有规定，不同编译器下运行结果不同。
 *
 * 位段的跨平台问题
 * 1.int 位段被当成有符号数还是无符号数？不确定
 * 2.int a : 17;
 *   在 32 位机器上可以，在 16 位机器上就会出问题
 * 3.位段成员是从高到低分配内存，还是从低到高？不确定
 * 4.一个位段剩余的 bit 容不下下一个成员，
 *   对剩余的 bit 是舍弃还是利用？
 *   不确定
 *
 * 对于问题 4，vs 选择舍弃剩余的 bit，再开一个位段。
 *
 * 位段的应用场景
 * 1.网络传输的数据包。数据包的包头可以用位段压缩空间
 * 2.STM32F10xxx 系列中的应用。
 */