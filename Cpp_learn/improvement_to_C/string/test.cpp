#include <iostream>
using namespace std;

/*
 * 新增类型 string 类的定义、使用
 */

#include <string> // 使用 string 要包含 <string> 头文件
int main()
{
    // 定义
    string s1;                  // 定义空串 s1
    string s2 = "hello,world!"; // s2 初值为 hello,world!
    string s3 = s2;             // s3 初值为串 s2 的值
    string s4(8, 'A');          // s4 初值为 8 个 A，即 AAAAAAAA

    // 读入
    cin >> s1;
    cout << s1 << endl;
    // 遇到 blank space 结束，blank space 留在缓冲区
    // 同 scanf("%s")

    getline(cin, s1);
    cout << s1 << endl;
    // 读入一行，遇到换行符结束，换行符被读入
    // 同 gets()

    // 赋值
    s1 = s4;
    s1 = '1';
    s1 = {'a', 'b', 'c'};
    cout << "s1=" << s1 << endl;
    // 右边可以是一个 string 串、C 风格的串或一个 char 字符

    // 字符串连结、比较
    s2 = s3 + ' ' + s4;
    cout << s2 << endl;
    bool tmp = s2 > s4;
    cout << boolalpha << tmp << endl;
    // + 运算符实现串连结，> 运算符比较串长度。
    // 运算符重载，+ 和 > 运算符的内涵发生了改变

    // 方法：
    // length, append, insert, replace
    // substr, find, erase, c_str

    // 求串长
    s1 = "abc";
    cout << s1.length() << endl;

    // 尾插
    s1.append(s2);
    cout << s1 << endl;

    // 在 s1 下标为 3 的位置前面插入 s4
    s1.insert(3, s4);
    cout << s1 << endl;

    // 下标 [0,3) 范围内的子串替换成"111"
    s1.replace(0, 3, "111");
    cout << s1 << endl;

    // s2 下标 [0,5) 范围内的子串赋给 s1
    s1 = s2.substr(0, 5);
    cout << s1 << endl;

    // 从 s1 中找 "ll"，
    // 找到返回第一个匹配字符的下标；否则返回 -1
    int pos = s1.find("ll");
    cout << pos << endl;

    // 删除 s1 下标 [0,3) 范围内的子串
    s1.erase(0, 3);
    cout << s1 << endl;

    // 某些情况下需要转成 C 风格的字符串，用方法 c_str

    return 0;
}
