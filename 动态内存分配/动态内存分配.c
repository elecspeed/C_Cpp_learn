#define _CRT_SECURE_NO_WARNINGS 1

//为什么要动态内存分配
//动态内存函数
//题目
//柔性数组

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



//内存可以分为三大区域：栈区，堆区和静态区
//
//栈区：局部变量，形参，函数调用等
//堆区：动态内存分配。相关函数 malloc/free,realloc,calloc 等
//静态区：全局变量，静态变量等

//内存的使用方式
// 1.创建变量
// 2.创建数组
// 
// 两种开辟内存的方式有以下特点：
// 1.开辟的空间大小是固定的
// 2.在程序运行前就分配好空间，运行后不能改变

//C语言其实可以创建柔性数组，但是
// 柔性数组是在C99之后才出现的，当前的多数编译器也不支持
// 因此，让我们倒退30年，讨论 动态内存分配 相比创建数组的优势
// 
// 创建的数组并不能根据需求伸长或缩短，只能事先猜测，可能需要多少元素个数（从内存上去解释）
// 而动态内存分配可以很好地解决这个问题
// 



//动态内存函数（malloc/free,realloc,calloc等）

//1.malloc
// Allocates memory blocks.
// 开辟连续的内存空间
// 
// 声明
// void *malloc( size_t size );
// 
// size表示要开辟的字节数
// 返回值：开辟空间的首地址 或 NULL（可能没有足够的可用空间）
// 
// 需要stdlib库或malloc库（free，realloc，calloc同）

//int main()
//{
//    //向内存申请10个整型的空间
//    int* p = (int*)malloc(10 * sizeof(int));//有些编译器可以自动类型转换，但强制类型转换总没错
//
//    //或者试试申请超大空间
//    //int* p = (int*)malloc(ULLONG_MAX);
//
//    if (p == NULL)
//    {
//        printf("%s\n", strerror(errno));    //打印错误原因
//    }
//    else
//    {
//        //正常使用
//        int i = 0;
//        for (i = 0; i < 10; i++)
//            p[i] = i;
//        for (i = 0; i < 10; i++)
//            printf("%d ", *(p + i));
//    }
//    
//    //用完空间要主动回收
//    free(p);                //释放空间
//    p = NULL;               //处理野指针
//
//    //虽然程序结束也能回收，但会有内存泄漏的风险
//    return 0;
//}
// 注意事项：
// 1.即使开辟的内存很小，也要检查melloc返回值
// 2.标准没有定义参数size为0的情况
// 3.在堆区连续开辟空间，开出的空间首地址没有地址高低顺序
//



//2.free
// Deallocates or frees a memory block.
// 回收或释放一块内存空间
// 
// 声明
// void free( void *memblock );
// 
// 参数memblock是之前被malloc，calloc，realloc开辟的空间首地址，回收的字节数等于之前开辟的
// 
// 注意事项：
// 1.如果参数memblock为NULL，则无事
// 2.如果memblock不是动态开辟的空间或NULL，会报错
// 3.释放后，可以用_heapmin将 释放的空间 和 未使用的空间 一起还给OS，
//   从而最小化堆上的可用内存。
//   如果不还给OS，释放的空间会还原到空闲池，可再次分配
//



//3.calloc
// Allocates an array in memory with elements initialized to 0.
// 开辟一个数组，每个元素已被初始化为0
// 
// 声明
// void *calloc( size_t num, size_t size );
// 
// num表示元素个数，size表示元素大小（单位是字节）

//int main()
//{
//    //int* p = (int*)malloc(5 * sizeof(int));
//    int* p = (int*)calloc(5, sizeof(int));
//
//    if (!p)
//        printf("%s\n", strerror(errno));
//
//    free(p);
//    p = NULL;
//
//    //调试看结果
//    return 0;
//}
// calloc和malloc的不同之处
// calloc在开辟空间后，会把每个字节初始化为0。其余二者相同
//



//4.realloc
// Reallocate memory blocks.
// 重新开辟内存空间
// 
// 声明
// void *realloc( void *memblock, size_t size );
// 
// memblock是之前动态开辟的空间的首地址 或 NULL
// size是新空间的大小，单位是字节
// 
// memblock是NULL，则realloc就是malloc
// 
// memblock是之前动态开辟的空间的首地址，则
// 1.realloc先开辟一块空间，再拷贝原数据到新空间，最后释放旧空间。
// 2.新空间小于旧空间时，拷贝会丢失尾部数据。
// 3.返回新地址 或 NULL（可能没有足够的空间）
//

//int main()
//{
//    int* p = (int*)malloc(20);
//    if (!p)
//        printf("%s\n", strerror(errno));
//    else
//    {
//        int i = 0;
//        for (i = 0; i < 5; i++)
//        {
//            p[i] = i;
//        }
//    }
//    //此时只使用了malloc开辟的20个字节空间
//    
//    //p = (int*)realloc(p, 12);
//    int* ptmp = (int*)realloc(p, 24);         //用临时指针存，防止返回NULL
//    if (!p)
//        printf("%s\n", strerror(errno));
//    else
//    {
//        p = ptmp;
//        ptmp = NULL;
//    }
//    //...
//    free(p);
//    p = NULL;
//    
//    //调试看结果
//    return 0;
//}
// 注意事项：
// 1.一块空间建议只用一个维护指针来管理
// 2.realloc要结合临时指针一起用，防止返回NULL。没有新空间也罢，但原空间别搞丢了
// 3.使用realloc成功后旧空间已经释放，不用再free
//



//常见错误：
// 1.忘记检查指针是否为NULL
// 2.对动态开辟内存的越界访问
// 3.对非动态开辟的内存free
// 4.free释放的空间和开辟的空间大小不同（意味着，改变了维护指针指向的地址）
// 5.对同一块动态内存多次free
// 6.忘记释放动态内存（会导致内存泄露）

//int main()
//{
//    //严重内存泄漏
//    while (1)
//    {
//        malloc(1);
//    }
//
//    //运行后打开任务管理器查看内存
//    //内存会一点点被榨干
//    //多数系统有内存保护机制，内存泄露到一定高度就停止（不保证有些系统没有）
//    //在内存崩溃前回到控制台，按键盘上的 crtl + C 停止程序
//    return 0;
//}
