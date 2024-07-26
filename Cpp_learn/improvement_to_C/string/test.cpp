#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
 * 标准库类型 string
 */
int main()
{
    /**
     * 定义和初始化
     * 有多种初始化的方式
     */
    // string s1;           // 默认初始化，s1 是空字符串
    // string s2 = s1;      // 拷贝初始化，s2 也是空字符串
    // string s3 = "hello"; // 拷贝初始化，s3 不包含 '\0'
    // string s4(5, '*');   // 直接初始化
    // 注意：
    // 用字符串字面值作初始值时，
    // 新创建的 string 对象不包含 '\0'

    /**
     * 操作 string 对象
     * IO
     *   os << s        将 s 写到输出流 os 中
     *   is >> s        从 is 中读取字符串赋给 s
     *   getline(is, s) 从 is 中读取一行赋给 s，返回 is
     * 比较
     *   s1 == s2
     *   s1 != s2
     *   <, <=, >, >=
     * 其他操作
     *   s1 + s2   返回 s1 和 s2 拼接后的结果
     *   s1 = s2   赋值
     *   s[n]      下标访问 s 中的字符
     * 常用方法
     *   empty, size, length, capacity
     *   （size,length 返回字符个数，capacity 返回 string 长度）
     *   push_back, append
     *   （push_back 追加字符，append 追加字符串）
     *
     *   insert   插入
     *   replace  修改
     *   substr   取子串
     *   find     找子串
     *   erase    删除
     *   c_str    返回 C 风格字符串，即返回 const char*
     */
    // 逐行读取，直到文件结束
    // string line;
    // while (getline(cin, line))
    //     if (!line.empty())
    //         // 跳过空行
    //         cout << line << endl;

    // size() 的返回类型 string::size_type
    // size_t，即 unsigned long long
    // 注意无符号数和带符号数的混用

    // 标准库允许把字符（串）字面值隐式转换成 string，
    // 所以，
    // 在需要 string 的地方可以用字符（串）字面值代替。
    string s1 = "hello";
    string s2 = "world";
    string s3 = s1 + ", " + "world";
    // string s4 = "hello" + ", " + s2;
    // 等价于 string s4 = ("hello" + ", ") + s2;
    // 错误：不能把字符串字面值直接相加

    /**
     * 操作 string 中的字符
     */
    // 处理每个字符：使用范围 for
    string str("some string");
    for (auto ch : str) // 不改变元素
        cout << ch << " ";
    for (auto &ch : str) // 改变元素
        ch = toupper(ch);
    cout << str << endl;

    // 只处理一部分字符：1.下标访问；2.使用迭代器
    // 这里只讲下标访问。
    // 带符号类型的索引将自动转换成无符号类型，
    // 即 string::size_type
    string str2("hello, world");
    if (!str2.empty())
        cout << str2[0] << endl; // 输出 str2 第一个字符

    // 编写程序把 0~15 的十进制数转换成十六进制数
    const string hexDigits = "0123456789ABCDEF";
    decltype(hexDigits.size()) n; // 存储十进制数
    while (cin >> n)
        if (n < hexDigits.size())
            cout << hexDigits[n] << " ";
    return 0;
}