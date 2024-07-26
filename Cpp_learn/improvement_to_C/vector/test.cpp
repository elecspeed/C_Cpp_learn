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
    // vector<int> ivec;
    // vector<vector<int>> vec_vec;
    // 老式的声明：vector<vector<int> > vec_vec

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
    // 编译器才将尝试用 () 代替 {} 进行初始化。

    // 对于 vector，初始化适用于：
    // 1.初始值已知且数量较少
    // 2.初始值是另一个 vector 对象
    // 3.所有元素的初始值都一样
    //
    // 然而更常见的是，
    // 先创建一个空 vector，
    // 然后用成员函数 push_back 向其中添加元素。
    //
    // 注：
    // 如果循环体内包含有向 vector 添加元素的语句，
    // 则不能使用范围 for。
    // （范围 for 语句预存了 end() 的值，即尾后迭代器。
    // （而向 vector 添加元素会导致尾后迭代器失效。

    /**
     * 其他 vector 操作
     * 比较
     *   v1 == v2
     *   v1 != v2
     *   <, <=, >, >=
     * （只有当元素可比较时，vector 对象才能比较）
     * 赋值拷贝
     *   v1 = v2
     *   v1 = {a,b,c,...}
     * 其他
     *   v[n]
     * 常用方法
     *   empty, size, capacity
     *   push_back
     *   begin, end
     */
    // 编程统计分数段
    // 有一组成绩，取值范围 0~100。
    // 以 10 分为一个分数段，统计各分数段有多少个成绩
    vector<int> scores(11, 0); // 11 个分数段。
    unsigned grade;
    while (cin >> grade)
        if (grade <= 100)
            ++scores[grade / 10];
    for (auto i : scores)
        cout << i << " ";

    // 不能使用下标添加元素，
    // 只能对已存在的元素执行下标操作。
    // 否则 buffer overflow
    return 0;
}