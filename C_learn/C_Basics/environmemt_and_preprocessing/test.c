#define _CRT_SECURE_NO_WARNINGS 1

//编程环境
//预处理


#include <stdio.h>

// 编程的翻译环境 和 运行环境

/*
 * C 标准的任何一种实现中，存在两个不同的环境：
 * 翻译环境和运行环境
 * 
 * test.c 源文件经过 预处理、编译、汇编和链接 生成可执行程序 test.exe，
 * 这个过程中所依赖的环境，称为翻译环境。
 * （通常也把预处理、编译、汇编三个过程合在一起，简称编译）
 * 
 * 从本质上看，源文件属于文本文件，而可执行文件则是二进制文件。
 * 从源文件到可执行文件，其实就是把人看得懂的文本文件，
 * 翻译成计算机能执行的二进制文件。
 * 
 * 至于生成的可执行文件如何运行，就要依赖具体计算机的运行环境了。
 * 不同计算机的实现原理都是一样的，都有运算器、存储器等等，
 * 但实现的方式却各有不同，不同的实现对应不同的程序运行环境。
 */

// 我们现在来研究翻译环境，观察源代码是如何转换为可执行的机器指令的。
// 

// 运行第一个程序之前，打开 file explorer 观察目录底下的文件
// 运行后，再观察目录，会发现底下多了一些文件
// （我的翻译环境为，OS: win11、编辑器：VS、编译器：MSVC）
//

// 简单 C 程序
//#define SIZE 10
//int gral = 100;
//int main()
//{
//    int arr[SIZE] = { 0 };
//    int i = 0;
//    for (i = 0; i < SIZE; i++)
//        arr[i] = i;
//
//    for (i = 0; i < SIZE; i++)
//        printf("%d ", arr[i]);
//
//    return 0;
//}

// 原本只有 test.c 和一些配置文件，
// 运行后有了 test.exe、test.obj 以及一些杂项文件。
// 这些配置文件和杂项文件不是关键的文件，大部分只是 VS 特有的。
// 我们只研究 test.obj。
// 问题来了，test.obj 究竟是什么，为什么要有这个文件？
//

/*
 * C/C++ 语言中有一个重要思想——分别编译，
 * 指的是若干个源文件可以在不同的时候分别编译，在合适的时候整合在一起。
 * 
 * 比如有三个源文件 main.c、A.c 和 B.c，
 * main.c 是 main 函数所在的文件，A.c 可以实现文件删除的功能，B.c 可以文件找回。
 * 实际开发过程中，编程人员先将 A.c 与 main.c 分别编译、整合，
 * 把生成的 APP 交付给用户使用；
 * 然后根据用户的反馈——说 APP 文件删除后不能回复，希望能改进——
 * 再编译 B.c，把编译得到的 B.obj 与 A.obj、main.obj 一起，整合成新版本的 APP。
 * 
 * 所以，拓展名为 .obj 的文件，其实就是源文件编译后得到的，称为目标文件（object file）。
 * 其中，把目标文件整合成可执行文件，由链接器来完成。
 */

// 现在我们知道了，从源文件到程序经过四步：预处理、编译、汇编、链接。
// 下面具体来看每一步都干了什么。
// （因为 VS 在生成可执行文件时，看不到预处理和编译的结果，就不敲代码了）
// （可以在 Linux 环境下观察）
//

/*
 * 预处理器干的其实就一件事：文本操作。具体来说有
 * 1.头文件的包含   2.用空格替换注释   3.宏替换   ...
 * 
 * 编译器干的是核心工作：把 C 代码翻译成汇编代码。具体来说有
 * 1.词法分析   2.语法分析   3.语义分析   4.符号汇总   ...
 * （详见《编译原理》）
 * 
 * 汇编器干的是，把汇编代码翻译成二进制机器指令，并形成符号表。
 * 
 * 链接器干的是：
 * 1.合并段表   2.符号表的合并与重定位
 * 简单来说就是，根据得到的符号表，
 * 把汇编得到的若干个目标文件与必要的库文件一起，整合成可执行文件。
 */

// 程序执行的过程
//

/*
 * 程序执行前必须放到内存中。
 * 该操作一般由操作系统完成；如果没有操作系统，则手动安排。
 * 
 * 程序开始执行。调用 main 函数。
 * 
 * 开始执行代码。程序将使用一个运行时堆栈，存储函数的局部变量和返回地址。
 * 静态变量存储在静态内存，整个程序周期都存在
 * 
 * 终止程序。main 函数正常终止，也可能是意外终止。
 */

// 下面详细研究预处理
//

// 预定义符号
// 语言本身定义好的，不是我们自己定义的 #define ...
//

//int main()
//{
//    printf("%d\n", __LINE__);
//    printf("%s\n", __FILE__);
//    printf("%s\n", __DATE__);
//    printf("%s\n", __TIMESTAMP__);
//    printf("%s\n", __TIME__);
//    printf("%s\n", __FUNCDNAME__);
//    printf("%s\n", __FUNCSIG__);
//    printf("%s\n", __FUNCTION__);
//
//    //printf("%d\n", __STDC__);
//    // 特殊的预定义符号 __STDC__
//    // 如果编译器严格遵循 C 标准，其值为 1，否则未定义
//
//    return 0;
//}
// 预定义符号的应用场景：日志文件
//

// 预处理指令。以 # 开头
// #define
// #include
// #pragma pack(4)
// #pragma
// #if
// #endif
// #ifdef
// 等等。
//

// #define 定义标识符（或预处理变量）
//

