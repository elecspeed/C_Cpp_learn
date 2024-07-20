#include <iostream>
#include <string>
using namespace std;

/*
 * 变量和基本类型
 */

/*
 * constexpr 和常量表达式
 *
 * 常量表达式：值不会改变，编译时就能得到计算结果的表达式
 * 例如
 * 1.字面值
 * 2.用常量表达式初始化的 const 对象
 * 3.以及只有 例1和例2 参与的表达式
 *
 * constexpr 类型：编译器验证变量值是否是常量表达式（C++11）
 *
 * constexpr & const
 * 同是限定符，但 constexpr 的要求更苛刻：
 * 1.对于变量
 *   声明为 constexpr 的变量一定是 const 的，
 *   且必须要用常量表达式初始化
 * 2.对于指针、引用
 *   constexpr 引用只能绑定存储于静态区的对象
 *   constexpr 指针只能指向 nullptr,0 或静态区对象
 * 3.对于对象
 *   （略）
 */
// int ll = 100;
// int main()
// {
//     /**
//      * constexpr 指针、引用
//      */
//     int a = 0;
//     // constexpr int &r = a;
//     const int b = 1;
//     // constexpr int &r = b;
//     constexpr int c = 2;
//     // constexpr int &r = c;
//
//     constexpr int &r = ll;
//     constexpr int *p = &ll;
//     // p 是一个顶层 const
//     // 即 constexpr int *p --> int *const p
//
//     /**
//      * constexpr 变量
//      */
//     constexpr int i = 20;
//     constexpr int k = i + 1;
//     // constexpr int l = size();
//     // 只有当 size 是 constexpr 函数时
//     // 才是一条正确的声明
//     return 0;
// }

/*
 * 处理类型
 */
int main()
{
    /**
     * 类型别名
     * 两种方式，其中 using 是 C++11
     */
    typedef char *pstr;
    typedef pstr &r_pstr;
    using ll = long long;
    using ull = unsigned ll;
    using pfunc = void (*)();

    /**
     * auto（C++11）
     */
    // auto 定义的变量必须初始化
    // auto a = 0, b;
    auto a = 0, &ra = a, *pa = &a;

    // 初始值是引用，
    // 则真正参与初始化的是引用的对象。
    // 要想设置 auto 引用，
    // 需要明确指出
    int i = 0, &ri = i;
    auto b = ri;
    auto &c = ri;

    // 忽略顶层 const，保留底层 const。
    // 如果希望推出的 auto 是顶层 const，
    // 需要明确指出
    const int ci = i, &rci = ci;
    auto d = ci;
    auto e = &ci;
    const auto f = &ci;
    auto &g = ci; // 转化成底层 const

    /**
     * decltype（C++11）
     * 1.一个函数
     * 2.一个变量
     * 3.既不是一个函数，也不是一个变量
     */
    // 1.
    // 如果 decltype 使用的表达式是一个函数，
    // 则返回该函数的返回类型。
    // 编译器并不调用该函数。
    string s;
    decltype(s.size()) count = 0; // std::size_t

    // 2.
    // 如果 decltype 使用的表达式是一个变量，
    // 则返回该变量的类型（包括顶层 const 和引用）
    const long cl = 0L,
               &rcl = cl,
               *pcl = &cl,
               *const cpcl = &cl;
    decltype(cl) h = 0;    // h 是 const long，必须初始化
    decltype(rcl) j = h;   // j 是 const long&，必须初始化
    decltype(pcl) k;       // k 是 const long*
    decltype(cpcl) l = &h; // l 是 const long *const，必须初始化

    // 3.
    // 如果 decltype 使用的表达式不是情况 1,2，
    // 再分情况：
    // a.表达式的结果只能作右值，
    //   则返回该结果的类型
    // b.能作左值，
    //   则返回该结果类型的引用类型
    int jj = 0, *p = &jj, &r = jj;
    decltype(r + 0) o;  // o 是 int
    decltype(*p) q = o; // q 是 int&

    return 0;
}
