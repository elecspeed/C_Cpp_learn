#include <iostream>
using namespace std;

/*
 * 输入/输出控制，I/O 流
 */

// 输入两个整数，如果第一个整数大于第二个则输出差值，否则输出和
bool larger(int x, int y)
{
    // 比较 x, y
    return x > y ? true : false;
}
int main()
{
    int a, b;
    cout << "请输入两个数：" << endl;
    cin >> a >> b;

    bool ret = larger(a, b);
    cout << ret << " " << boolalpha << ret << " "
         << noboolalpha << ret << endl;
    // 操纵符 boolalpha 将输出 true 和 false 时改为文本输出，
    // noboolalpha 将输出 true 和 false 时改为数字输出
    // 一开始默认是数字输出

    if (ret == 1)
        cout << a << "-" << b << "=" << a - b << endl;
    else
        cout << a << "+" << b << "=" << a + b << endl;

    return 0;
}