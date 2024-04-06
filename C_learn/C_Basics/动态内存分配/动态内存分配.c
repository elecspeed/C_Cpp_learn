#define _CRT_SECURE_NO_WARNINGS 1

// 为什么要动态内存分配
// 动态内存函数
// C/C++ 程序的内存开辟
// 题目
// 柔性数组

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*
 * 内存可以分为三大区域：栈区，堆区和静态区
 *
 * 栈区：局部变量，形参，函数调用等
 * 堆区：动态内存分配。相关函数 malloc/free,realloc,calloc 等
 * 静态区：全局变量，静态变量等
 *
 * 在此之前，我们使用内存的方式
 * 1.创建变量
 * 2.创建数组

 * 两种开辟内存的方式有以下特点：
 * 1.开辟的空间大小是固定的
 * 2.在程序运行前就分配好空间，运行后不能改变
 *
 * （C 语言其实可以创建柔性数组，
 * （但是柔性数组是在 C99 之后才出现的，
 * （多数程序员也已经习惯了另一种实现方式。）
 *
 * 栈区数组并不能根据需求伸长或缩短，
 * 只能事先猜测，可能需要多少元素个数
 * （从内存上去理解）
 * 而动态内存分配可以很好地解决这个问题
 */

// 动态内存函数（malloc/free,realloc,calloc 等）

/*
 * 1.malloc
 * 开辟连续的内存空间
 *
 * 声明
 * void *malloc( size_t size );
 * size 表示要开辟的字节数
 * 返回开辟空间的首地址 或 NULL（可能没有足够的空间）
 *
 * 需要 stdlib.h 库或 malloc.h 库
 * （free,realloc,calloc 同）
 */

// int main()
// {
//     // 向内存申请 10 个整型的空间
//     int *p = (int *)malloc(10 * sizeof(int));
//     // （有些编译器可以自动类型转换，但强制类型转换总没错）
//     // 试试申请超级大的空间
//     // int* p = (int*)malloc(ULLONG_MAX);
//
//     if (p == NULL)
//     {
//         // 打印错误原因
//         printf("%s\n", strerror(errno));
//     }
//     else
//     {
//         // 正常使用
//         int i = 0;
//         for (i = 0; i < 10; i++)
//             p[i] = i;
//         for (i = 0; i < 10; i++)
//             printf("%d ", *(p + i));
//     }
//
//     // 用完空间要主动回收
//     // 虽然程序结束也能回收，但会有内存泄漏的风险
//     free(p);  // 释放空间
//     p = NULL; // 处理野指针
//     return 0;
// }
// 注意事项：
// 1.即使开辟的内存很小，也要检查 melloc 返回值
// 2.标准没有定义参数 size 为 0 的情况
// 3.在堆区连续开辟空间，开辟出的空间的首地址没有高低顺序

/*
 * 2.free
 * 回收或释放一块动态内存空间
 *
 * 声明
 * void free( void *memblock );
 *
 * memblock：动态空间的首地址 或 NULL，
 * 回收的字节数等于动态空间的大小。
 *
 * 注意事项：
 * 1.除了首地址，动态空间内的地址不能作实参
 * 2.NULL 作实参，无事
 * 3.已经释放的动态空间不能再次释放
 * 4.释放后，
 *   可以用 _heapmin 将堆区未使用的空间还给 OS，
 *   从而最小化堆区的可用内存。
 *   如果不还给 OS，释放的空间会还原到空闲池，可再次分配
 *   （如果使用的是 CRT 内存管理器，
 *   （就不需要显式调用 _heapmin，OS 会参与管理）
 */

/*
 * 3.calloc
 * 开辟一个数组，每个元素被初始化为 0
 *
 * 声明
 * void *calloc( size_t num, size_t size );
 * num 表示元素个数，
 * size 表示元素大小（单位是字节）
 */

// int main()
// {
//     // int* p = (int *)malloc(5 * sizeof(int));
//     int *p = (int *)calloc(5, sizeof(int));
//     if (!p)
//         printf("%s\n", strerror(errno));
//
//     free(p);
//     p = NULL;
//     // 调试看结果
//     return 0;
// }
// calloc 在开辟空间后，会把每个字节初始化为 0。
// calloc 和 malloc 几乎相同

/*
 * 4.realloc
 * 重新开辟内存空间
 *
 * 声明
 * void *realloc( void *memblock, size_t size );
 * memblock 是动态空间的首地址 或 NULL
 * size 是新空间的大小，单位是字节
 * 返回值由下面的分析给出
 *
 * 当 memblock 是 NULL 时，realloc 就是 malloc
 *
 * 当 memblock 是动态空间的首地址，则
 * 1.realloc
 *   可能先开辟一块空间，再拷贝原数据到新空间，最后释放旧空间。
 *   也可能在旧空间的基础上，拓展或缩小空间。
 * 2.新空间小于旧空间时，尾部数据会丢失。
 * 3.返回新地址 或 原来的地址 或 NULL
 *   （可能没有足够的空间，也可能第二个参数为 0）
 *
 */

// int main()
// {
//     int *p = (int *)malloc(20);
//     if (!p)
//         printf("%s\n", strerror(errno));
//     else
//     {
//         int i = 0;
//         for (i = 0; i < 5; i++)
//             p[i] = i;
//     }
//     // 使用了 malloc 开辟的 20 个字节空间
//
//     // p = (int*)realloc(p, 12);
//     int *tmp = (int *)realloc(p, 12);
//     // 用临时指针接收，防止 realloc 返回 NULL
//
//     if (!p)
//         printf("%s\n", strerror(errno));
//     else
//     {
//         // 成功接收地址，
//         // 观察两个地址有何不同，然后将新空间交给 p 管理
//         printf("%p\n", p);
//         printf("%p\n", tmp);
//         p = tmp;
//         tmp = NULL;
//     }
//     free(p);
//     p = NULL;
//     // 调试观察
//     return 0;
// }
// 注意事项：
// 1.一块空间建议只用一个指针来管理维护
// 2.realloc 要结合临时指针一起用，防止返回 NULL。
//   没有新空间也就算了，但别把原空间搞丢了
// 3.使用 realloc 成功后，不用再对旧空间使用 free

