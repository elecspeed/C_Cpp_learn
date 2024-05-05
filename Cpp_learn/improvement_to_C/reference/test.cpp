#include <iostream>
using namespace std;

/*
 * 引用的定义和使用
 */

// 引用的声明
// int main()
// {
//     int a = 0;
//     // int &ref_a; // 错误。引用一定要初始化
//     int &ref_a = a;
//
//     cout << "&a == " << &a << endl
//          << "&ref_a == " << &ref_a << endl;
//     // ref_a 和 a 共享同一块内存空间
//
//     // void &ref_b = b;        // 不能建立 void 型的引用
//     // int &(&ref_ref_a) = a;  // 不允许使用引用的引用
//     // int &*p_ref = &ref_a;   // 不允许使用指向引用的指针
//     // int &ref_arr[10] = {0}; // 不允许使用引用数组
//
//     return 0;
// }
// 引用相当于变量的别名。引用名和变量名共享同一块内存空间。
// 声明一个引用时必须初始化，初始化后不能更改。
// （作为函数参数或返回值则可以不用初始化）
// 引用的本质：对内存空间的硬链接。

/*
 * 引用作函数形参
 */

// 设计函数交换两个数的值
// void swap(int &a, int &b)
// {
//     // 交换实参 a 和 b 的值
//     int tmp = a;
//     a = b;
//     b = tmp;
// }
// int main()
// {
//     int a = 10, b = 20;
//     cout << "a == " << a << ","
//          << "b == " << b << endl;
//     swap(a, b);
//     cout << "a == " << a << ","
//          << "b == " << b << endl;
//     return 0;
// }

// 引入引用这个机制，
// 主要是为了引用传参，代替指针的大多数应用场合。
//
// 函数传参：1.值传递；2.地址传递；3.引用传递。
// 其中，方式 2 和 3 可以改变实参的值
//
// 引用型形参与实参共享内存空间，函数调用时不为其分配内存
// 因此，引用传参比另两种传参方式更高效
// （可以用 const 修饰，保护数据）
//
// 需要返回型参数时，用引用传参；不需要时，用常引用传参或值传参。
// 少用地址传参

/*
 * 引用作函数返回值
 */

// int &swap(int &x, int &y)
// {
//     int tmp = x;
//     x = y;
//     y = tmp;
//     return x;
// }
// int main()
// {
//     int a = 10, b = 20;
//     cout << "a == " << a << ",b == " << b << endl;

//     swap(a, b) = 0;
//     cout << "a == " << a << ",b == " << b << endl;
//     return 0;
// }