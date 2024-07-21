/*
 * 头文件保护
 * 确保头文件多次包含仍能安全工作的常用技术是预处理器。
 * 之前已经用到了 #include，
 * 预处理器会将指定头文件的内容代替 #include。
 *
 * 头文件保护依赖于预处理变量。
 * #define  #ifdef  #ifndef  #endif
 *
 * 与头文件保护有关的预处理变量必须唯一，
 * 通常的做法是以头文件的文件名为预处理变量，
 * 一般预处理变量的名字全部大写。
 *
 * 建议习惯性的加上头文件保护。
 *
 * 注：预处理变量无视 C++ 作用域规则
 */
#ifndef TEST_H
#define TEST_H
#include <string>
struct Test2
{
    // 数据成员
    std::string s;
    int i = 0;
    double pi = {3.1415};
    // 成员函数
    constexpr int nums_DataNumber() const { return 3; }
};
#endif /* TEST_H */