//#define TEN 10
//#define STR "hello"
//#define reg register
//
//#define do_forever for(;;)
//#define DEBUG_PRINT printf("file:%s\tline:%d\t"\
//                        "date:%s\ttime:%s\n",\
//                        __FILE__, __LINE__,\
//                        __DATE__, __TIME__)
//int main()
//{
//    printf("%d\n", TEN);
//    printf("%s\n", STR);
//    reg int a;
//
//    DEBUG_PRINT;
//    return 0;
//}
// #define 定义的后面一般都不加分号
//

// #define 定义宏
//

//#define FIVE 5
//#define TEN 10
//#define MAX(a, b) ((a)>(b)?(a):(b))
//int main()
//{
//    int a = 22, b = 11;
//    printf("%d\n", MAX(a, b));
//    printf("%d\n", MAX(FIVE, TEN));
//    return 0;
//}
// #define 定义宏或标识符，一般都大写。
// 定义宏时，宏名和左边的小括号之间不能有空白；调用宏时可以。
// 定义宏时，不要吝啬小括号。
// 调用宏时，先检查宏参数中有没有 #define 定义的符号，有就替换；然后才是宏替换。
// 宏不能递归。
//

// # 和 ##
//

// # 的应用场景：把宏参数插入字符串中
// （函数不能实现该功能）
// 
//#define PRINT(X) printf("the value of "#X" is %d\n", (X))
//int main()
//{
//    int a = 10, b = 20;
//    //printf("the value of a is %d\n", a);
//    PRINT(a);
//    PRINT(b);
//    return 0;
//}
// 宏定义中，#宏参数 == "宏参数名"，即 #X == "X"。
// 然后进行宏替换。
//

// ##：把宏参数拼接成新符号，然后宏替换。
//

//#define CAT(a, b) a##b
//int main()
//{
//    int tmp1024 = 100;
//    printf("%d\n", CAT(tmp, 1024));
//    return 0;
//}

// 带副作用的宏参数
// a++, a--, ++a, --a
// 当使用带副作用的宏参数时，要查看宏定义
// 有些宏参数在宏定义中多次求值或多次出现，如果带副作用，会导致不可预料的后果
//

// 宏和函数的比较
//

//#define MAX(X, Y) ((X)>(Y)?(X):(Y))
//double max_double(double x, double y) { return x > y ? x : y; }
//int max_int(int x, int y) { return x > y ? x : y; }
//int main()
//{
//    int a = 10, b = 20;
//    double c = 3.14, d = 3.1415;
//
//    printf("max_double(c, d) = %f\n", max_double(c, d));
//    printf("MAX(c, d) = %f\n\n", MAX(c, d));
//    printf("max_int(a, b) = %d\n", max_int(a, b));
//    printf("MAX(a, b) = %d\n", MAX(a, b));
//    return 0;
//}

/*
 * 1.函数调用时有系统开销，宏调用没有。
 * 2.函数调用是调用同一个地方的同一个代码，宏调用是宏替换。
 * 3.函数形参要声明类型，宏参数则无关类型，甚至参数可以是类型。
 * 4.函数可以调试，宏不行。
 * 5.函数可以递归，宏不行。
 * 6.函数实参可以自增自减，宏不行。
 * 7.宏可以 #，##，函数不行。
 */

//#define MALLOC(num, type)\
//        (type *)malloc (num * sizeof(type))
//int main()
//{
//    int* p = MALLOC(10, int);
//    free(p);
//    p = NULL;
//    return 0;

// 如果已有的一个名字需要重新定义，那么旧的定义首先要移除。
// #undef：移除一个宏定义
//

//#define TEN 10
//int main()
//{
//    printf("%d\n", TEN);
//#undef TEN
//    //printf("%d\n", TEN);
//#define TEN 11
//    printf("%d\n", TEN);
//
//    return 0;
//}

// 命令行定义
// 许多 C 编译器允许在命令行中定义符号，用来启动编译过程。
// 
// 应用场景：根据同一个源文件编译出一个程序的不同版本。
// （比如一个程序的两个版本——对 32 位机器和 64 位机器的版本）
//

//int main()
//{
//    int i;
//    for (i = 0; i < LEN; ++i)
//    {
//        printf("%d ", i);
//    }
//    return 0;
//}
// 上面的代码不完整，LEN 未定义。
// 在 Linux 命令行中使用命令 gcc test.c -D LEN=100，来编译
//

/*
 * 条件编译
 * 1.单分支
 *      #if 常量表达式
 *          // ...
 *      #endif
 * 
 * 2.多分支
 *      #if 常量表达式
 *          // ...
 *      #elif 常量表达式
 *          // ...
 *      #else
 *          // ...
 *      #endif
 * 常量表达式的结果为 0，则条件为假；结果为 非零，则条件为真。
 * 
 * 3.判断标识符是否被定义
 *      #ifdef symbol
 *      #if defined(symbol)
 *      若标识符已定义，条件为真；否则为假。
 * 
 *      #ifndef symbol
 *      #if !defined(symbol)
 *      若标识符未定义，条件为真；否则为假。
 * 
 * 一旦条件为真，执行后面的语句直到遇到 # endif；
 * 一旦条件为假，跳过后面的语句直到遇到 # endif。
 * 以上条件编译可以嵌套。
 * 
 * 应用场景：头文件保护。防止头文件被重复包含。
 */

// 假设有一个头文件 student.h
#ifndef __STUDENT_H__
#define __STUDENT_H__
// student.h 的内容
// ...
#endif // !__STUDENT_H__

// C 语言的新标准也可以 #pragma once

/*
 * 文件包含
 * #include <> 和 #include ""
 * 
 * #include <> 直接去标准路径下查找；
 * #include "" 先在指定路径下查找（相对路径或绝对路径），然后才去标准路径。
 * 找不到就编译错误。
 */

