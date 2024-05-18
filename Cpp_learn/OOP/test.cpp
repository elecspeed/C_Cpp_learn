#include <string>
#include <iostream>
using namespace std;

/*
 * 类与对象
 * 类是某一对象的抽象，
 * 对象是某一类的实例。
 *
 * 类的静态属性：数据成员；
 * 类的动态属性：成员函数
 *
 * 访问属性（又称为访问权限）
 * 三种访问说明符
 * public: 所有用户。
 * private: 类的内部成员及友元。
 * protected: 类的内部成员，派生类的成员及友元
 *
 * 通常将数据成员定义为 private 或 protected，
 * 将成员函数定义为 public。
 */

// class Student
// {
// protected:
//     int _protected;
// private:
//     int _age;
//     string _name;
// public:
//     Student(int age = 0, string name = "?", int a = 0);
//     void Display();
//     ~Student();
// };
// Student::Student(int age, string name, int a)
// {
//     _age = age;
//     _name = name;
//     _protected = a;
// }
// Student::~Student()
// {
// }
// inline void Student::Display()
// {
//     cout << "name: " << _name << ","
//          << "age: " << _age << ","
//          << "protected: " << _protected << endl;
// }
// int main()
// {
//     Student s(1, "abcd", 1);
//     Student *p = &s;
//     s.Display();
//     p->Display();
//     return 0;
// }
// 只有定义了对象，系统才会给对象分配内存空间

/*
 * 关键字 struct 和 class 的区别
 * 只有一个：
 * struct 的默认访问权限为 public，
 * class 的默认访问权限为 private。
 */

/*
 * 成员函数有权访问所有内部成员。
 *
 * 成员函数的实现代码可以放在类的内部，也可以放在外部。
 * 放在内部，被自动视为内联函数。
 * 放在外部，定义必须与声明匹配。
 *
 * 递归函数和返回地址的函数不能设为 inline。
 */

/*
 * this 指针
 * C++ 中，每个成员函数都有一个隐含指针，为 this 指针。
 *
 * inline void Student::Display()
 * 等价于
 * inline void Student::Display(Student *const this)
 *
 * s.Display()
 * 等价于
 * Student::Display(&s)
 *
 * this 指针是一个常量指针。
 */

/*
 * 常量成员函数
 *
 * this 指针是顶层 const。
 * 例如上面的 Student 类：Student *const this，
 * 是不能指向 const Student 对象的。
 * 也就是说，
 *
 * const Student s;
 * s.Display();
 *
 * 是非法的。
 *
 * 要解决这一问题，必须修改 this 指针的类型，
 * 使其变为 const Student *const this。
 * 然而，this 指针是隐式的，
 * 在哪里将 this 声明为指向常量的指针？
 *
 * C++ 的做法是把 const 放在成员函数的参数列表后。
 * 这时，
 * 使用 const 的成员函数就被称为常量成员函数。
 *
 * 这里的 const 的作用是修改 this 指针的类型。
 */

// class Book
// {
// private:
//     double _price;
//     string _name;
//     string _writer;
// public:
//     Book(double price = 0, string name = "?", string writer = "?");
//     ~Book();
//     void Display() const
//     {
//         cout << "name: " << _name << ","
//              << "writer: " << _writer << ","
//              << "price: " << _price << endl;
//     }
// };
// Book::Book(double price, string name, string writer)
//     : _price(price), _name(name), _writer(writer) {}
// Book::~Book() {}
// int main()
// {
//     Book b(3.14, "hhh", "Joe");
//     const Book *p = &b;
//     b.Display();
//     p->Display();
//     return 0;
// }

// tip:
// 不改变对象的成员函数，都设为 const；
// 改变对象的成员函数，设置两份。
// 一份为普通成员函数，
// 一份为常量成员函数。
// 可重载

/*
 * 与类相关的非成员函数
 *
 * 如果非成员函数是类接口的一部分，
 * 则这些非成员函数应该与类在同一个头文件内。
 */

/*
 * 构造函数
 * 类通过构造函数来初始化对象，
 * 构造函数的唯一目的就是初始化数据成员。
 *
 * 特点：
 * 1.名字与类名相同
 * 2.没有返回类型
 * 3.一定为 public
 * 4.不能被声明为 const。
 *   （创建一个 const 对象时，
 *   （直到构造函数完成初始化过程，
 *   （该对象才有“常量”属性。）
 *
 * 默认构造函数
 * 没有任何参数的构造函数就是默认构造函数。
 *
 * 如果我们没有提供任何构造函数，
 * 编译器将为我们隐式定义一个默认构造函数。
 *
 * 但是，
 * 一旦我们提供了任意一种构造函数，
 * 编译器就不会合成默认构造函数。
 */

// class car
// {
// private:
//     const double _weight = 0;
//     double _speed = 0;
//     const string _brand;
// public:
//     car() = default;
//     car(const double weight,
//         double speed,
//         const string brand);
//     ~car();
//     void GetData()
//     {
//         cout << "weight: " << _weight << ", "
//              << "speed: " << _speed << ", "
//              << "brand: " << _brand << endl;
//     }
// };
// car::car(const double weight, double speed, const string brand)
//     : _weight(weight), _speed(speed), _brand(brand) {}
// car::~car() {}

// car() = default;
// 等价于由编译器提供的默认构造函数（C++11）

// 上面的类的定义中，
// 我们为内置类型的数据成员提供了初始值。
// 有些编译器不支持。

/*
 * 构造函数初始化列表
 *
 * 某些数据成员的初始化必须由初始化列表来进行。
 * 比如 const，引用 或 某些未提供默认构造函数的类类型。
 *
 * 不在初始化列表的数据成员，
 * 由类内初始值 或 编译器默认初始化。
 * 这意味着，
 * 一旦构造函数体开始执行，
 * 初始化就完成了。
 *
 * 除了在底层效率的区别外，
 * 更关键的是一些数据成员必须被初始化。
 * 建议使用初始化列表，养成习惯。
 *
 * 初始化的顺序
 * 与类定义中出现的顺序一致。
 * 建议保持初始化列表的顺序与成员声明的顺序一致。
 */