/*
 * 常见错误：
 * 1.忘记检查指针是否为 NULL
 * 2.对动态空间的越界访问
 * 3.对栈区的内存 free
 *   （尤其是堆区指针指向栈区空间的时候）
 * 4.free 释放的空间和开辟的空间大小不同
 *   （即，传给 free 的参数不是动态空间的首地址）
 * 5.对同一块动态空间多次 free
 * 6.忘记释放动态空间（会导致内存泄露）
 */

// 严重内存泄漏
// int main()
// {
//     // 运行后打开任务管理器查看内存
//     // 内存会一点点被榨干
//     // 多数系统内部有内存保护机制，内存泄露到一定程度就停止
//     // （不保证有些系统没有）
//     // 在内存崩溃前回到控制台，按键盘上的 ctrl+C 停止程序
//     while (1)
//         malloc(1);
//     // free(malloc(1));
//     return 0;
// }

/*
 * C/C++ 程序的内存开辟
 * 内存分为
 * 1.内核空间（用户代码不能读写）
 * 2.内存映射段（文件映射，动态库，匿名映射）
 * 3.栈（向下增长）
 * 4.堆（向上增长）
 * 5.静态区（也称为数据段，存储全局变量、静态变量）
 * 6.代码段（存储可执行代码、只读常量）
 */

/*
 * 柔性数组（C99 标准）
 * 结构体中最后一个成员允许是未知大小的数组，该成员称为柔性数组
 * 柔性数组前至少有一个其他成员
 */

// 使用柔性数组
// struct S
// {
//     // 两种写法
//     int i;
//     // int arr[]; // 未知大小的数组
//     int arr[0]; // 未知大小的数组（数组大小可调整）
// };
// typedef struct S S;
// #include <assert.h>
// int main()
// {
//     printf("%zd\n", sizeof(S)); // 先看看 sizeof(S)
//
//     // 使用
//     // 在堆区开辟结构体，用栈区指针管理
//     S *ps = (S *)malloc(sizeof(S) + 5 * sizeof(int));
//     if (!ps)
//         printf("%s\n", strerror(errno));
//     else
//     {
//         ps->i = 0x11223344;
//         memset(ps->arr, 1, 20);
//     }
//
//     // 改变长度
//     S *tmp = (S *)realloc(ps, 44);
//     if (!tmp)
//         assert(0);
//     else
//     {
//         ps = tmp;
//         tmp = NULL;
//         memset(ps->arr, 2, 40);
//     }
//     free(ps);
//     ps = NULL;
//     // 调试观察
//     return 0;
// }

// 用成员指针代替柔性数组
// struct S
// {
//     int i;
//     int *arr;
// };
// typedef struct S S;
// int main()
// {
//     // 在堆区开辟结构体，用栈区指针管理
//     S *ps = (S *)malloc(sizeof(S));
//     if (!ps)
//     {
//         printf("%s\n", strerror(errno));
//         assert(0);
//     }
//
//     // 在堆区开辟 int 数组，用堆区指针管理
//     ps->arr = (int *)calloc(5, sizeof(int));
//     if (!ps->arr)
//     {
//         printf("%s\n", strerror(errno));
//         assert(0);
//     }
//     memset(ps->arr, 1, 20);
//
//     // 改变长度
//     int *tmp = (int *)realloc(ps->arr, 40);
//     if (!tmp)
//         assert(0);
//     else
//     {
//         ps->arr = tmp;
//         tmp = NULL;
//         memset(ps->arr, 2, 40);
//     }
//
//     // 释放
//     // （从指针链的末端指针开始，free 到开端指针）
//     // （注意指向栈区的指针）
//     free(ps->arr);
//     ps->arr = NULL; // 可以不写
//     free(ps);
//     ps = NULL;
//     // 调试观察
//     return 0;
// }

/*
 * 发现：用成员指针可以实现柔性数组的功能
 * 问：两种实现方式有何不同？
 *
 * 不同：内存上的布局
 * 柔性数组和其他结构体成员挨在一起，
 * 成员指针则是再开辟一块空间
 *
 * 柔性数组的优势
 * 1.相比成员指针，
 *   不用再开空间和 free 空间，减少写出 bug 的可能性
 * 2.动态空间是在堆区的剩余空间中开辟的，具有随机性。
 *   在已经开辟的内存块之间，
 *   多多少少存在利用不到的内存碎片。
 *
 *   相比成员指针，柔性数组对空间的利用率更高。
 * 3.
 *   > 计算机存储结构：
 *     register - cache - memory - disk
 *     往左空间越小，访问速度越快，造价越高；往右反之
 *
 *   CPU 需要处理的数据来自寄存器。
 *   寄存器没有，向缓存要；
 *   缓存也没有，向内存要；
 *   内存也没有，向硬盘要。
 *   这一来一回会消耗时间。
 *   为了节省时间，
 *   人们发现在很多情况下，需要的数据是放在一起的（局部性原理）
 *   因此在逐层往下拿数据时，
 *   会把这次需要的数据，连同附近的数据一起取出。
 *
 *   相比成员指针，柔性数组对时间的利用率更高
 */