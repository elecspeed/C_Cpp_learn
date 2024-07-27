#include <iostream>
#include <vector>
using namespace std;

/*
 * 迭代器（iterator，又译为泛型指针）
 * 迭代器对于容器，好比指针对于数组。
 * 换句话说，
 * 迭代器是模仿指针和数组的关系，
 * 在容器的基础上抽象出的概念。
 *
 * 访问 string 中的字符有两种方法
 * 1.下标访问  2.使用迭代器
 * 所有标准库容器都可以使用迭代器，
 * 但只有其中少数几种才支持下标运算。
 */

/*
 * 内置指针能参与的计算
 * 1.间接访问
 *   *（解引用）, ->, []（其实是 *(ptr + n)）
 * 2.加上或减去一个整数
 *   表示指针前进或后退 n 个对象
 *   ptr + n, ptr - n, ++, --
 * 3.指针减指针
 *   结果是相差的对象个数（结果类型 ptrdiff_t）
 *   ptr1 - ptr2
 * 4.比较
 *   ==, !=, <, <=, >, >=
 */
int main()
{
    /**
     * 使用成员函数 begin 和 end
     *
     * begin 返回指向首元素的迭代器，
     * end 返回指向尾元素下一位置的迭代器，为尾（后）迭代器
     * （尾迭代器仅用来标记，
     * （没有什么实际含义。
     * （解引用尾迭代器是未定义行为。
     */
    vector<int> v(5, 1);
    auto b = v.begin(), e = v.end(); // vector<int>::iterator

    /**
     * 迭代器类型
     * 就像不知道 string 和 vector 的 size_type 类型一样，
     * 一般来说我们也不需要知道迭代器的类型。
     */
    vector<int> v2;
    const vector<int> v3;
    auto it2 = v2.begin(); // vector<int>::iterator
    auto it3 = v3.begin(); // vector<int>::const_iterator
    // 如果对象是常量，
    // begin 和 end 返回 const_iterator（常量泛型指针），
    // 否则返回 iterator。
    // 为了专门得到 const_iterator，
    // C++11 引入了 cbegin, cend（C++11）。
    auto const_begin = v2.cbegin(); // vector<int>::const_iterator
    auto const_end = v2.cend();     // vector<int>::const_iterator

    /**
     * 标准库容器共有的迭代器运算
     * 1.间接访问
     *   *, ->
     * 2.自增自减（都是前置）
     *   ++, --
     * 3.比较
     *   ==, !=
     *
     * C++ 程序员在 for 循环中使用 != 而非 < 进行判断的原因，
     * 与他们更愿意使用迭代器而非下标的原因一样：
     * 这种编程风格在所有标准库容器上都有效。
     */

    /**
     * vector 和 string 特有的迭代器运算
     * 1.间接访问
     *   []
     * 2.加上或减去一个整数
     *   it + n,
     *   it - n,
     *   +=, -=
     * 3.迭代器减迭代器（结果类型 difference_type）
     *   it1 - it2
     * 4.比较
     *   <, <=, >, >=
     *
     * vector 和 string 的迭代器非常贴近内置指针
     *
     * 注：
     * 改变 vector 和 string 容量的操作，
     * 可能会使指向二者的迭代器失效。
     */
    // 二分查找
    vector<int> ivec;
    for (int i = 0; i < 100; i++)
        ivec.push_back(i); // ivec 有序
    int sought;            // 要找的数
    cin >> sought;
    auto first = ivec.begin(), last = ivec.end();
    auto mid = first + (last - first) / 2; // 中间点
    while (mid != last)
    {
        if (*mid > sought)
            last = mid;
        else if (*mid == sought)
            break;
        else
            first = mid + 1;
        mid = first + (last - first) / 2; // 新的中间点
    }
    if (mid == last)
        cout << "No find." << endl;
    else
        cout << "Find it at index "
             << mid - ivec.begin() << endl;
    // 问：
    // 为什么 mid = first + (last - first) / 2，
    // 而非 mid = (first + last) / 2
    return 0;
}