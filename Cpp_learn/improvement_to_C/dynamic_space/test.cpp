#include <iostream>
using namespace std;

/*
 * 动态内存分配
 * C 语言用 malloc,realloc,free 等库函数实现动态内存分配；
 * C++ 用 new,delete 运算符实现更简单的动态内存分配。
 */

// int main()
// {
//     // 申请一个动态变量并释放
//     int *p_int = new int;
//     double *p_double = new double;
//     delete p_int;
//     delete p_double;
//     p_int = nullptr;
//     p_double = nullptr;
//
//     // 申请一个一维动态数组并释放
//     int *p_arr = new int[10];
//     delete[] p_arr;
//     p_arr = nullptr;
//
//     // 申请一个二维动态数组并释放
//     int **p_2Darr;
//     p_2Darr = new int *[3];
//     for (int i = 0; i < 3; ++i)
//         p_2Darr[i] = new int[10];
//     for (int i = 0; i < 3; ++i)
//         delete[] p_2Darr[i];
//     delete[] p_2Darr;
//     p_2Darr = nullptr;
//
//     return 0;
// }

// 同 C，动态内存分配也要：
// 1.检查是否成功分配内存；
// 2.释放内存后，将 nullprt 赋予空悬指针

/*
 * 练习
 * 生成 N 个 0~99 的随机整数，统计其中奇数的个数。
 * 要求：用动态一维数组存储这些整数，用一个动态变量统计结果
 */

// #include <cstdlib>
// #include <ctime>
// int main()
// {
//     int n = 0;
//     cin >> n;
//
//     srand((unsigned int)time(nullptr));
//     int *arr = new int[n];
//     if (!arr)
//     {
//         cout << "allocation failure." << endl;
//         return -1;
//     }
//     for (int i = 0; i < n; ++i)
//         arr[i] = rand() % 100;
//
//     int *count = new int(0);
//     for (int i = 0; i < n; ++i)
//         if (arr[i] & 1)
//             ++*count;
//
//     cout << *count << endl;
//     delete[] arr;
//     arr = nullptr;
//     delete count;
//     count = nullptr;
//     return 0;
// }
