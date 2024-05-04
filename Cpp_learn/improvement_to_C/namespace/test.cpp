#include <iostream>
using namespace std;

/*
 * 命名空间定义、使用
 */

// 定义命名空间
namespace one
{
    int x = 1;
    int y = 11;
} // namespace one
namespace two
{
    int x = 2;
    int y = 22;
} // namespace two

// 三种使用方式
using namespace one; // 第一种方式。意为默认使用 one 里面的名字
int main()
{
    cout << x << "," << y << endl;

    cout << two::y << endl;
    cout << y << endl;
    // 第二种方式。通过域解析符::一次性使用

    using two::x;
    cout << x << "," << y << endl;
    // 第三种方式。意为在该语句后面，x 默认是 two::x
    // 但是想使用 two 里面的其他内容时，仍要通过域解析符

    void print();
    print();
    return 0;
}
void print()
{
    cout << x << "," << y << endl;
    // main 函数里面的 using two::x，作用域为 main，
    // 影响不到 print 函数里面的 x
}
