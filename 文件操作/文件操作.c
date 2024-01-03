#define _CRT_SECURE_NO_WARNINGS 1

//什么是文件
//文件名 和 文件类型
//文件缓冲区
//文件指针
//文件的打开与关闭
//文件的顺序读写 和 随机读写
//文件结束的判定

#include <stdio.h>
#include <string.h>
#include <errno.h>


//磁盘里面放的都是文件
//在这里，从程序设计的角度，把文件分为两种：程序文件 和 数据文件

//程序文件
//包括 源文件（后缀名为.c），目标文件（.obj），可执行程序（.exe）
//数据文件
//程序文件可以读取和写入数据的文件
//这里讨论的是对数据文件的操作

//此前处理的数据，其输入输出都在终端上进行。
//今天要将数据的输入输出转到磁盘上进行，处理的便是磁盘上的文件



//文件名：文件路径+文件名主干+文件后缀（或称拓展名）
//例：C:\User\test.txt

//文件类型
//根据写入数据时数据的组织形式，数据文件被称为文本文件 或 二进制文件
//数据不加以转换，从内存直接输入磁盘，磁盘存储的为二进制文件
//数据转换成ASCII码，再从内存输入磁盘，则为文本文件

//字符只能以ASCII码存储。数值型数据可以用ASCII码存储，也可以用二进制形式存储



//文件缓冲区
//C标准采用“缓冲文件系统”处理数据文件。
//系统会自动在内存中，为程序的每一个正在使用的文件开辟一块“文件缓冲区”。
//在内存和磁盘之间往来的数据，会先存在输入缓冲区和输出缓冲区
//缓冲区满了才送到对应的区域
//缓冲区的大小由C编译系统决定

//从程序输出数据到外部（文件，终端等），或从外部输入数据到程序，都要经过缓冲区



//文件指针
//在缓冲文件系统中，每个被使用的文件都在内存中开辟了一块文件信息区（不是文件缓冲区）
//该文件信息区用来存放文件的相关信息（如文件名，文件状态，文件位置等）
//在C语言看来，这些文件信息区就是结构体变量
//系统将该结构体类型声明为FILE
//不同编译器对FILE的定义非常相似
//每使用一个文件，系统就创建一个FILE结构体变量，并自动填充相关信息
//当文件内容发生变化，FILE结构体成员变量也会发生变化
// 
//那么，这块动态开辟的空间就由“文件指针”来管理



//文件使用前要先打开，使用完要关闭

//C语言每打开文件，都会返回文件信息区的地址（动态内存分配），
//相当于建立了指针和文件的联系

//打开文件用fopen函数
// 
// FILE *fopen( const char *filename, const char *mode );
// 
// filename为文件名，mode为打开方式

//打开方式    含义                         如果指定文件不存在
//  "r"     打开一个文本文件读取数据         出错
//  "w"     打开一个文本文件写入数据         新建一个文本文件并写入数据（会把原有的文件覆盖掉）
//  "a"     向文本文件尾部追加数据           出错
//  "rb"    
//  "wb"    
//  "ab"    同上（换成二进制文件）           同上
// 
//  "r+"    打开一个文本文件读写数据         出错
//  "w+"    新建一个文本文件读写数据      
//  "a+"    打开一个文本文件，在尾部读写数据 新建
//  "rb+"
//  "wb+"
//  "ab+"   同上
//

//打开文件test.txt
//int main()
//{
//    //绝对路径
//    //FILE* pf = fopen("E:\\Source\\Repos\\elecspeed\\C_learn\\文件操作\\test.txt", "r");
//
//    //相对路径
//    //FILE* pf = fopen("../../test.txt", "r");
//    FILE* pf = fopen("test.txt", "r");
//
//    if (!pf)
//    {
//        //打开失败
//        printf("%s", strerror(errno));
//        return 0;
//    }
//    //打开成功
//    
//    //读文件
//    //关闭文件
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

//关闭文件用fclose 或 _fcloseall函数
// Closes a stream (fclose) or closes all open streams (_fcloseall).
// 
// 声明
// int fclose( FILE *stream );
// int _fcloseall( void );



//文件的顺序读写
//  函数名      功能                适用于
//  fgetc       字符输入            所有输入流
//  fputc       字符输出            所有输出流
//  fgets       文本行输入          
//  fputs       文本行输出          同上
//  fscanf      格式化输入          
//  fprintf     格式化输出          同上
//  fread       二进制输入          文件
//  fwrite      二进制输出          文件

//int main()
//{
//    FILE* pf = fopen("test.txt", "r");    //打开方式会影响读写函数
//    if (!pf)
//    {
//        printf("%s\n", strerror(errno));
//        return 0;
//    }
//    //写
//    //fputc('g', pf);
//
//    //读
//    int ch = fgetc(pf);
//    putchar(ch);
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//键盘和屏幕都是外部设备
//键盘 - 标准输入设备
//屏幕 - 标准输出设备
//是每个程序默认打开的两个流设备
//三个默认打开的流设备：stdin，stdout，stderr
//FILE* stdin
//FILE* stdout
//FILE* stderr

