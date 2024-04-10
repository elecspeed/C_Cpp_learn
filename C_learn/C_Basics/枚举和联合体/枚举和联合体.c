#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 枚举，即一一列举

// 枚举类型
// enum Sex
// {
//     // 枚举的可能取值：枚举成员（或枚举常量）
//     // 枚举成员之间用 , 分隔
//     MALE,
//     FEMALE,
//     SECRET
// };
// enum Color
// {
//     RED,
//     GREEN = 2,
//     BLUE
// };
// int main()
// {
//     // enum Sex s1 = 0; // 不建议
//     enum Sex s2 = MALE;
//     enum Color c = BLUE;
//
//     printf("%d %d %d\n", MALE, FEMALE, SECRET);
//     printf("%d %d %d\n", RED, GREEN, BLUE);
//     printf("%zd\n", sizeof(enum Sex));
//     printf("%zd\n", sizeof(enum Color));
//     return 0;
// }

/*
 * 枚举成员都是 int 整型常量，
 * 默认从 0 开始，默认相邻两个枚举成员相差 1。
 * 可以手动设置成员的值。
 *
 * 初始化枚举变量时，尽量使用枚举成员，不建议用 int 整型常量。
 *
 * 枚举类型的大小
 * sizeof(枚举类型) == sizeof(int)
 *
 * 枚举的工作可以由 #define 完成，那为什么还要枚举？
 *
 * 枚举的优点（跟 #define 相比）
 * 1.一次可以定义多个常量
 * 2.通过封装防止命名冲突
 * 3.增加代码的可读性和可维护性
 * 4.便于调试。
 *   调试时已经经过预处理，#define 定义的标识符会被替换；
 *   而枚举变量不会。
 * 5.相比 #define 定义的标识符，枚举有类型检查，更严谨
 *
 * 不足：
 * 枚举成员本质上是 int 整型常量，
 * 而 #define 定义的标识符可以是字符串常量、浮点型常量等等。
 */

// 联合体（或称共用体）
// 和结构体类型，枚举类型一样的声明
// union un
// {
//     char c;
//     int i;
// };
// int main()
// {
//     printf("%zd\n", sizeof(union un));
//
//     union un u;
//     printf("%p\n", &u);
//     printf("%p\n", &(u.c));
//     printf("%p\n", &(u.i));
//     return 0;
// }

/*
 * 联合成员共用同一块空间
 * 因此，不能同时改变两个或两个以上的联合成员
 *
 * 联合类型的大小
 * 两个规则
 * 1.至少是最大成员的大小
 * 2.还要求是最大成员对齐数的整数倍
 */

// 判断当前机器的大小端（“数据的存储”讲过）
// int CheckEndian()
// {
//     // 判断函数。小端返回 1，大端返回 0
//     // 利用指针实现
//     int a = 1;
//     return *(char *)&a;
//
//     // 利用联合体实现
//     union
//     {
//         char c;
//         int i;
//     } u;
//     u.i = 1;
//     return u.c;
// }
// int main()
// {
//     int ret = CheckEndian();
//     if (ret == 1)
//         printf("small endian.\n");
//     else
//         printf("big endian.\n");
//     return 0;
// }