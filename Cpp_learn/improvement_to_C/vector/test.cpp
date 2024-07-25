#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * 标准库类型 vector
 */
int main()
{
    /**
     * vector 是模板而非类型，
     * vector<...> 才是类型。
     *
     * 可以将模板看成是编译器生成类或函数的一份说明，
     * 编译器根据模板创建类或函数的过程叫做实例化。
     */
    // vector vec; // 缺少元素类型的说明

    // vector 能容纳绝大多数类型的对象，
    // 甚至组成 vector 的元素也可以是 vector。
    // 因为引用不是对象，
    // 所以引用不能做 vector 的元素。
    vector<int> ivec;
    vector<vector<int>> file;
    // 老式的声明：vector<vector<int> > file

    /**
     * 定义和初始化
     */
    vector<int> v;           // 默认初始化
    vector<int> v2(v);       // 拷贝初始化
    vector<int> v3 = v;      // 同 vector<int> v2(v);
    vector<int> v4(5, 1);    // 包含 5 个重复的 1
    vector<int> v5(5);       // 包含 5 个重复的默认初始化的元素
    vector<int> v6{1, 2};    // 列表初始化（C++11）
    vector<int> v7 = {1, 2}; // 等价于 vector<int> v6{1, 2};

    // {} 和 ()
    vector<string> strv1{"hi"};
    // vector<string> strv2("hi"); // 错误
    vector<string> strv3{10};       // 同 strv3(10)
    vector<string> strv4{10, "hi"}; // 同 strv4(10, "hi");
    // {} 表示我们想列表初始化，
    // 初始化过程会尽可能地把 {} 当成是列表初始化来处理。
    // 只有无法执行列表初始化时，
    // 才将尝试用 () 代替 {} 进行初始化。

    return 0;
}