//因此，文件读写函数可以操作标准输入输出流
//int main()
//{
//    int ch = fgetc(stdin);
//    fputc(ch, stdout);
//
//    return 0;
//}

//练习使用文件读写函数
//int main()
//{
//    char buf[100] = { 0 };
//    FILE* pf = fopen("test.txt", "r");
//    if (!pf)
//    {
//        printf("%s", strerror(errno));
//        return 0;
//    }
//    //读文件
//    fgets(buf, 100, pf);
//    //printf("%s", buf);       //打印看看。同时注意printf，fprintf，puts，fputs四者的不同和相同
//    //fprintf(stdout, "%s", buf);
//    //puts(buf);
//    //fputs(buf, stdout);
//
//    fgets(buf, 100, pf);
//    //printf("%s", buf);
//    //fprintf(stdout, "%s", buf);
//    //puts(buf);
//    //fputs(buf, stdout);
//
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

//int main()
//{
//    char buf[100] = { 0 };
//
//    FILE* pf = fopen("test.txt", "w");
//    if (!pf)
//    {
//        printf("%s", strerror(errno));
//        return 0;
//    }
//    //写文件
//    //scanf("%s", buf);
//    //fscanf(stdin, "%s", buf);
//    //gets(buf);
//    //fgets(buf, 100, stdin);
//    fputs(buf, pf);
//
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

//笔试题（对比下列函数）
//printf/fprintf/sprintf
//scanf /fscanf /sscanf
//
//print和scanf   是针对 标准输入输出流 的 格式化输入输出函数
//fprintf和fscnaf是针对 所有输入输出流 的 格式化输入输出函数

//sscanf和sprintf
//struct S
//{
//    int i;
//    float f;
//    char arr[10];
//};
//int main()
//{
//    struct S s = { 100, 3.14f, "abcdef" };
//    char buf[1024] = { 0 };
//
//    sprintf(buf, "%d %f %s", s.i, s.f, s.arr);
//
//    struct S tmp = { 0 };
//    sscanf(buf, "%d %f %s", &(tmp.i), &(tmp.f), tmp.arr);
//
//    //调试看结果
//    return 0;
//}
//
//int sprintf( char *buffer, const char *format [, argument] ... );
//将后面的参数，按照format字符串的格式转成str，再存储到buffer
//
//int sscanf( const char *buffer, const char *format [, argument ] ... );
//将前面的字符串buffer，按照format的格式读取数据，再存储到后面的参数

//struct S
//{
//    char name[20];
//    int age;
//    double score;
//};
//int main()
//{
//    struct S s[3] = {
//        { "张三", 20, 59.9},
//        { "张三", 20, 59.9 },
//        { "张三", 20, 59.9 },
//    };
//    FILE* pf = fopen("test.txt", "wb");
//    if (!pf)
//        return 0;
//    //以二进制的形式写文件
//    fwrite(&s, sizeof(struct S), 3, pf);
//
//    fclose(pf);
//    pf = NULL;
//
//    //打开同目录的test.txt文件看结果
//    return 0;
//}
//int main()
//{
//    struct S s[3] = { 0 };
//    FILE* pf = fopen("test.txt", "rb");
//    if (!pf)
//        return 0;
//    //以二进制的形式读文件
//    fread(&s, sizeof(struct S), 3, pf);
//
//    fclose(pf);
//    pf = NULL;
//
//    //调试看结果
//    return 0;
//}



//文件的随机读写

//fseek
// 定位文本指针（不是文件指针）指向特定的文本位置
// 
// 声明
// int fseek( FILE *stream, long offset, int origin );
// 
// offset：偏移量
// origin：开始偏移的位置，有SEEK_CUR（当前文本指针的位置）, SEEK_END 和 SEEK_SET
//
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");
//    if (!pf)
//        return 0;
//    //1.定位文本指针
//    fseek(pf, -2, SEEK_END);      //SEEK_END一般是'\0'
//
//    //2.读取文件
//    int ch = fgetc(pf);
//    printf("%c\n", ch);
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//ftell
// 计算文本指针相对于SEEK_SET的偏移量
// 
// 声明
// long ftell( FILE *stream );
//
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");
//    if (!pf)
//        return 0;
// 
//    //文本指针在起始位置
//    long pos = ftell(pf);
//    printf("%ld\n", pos);
//
//    //文本指针在起始位置后3个字节处
//    fseek(pf, 3, SEEK_SET);
//    pos = ftell(pf);
//    printf("%ld\n", pos);
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//rewind
// 让文本指针回到SEEK_SET位置
// 
// 声明
// void rewind( FILE *stream );
//
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");
//    if (!pf)
//        return 0;
//
//    fseek(pf, 3, SEEK_SET);
//    rewind(pf);
//
//    int ch = fgetc(pf);
//    printf("%c\n", ch);
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}



//文件的结束判定
//
//
