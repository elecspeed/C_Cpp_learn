#include <stdio.h>

/*
 * 1.字符指针
 * 2.数组指针
 * 3.指针数组
 * 4.数组传参和指针传参
 * 5.函数指针
 * 6.函数指针数组
 * 7.指向函数指针数组的指针
 * 8.回调函数
 */

// 模拟计算机（回调函数）
// void menu()
// {
//     printf("*************************\n");
//     printf("***  1.Add     2.Sub  ***\n");
//     printf("***  3.Mul     4.Div  ***\n");
//     printf("***       0.exit      ***\n");
//     printf("*************************\n");
// }
// int Add(int x, int y) { return x + y; }
// int Sub(int x, int y) { return x - y; }
// int Mul(int x, int y) { return x * y; }
// int Div(int x, int y) { return x / y; }
// void Calc(int (*pf)(int, int))
// {
//     int x = 0, y = 0;
//     printf("请输入两个整数\n");
//     scanf("%d%d", &x, &y);
//     printf("%d\n", pf(x, y));
// }
// int main()
// {
//     int input = 0;
//     do
//     {
//         menu();
//         printf("请选择：");
//         scanf("%d", &input);
//         switch (input)
//         {
//         case 1:
//             Calc(Add);
//             break;
//         case 2:
//             Calc(Sub);
//             break;
//         case 3:
//             Calc(Mul);
//             break;
//         case 4:
//             Calc(Div);
//             break;
//         case 0:
//             printf("计算结束\n");
//             break;
//         default:
//             printf("选择错误，请重新选择\n");
//             break;
//         }
//     } while (input);
//     return 0;
// }

// 回调函数：被作为实参的函数
//   把不同功能的代码封装成独立的函数，
//   需要使用这些功能时，
//   要么直接调用，要么将其作为参数传递给相应的函数。
//   第二种方法便是回调函数。
//
// 把函数名 A （即 A 函数地址）传参给 B 函数，用函数指针 pf 接收，
// 然后在 B 函数内通过函数指针 pf 调用 A 函数，
// 这就是回调函数机制。
// 此时 A 被称为回调函数。
//
// 例：
// void A();
// void B(int, void (*pf)()) // 函数指针作形参
// {
//     // ...
//     pf();
//     // B 函数内通过函数指针调用传进来的函数（不管是不是 A 函数）
//     // ...
// }
// int main()
// {
//     // ...
//     B(1024, A);
//     // 把函数名 A （即 A 函数地址）传给 B
//     // ...
// }

// 不同于在 B 函数内部直接调用 A 函数，
// A 函数是在调用 B 函数的时候才确定的。
// 也就是说，
// 只有到了需要使用 B 函数的时候，才能根据具体情形确定 A 函数。
//
// 作用与意义
// 1.降低函数间的耦合度（简称解耦）
//   （耦合度：不同模块之间的交互程度。）
// 2.异步编程与非阻塞操作
// 3.灵活，可拓展

// 指向函数指针数组的指针
//
// int (*pf)(int, int);           // 函数指针
// int (*pfArr[4])(int, int);     // 函数指针数组
// int (*(*ppfArr)[4])(int, int); // 指向函数指针数组的指针

// 函数指针数组
// int Add(int x, int y) { return x + y; }
// int Sub(int x, int y) { return x - y; }
// int Mul(int x, int y) { return x * y; }
// int Div(int x, int y) { return x / y; }
// int main()
// {
//     // 如何声明一个一维数组？
//     // 先以基本类型的数组为例
//     int *ptr_int;        // int* 类型
//     int *arr_ptr_int[5]; // int* 类型一维数组
//     // 由此可见，
//     // 在变量声明中的变量名后面加上 []，
//     // 该声明就变成了一维数组声明，数组元素的类型为原来变量的类型。
//
//     int (*ptr_func)(int, int) = Add;
//     int (*arr_ptr_func[4])(int, int) = {Add, Sub, Mul, Div};
//     int i = 0;
//     for (i = 0; i < 4; i++)
//         printf("%d ", arr_ptr_func[i](2, 3));
//     return 0;
// }

// 函数指针数组的应用场景：转移表

// 模拟计算器（转移表）
// void menu()
// {
//     printf("*************************\n");
//     printf("***  1.Add     2.Sub  ***\n");
//     printf("***  3.Mul     4.Div  ***\n");
//     printf("***  5.Xor     0.exit ***\n");
//     printf("*************************\n");
// }
// int Add(int x, int y) { return x + y; }
// int Sub(int x, int y) { return x - y; }
// int Mul(int x, int y) { return x * y; }
// int Div(int x, int y) { return x / y; }
// int Xor(int x, int y) { return x ^ y; }
// int main()
// {
//     int input = 0;
//     int x = 0, y = 0;
//     int (*pfArr[])(int, int) = {0, Add, Sub, Mul, Div, Xor}; // 转移表
//     do
//     {
//         menu();
//         printf("请选择：");
//         scanf("%d", &input);
//         if (input >= 1 && input <= 5)
//         {
//             printf("请输入两个整数\n");
//             scanf("%d%d", &x, &y);
//             printf("%d\n", pfArr[input](x, y));
//         }
//         else if (input == 0)
//             printf("计算结束\n");
//         else
//             printf("选择错误，请重新选择\n");
//     } while (input);
//     return 0;
// }

// 练习，解释下列代码
//(*(void (*)())0)();
// void (*signal(int, void(*)(int)))(int);
//
// 第一个代码
// 将 0 强制类型转换成函数指针类型，即把 0 看作某函数地址，
// 然后调用该函数。
//
// 第二个代码等价于下面的代码
// typedef void (* pfun_t)(int);
// pfun_t signal(int, pfun_t);
// 即函数 signal 有两个参数：int 和函数指针，
// 返回类型还是该函数指针

// 函数指针：指向函数的指针
// &函数名 和 函数名都是函数地址
//
// int sum(int x,int y) { return x+y; }
// int (*p)(int,int) = sum;
//
// void Print(char* arr) { printf("%s", arr); }
// void (*p)(char*) = Print;
//
// 通过函数指针调用函数时可以不写 *