/*
 * C++ 语言同时支持面向对象和面向过程的程序设计。
 * 这里主要讲 C++ 在面向过程的程序设计方面，相比 C 语言的一些改进和拓展
 */

#include <iostream>
using namespace std;

/*
 * 输入两个整数，如果第一个整数大于第二个则输出差值，否则输出和
 */

// 比较 x, y
// bool larger(int x, int y)
// {
//     return x > y ? true : false;
// }
// int main()
// {
//     int a, b;
//     cout << "请输入两个数：" << endl;
//     cin >> a >> b;

//     bool ret = larger(a, b);
//     cout << ret << " " << boolalpha << ret << " "
//          << noboolalpha << ret << endl;
//     // 操纵符 boolalpha 将输出 true 和 false 时改为文本输出，
//     // noboolalpha 将输出 true 和 false 时改为数字输出
//     // 一开始默认是数字输出

//     if (ret == 1)
//         cout << a << "-" << b << "=" << a - b << endl;
//     else
//         cout << a << "+" << b << "=" << a + b << endl;

//     return 0;
// }

/*
 * 命名空间定义、使用
 */

// 定义命名空间
// namespace one
// {
//     int x = 1;
//     int y = 11;
// } // namespace one
// namespace two
// {
//     int x = 2;
//     int y = 22;
// } // namespace two

// // 三种使用方式
// using namespace one; // 第一种方式。意为默认使用 one 里面的名字

// void print();
// int main()
// {
//     cout << x << "," << y << endl;

//     cout << two::y << endl;
//     // 第二种方式。通过域解析符::一次性使用

//     cout << y << endl;

//     using two::x;
//     // 第三种方式。意为在该语句后，且只在 main 内，x 默认是 two::x
//     // 但是想使用 two 里面的其他内容时，仍要通过域解析符

//     cout << x << "," << y << endl;

//     print();

//     return 0;
// }
// void print()
// {
//     cout << x << "," << y << endl;
//     // main 函数里面的 using two::x 影响不到 print 函数里面的 x
// }

/*
 * 新增类型 - string 类，定义、使用
 */

// #include <string> // 使用 string 要包含 <string> 头文件
// int main()
// {
//     // 定义
//     // string s1;                  // 定义空串 a
//     // string s2 = "hello,world!"; // 定义串 b 初值为 hello,world!
//     // string s3 = s2;             // 定义串 c 初值为串 b 的值
//     // string s4(8, 'A');          // 定义串 d 初值为 8 个 A，即 AAAAAAAA

//     // 读入
//     // cin >> s1;
//     // cout << s1 << endl;
//     // 读入字符串，遇到 blank space 结束，blank space 留在缓冲区

//     // getline(cin, s1);
//     // cout << s1 << endl;
//     // 读入一行，遇到换行符结束，换行符被读入

//     // 赋值
//     // s1 = s4;
//     // s1 = '1';
//     // s1 = {'a', 'b', 'c'};
//     // cout << "s1=" << s1 << endl;
//     // 右边可以是一个 string 串、C 风格的串或一个 char 字符

//     // 字符串连结、比较
//     // s2 = s3 + ' ' + s4;
//     // cout << s2 << endl;
//     // bool tmp = s2 > s4;
//     // cout << boolalpha << tmp << endl;
//     // + 号实现串连结，关系运算符比较串长度。
//     // 运算符重载，+ 号和关系运算符的内涵发生了改变

//     // 方法：
//     // 求串长 length、串插入 insert、串尾插 append、串替换 replace、
//     // 取子串 substr、找子串 find、删子串 erase
//     // s1 = "abc";
//     // cout << s1.length() << endl;

//     // s1.append(s2);
//     // cout << s1 << endl;
//     // 尾插

//     // s1.insert(3, s4);
//     // cout << s1 << endl;
//     // 在 s1 下标为 3 的位置前面插入 s4

//     // s1.replace(0, 3, "111");
//     // cout << s1 << endl;
//     // 下标 [0,3) 范围内的子串替换成"111"

//     // s1 = s2.substr(0, 5);
//     // cout << s1 << endl;
//     // s2 下标 [0,5) 范围内的子串赋给 s1

//     // int pos = s1.find("ll");
//     // cout << pos << endl;
//     // 从 s1 中找 "ll"，找到返回 s1 中第一个匹配字符的下标；否则返回 -1

//     // s1.erase(0, 3);
//     // cout << s1 << endl;
//     // 删除 s1 下标 [0,3) 范围内的子串

//     // 某些情况下需要转成 C 风格的字符串，用方法 c_str

//     return 0;
// }

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

//     ::test += test; // 左边全局，右边局部
//     cout << "test == " << test << endl;
//     cout << "::test == " << ::test << endl;

//     return 0;
// }

// 二、形参可带有默认值
// void func(int x, int y = 10, int z); // 错误。具有默认值的参数从最右边开始
// void func(int x, int y, int z = 10);
// int main()
// {
//     // 实参个数小于或等于形参个数。没有默认值的形参一定要传参
//     func(1, 2, 3);
//     func(1, 2);
//     // func(1); //错误。

//     return 0;
// }
// // void func(int x, int y, int z = 10) // 没有函数声明，函数定义才能带有默认值
// void func(int x, int y, int z)
// {
//     cout << x << " "
//          << y << " "
//          << z << endl;
// }

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

// int square(int x, int y = 100) { return x * x + y * y; }
// int square(int x) { return x * x; }
// int main()
// {
//     cout << square(1) << endl;
//     return 0;
// }
// 有问题。函数重载机制 和 形参默认值机制 同时使用时，可能会产生二义性

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
// 有问题。
// 函数调用，实参与形参类型不相符合时，编译器会自动类型转换。
// 即，上面的两个 Islarger 只留一个都可以通过编译
// 因此，函数调用时，实参的个数、类型、顺序与某一版本的重载函数形参要一致
