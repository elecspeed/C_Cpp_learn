#include <iostream>
using namespace std;

/*
 * 输入/输出控制，I/O 流
 */

// 输入两个整数，如果第一个整数大于第二个则输出差值，否则输出和
// inline bool larger(int x, int y)
// {
//     // 比较 x, y
//     return x > y ? true : false;
// }
// int main()
// {
//     int a, b;
//     cout << "请输入两个数：" << endl;
//     cin >> a >> b;
//
//     bool ret = larger(a, b);
//     cout << ret << " " << boolalpha << ret << " "
//          << noboolalpha << ret << endl;
//     // 操纵符 boolalpha 将输出 true 和 false 时改为文本输出，
//     // noboolalpha 取消 boolalpha。
//     // 一开始默认是数字输出
//
//     if (ret == 1)
//         cout << a << "-" << b << "=" << a - b << endl;
//     else
//         cout << a << "+" << b << "=" << a + b << endl;
//     return 0;
// }

/*
 * IO stream
 * 头文件           类类型
 * iostream     istream      ,ostream ,iostream
 * fstream      ifstream     ,        ,fstream
 * sstream      istringstream,
 *
 * （宽字符版本的类类型和函数的名字以 w 开头）
 *
 * fstream 定义了 6 个类型来支持文件 IO，
 * 分别是
 * ifstream, ofstream, fstream,
 * 以及相应的 3 个宽字符版本的类类型
 *
 * sstream 同理，用来支持内存 IO
 * （相当于 C 中的内存操作）
 *
 * fstream 和 sstream 继承自 iostream。
 * iostream 是普通流，
 * fstream 是文件流，
 * sstream 是 string 流。
 * 因此，iostream 的特性适用于 fstream 和 sstream。
 * 也就是说，
 * 我们是如何使用 cin 和 cout 的，
 * 就同样地使用相应的对象。
 * 除了继承自 iostream 的行为之外，
 * fstream 和 sstream 还定义了各自的新行为。
 */

/*
 * iostream 的流特性
 *
 * 1.
 * IO 对象无拷贝或赋值，
 * 因此进行 IO 操作的函数通常以引用方式传递和返回流。
 * 还不能是 const，
 * 因为 IO 操作会改变流状态。
 *
 * 2.
 * 流的条件状态
 * 一个流发生错误，其后续的 IO 操作都会失败。
 * 因此应该在使用之前，检查流的状态。
 * 最简单的检查：将一个流作为一个条件
 * while (cin >> input)
 *     // ok，成功读取
 *
 * 下面是与流的条件状态相关的成员
 * type member
 * iostate   与机器相关
 *
 * data member
 * badbit    表示流已崩溃
 * failbit   表示一个 IO 操作失败了
 * eofbit    表示流到达了文件结束
 * goodbit   表示流的状态为有效，此值保证为 0
 *
 * member function
 * eof()   若流的 eofbit 置位，返回 true
 * bad()   若流的 badbit 置位，返回 true
 * fail()  若流的 failbit 或 badbit 置位，返回 true
 * good()  若流的 eofbit,failbit,badbit 都为真，返回 true
 *
 * clear()          将流中所有条件状态位复位
 * clear(flags)     根据 flags，将对应的条件状态位复位
 * setstate(flags)  根据 flags，将对应的条件状态位置位
 * rdstate()        返回流的当前状态。即 read state
 * （flags 的类型为 iostate）
 *
 * 原理
 * iostate 类型作为一个位集合来使用。
 * IO 库定义了 4 个 iostate 类型的 constexpr 值，
 * 即 goodbit,eofbit,badbit,failbit。
 * 这些值用来表示特定的 IO 条件，
 * 可以与位运算符一起使用。
 *
 * 比如，
 * 0000 0000 为 goodbit；
 * 0000 0011 可能为 failbit；
 * 等等。
 *
 * 发生系统级错误，badbit 被置位。
 * 通常一旦 badbit 被置位，流就无法使用了。
 * 发生可恢复错误后，failbit 被置位。
 * 到达文件结束，eofbit 和 failbit 都被置位。
 *
 * 查询流的状态
 * 使用相应的成员函数来查询，一般是 good 或 fail。
 * eof 和 bad 只能表示特定的错误。
 * 实际上，将流当作条件使用等价于 !fail()
 *
 * 管理流的状态
 */

// void process_inupt(istream &in) { ; }
// int main()
// {
//     auto old_state = cin.rdstate(); // 记住 cin 当前状态
//     cin.clear();                    // 使 cin 有效
//     process_inupt(cin);             // 使用 cin
//     cin.setstate(old_state);        // 将 cin 恢复为原状态
//
//     // 复位 failbit 和 badbit，其他标志位不变
//     cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
//     return 0;
// }

/*
 * 3.
 * 管理输出缓冲
 *
 * 导致输出缓冲刷新的原因
 * a.程序正常结束
 *   （程序崩溃，输出缓冲区不会被刷新）
 * b.缓冲区满
 * c.操作符显式刷新，有 flush,endl,ends
 *   flush 刷新缓冲区
 *   endl  输出一个 '\n'，然后刷新
 *   ends  输出一个 '\0'，然后刷新
 * d.操作符设置流的内部状态
 *   unitbuf   每次输出后都刷新缓冲区
 *   nounitbuf 取消 unitbuf
 * e.流的关联
 *
 * 流的关联
 *
 * is.tie(os);
 * // is 关联 os。
 * // 对输入流 is 的读操作会先刷新输出流 os
 *
 * os1.tie(os2);
 * // os1 关联 os2。
 * // 对输出流 os1 的写操作会先刷新输出流 os2
 *
 * 成员函数 tie 有两个重载版本
 * ostream* tie( ostream* pos );
 * ostream* tie() const;
 */

// int main()
// {
//     cin.tie(&cout);           // cin 关联 cout
//     auto old_tie = cin.tie(); // old_tie 指向 cin 当前关联的流
//     cin.tie(nullptr);         // cin 不关联其他流
//     // 可以写在一起
//     // auto old_state = cin.tie(nullptr);
//
//     cin.tie(&cerr);   // 读取 cin 会刷新 cerr
//     cin.tie(old_tie); // cin 重新关联 cout
//     return 0;
// }

// 默认情况下，cin 和 cerr 都关联 cout。
// 每个流最多关联一个流，
// 但多个流可以同时关联一个 ostream。

/*
 * file stream
 */
