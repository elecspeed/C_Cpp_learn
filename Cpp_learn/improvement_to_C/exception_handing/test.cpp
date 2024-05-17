#include <iostream>
using namespace std;

/*
 * 异常处理
 *
 * 什么是异常
 * 异常是指程序运行时的反常行为，
 * 比如失去数据库连接、遇到意外输入、申请的动态空间不足等。
 */

// 除数为 0
// int divide(int a, int b)
// {
//     if (b == 0)
//         // 除数为 0，抛出异常
//         throw b;
//     return a / b;
// }
// int main()
// {
//     int a = 10, b = 0, c;
//     try
//     {
//         c = divide(a, b);
//         cout << c << endl;
//     }
//     catch (int)
//     {
//         cout << "except of divide zero." << endl;
//     }
//     catch (const std::runtime_error &e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     catch (...)
//     {
//         cout << "unclear exception." << endl;
//     }
//     return 0;
// }

/*
 * 异常处理机制给 异常检测和异常处理 的协作提供支持，
 * 把对于异常的检测和处理分离开来。
 *
 * 抛出异常
 * 通过 throw 语句引发一个异常。
 * 程序执行到 throw 语句时，跟在后面的代码将不再被执行，
 * 程序的控制权转移到与该 throw 最近且匹配的 catch 模块。
 * 该 catch 可能与 throw 位于同一个函数中，
 * 也可能位于直接或间接调用了 throw 所在函数的另一个函数。
 * （一般位于上级函数）
 * 最坏的情况是没有匹配的 catch，
 * 程序将调用标准库函数 terminate，终止程序。
 *
 * 栈展开
 * 抛出一个异常后，程序暂停，
 * 异常处理程序开始搜寻与异常匹配的 catch 子句。
 * 搜寻过程：
 * 沿着函数的调用链，
 * 从里层函数到最外层的 main 函数层层检查。
 * 先检查异常是否在 try 语句块内，
 * 如果在，
 * 再检查与该 try 模块关联的 catch 子句。
 * （注意，如果异常不在 try 语句块内，
 * （catch 子句是无法和异常匹配的。）
 * 这个过程被称为栈展开。
 *
 * 找到匹配的 catch 子句后，程序进入并执行其中的代码。
 * 执行完毕后，如果没有重新抛出，
 * 程序跳到 try 语句块后继续执行。
 *
 * 控制权的转移意味着
 * 1.沿着调用链的函数可能会提早退出
 * 2.提早退出的函数内部，它的局部变量随之销毁。
 * throw 有些时候类似于 return：
 * 通常位于条件语句内或某个函数的最后一条语句。
 *
 * > 如果异常发生在构造函数中，
 * > 务必确保已构造的成员被正确地销毁！
 * >
 * > 如果异常发生在析构函数中，
 * > 请在析构函数内部处理异常。
 *
 * 捕获异常
 * try 语句块以关键字 try 开始，以一个或多个 catch 模块结束。
 * 每一个 catch 子句类似重载函数：
 * 1.其中的异常声明可以忽略捕获形参的名字；
 * 2.不仅如此，
 *   捕获形参可以是一个引用，
 *   通过抛出的异常对象初始化捕获形参，
 *   此时捕获形参就是异常对象的别名！
 * 3.还有一个特性：
 *   抛出的异常对象初始化捕获形参，
 *   是符合赋值兼容规则的。
 *
 * 异常类
 * 异常类是一种特殊的类，用来抛出异常对象。
 *
 * 重新抛出
 * 一个 catch 语句不能完全处理某个异常时，
 * 在末尾加上一句 throw;，
 * 则会继续向上级函数抛出异常对象。
 *
 * 捕获所有异常
 * 形如 catch(...)
 * catch(...) 必须放在所有 catch 中最后的位置
 */
