#include <iostream>
using namespace std;

/*
 * 函数改进
 */

// 一、域解析符扩大全局变量的作用域
// int test = 100;
// int main()
// {
//     int test = 1;
//     cout << "test == " << test << endl;
//     cout << "::test == " << ::test << endl;
//
//     ::test += test; // 左边全局，右边局部
//     cout << "test == " << test << endl;
//     cout << "::test == " << ::test << endl;
//     return 0;
// }

// 二、形参可带有默认值
// void func(int x, int y = 10, int z); // 错误。默认值形参从最右边开始
// void func(int x, int y, int z = 10);
// int main()
// {
//     // 实参个数小于或等于形参个数。
//     // 没有默认值的形参一定要传参。
//     func(1, 2, 3);
//     func(1, 2);
//     // func(1); // 错误。
//
//     return 0;
// }
// // void func(int x, int y, int z = 10)
// void func(int x, int y, int z)
// {
//     cout << x << " "
//          << y << " "
//          << z << endl;
// }
// 没有函数声明，函数定义才能有默认值形参
// 默认值形参最好放在函数声明

// 三、函数重载
// 函数可以同名，但形参的个数、类型、顺序要不同。

// void test(int x);
// char test(int x);
// 错误。返回类型不是区分重载函数的因素

// double max(double x, double y) { return x > y ? x : y; }
// int max(int x, int y) { return x > y ? x : y; }
// int main()
// {
//     cout << "max(20, 10) == " << max(20, 10) << endl;
//     cout << "max(3.14, 3.1415) == " << max(3.14, 3.1415) << endl;
//     return 0;
// }

// 注意：函数重载机制 和 形参默认值机制 同时使用时，可能会产生二义性
// int square(int x, int y = 100) { return x * x + y * y; }
// int square(int x) { return x * x; }
// int main()
// {
//     cout << square(1) << endl; // 调用哪个重载函数？
//     return 0;
// }

// 注意：
// 1.函数调用时，
//   实参的个数、类型、顺序与某一版本的重载函数形参要一致
// 2.设计函数时，
//   要考虑传参时的自动精度提升
// bool Islarger(unsigned x, unsigned y) { return x > y ? true : false; }
// bool Islarger(int x, int y) { return x > y ? true : false; }
// int main()
// {
//     unsigned a = 20;
//     int b = 10;
//     cout << "Islarger(a, b) == " << boolalpha << Islarger(a, b) << endl;
//     cout << "Islarger(b, a) == " << boolalpha << Islarger(b, a) << endl;
//     return 0;
// }
// 函数调用，实参与形参类型不相符合时，编译器会自动类型转换。
// 即，上面的两个 Islarger 只留一个都可以通过编译
