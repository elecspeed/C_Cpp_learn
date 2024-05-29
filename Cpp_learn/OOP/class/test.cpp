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
 * protected: 类的内部成员，派生类的成员及友元。
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
// 不改变对象、不返回本类引用的成员函数，都设为 const；
// 改变对象、返回本类引用的成员函数，设置两份。
// 一份为普通成员函数，
// 一份为常量成员函数。

/*
 * 建议：将类内公共代码设为 private 内联函数
 * 理由
 * 1.减少代码量
 * 2.可拓展性、可维护性
 *   随着类规模的发展，代码只需改动一处
 * 3.内联函数不会增加开销
 */

/*
 * 与类相关的非成员函数
 *
 * 如果非成员函数是类接口的一部分，
 * 则这些非成员函数应该与类在同一个头文件内。
 * 可设为友元。
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
//     void GetData() const
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
// 我们为内置类型的数据成员提供了类内初始值。
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

/*
 * 委托构造函数
 * 一个构造函数可以把自己的一些或全部功能
 * 委托给其他构造函数。（C++11）
 *
 * 流程
 * 执行完受委托的构造函数后
 * （包括初始化列表和函数体），
 * 控制权才交还给委托者。
 */

/*
 * 聚合类、字面值常量类
 *
 * 聚合类
 * 相当于 C 结构体，所有成员皆为 public。
 * 可以有成员函数。
 *
 * 字面值常量类（略）
 */

/*
 * 类类型转换
 * 接受一个实参的构造函数，
 * 实际上定义了一种类类型转换。
 *
 * 比如下面的代码
 */

// class A
// {
// private:
//     string _a;
// public:
//     A() = default;
//     A(string str); // 定义了一种类类型转换
//     ~A();
//     A &Modify(const A &src);
// };
// A::A(string str) : _a(str) {}
// A::~A() {}
// A &A::Modify(const A &src)
// {
//     _a = src._a;
//     return *this;
// }
// int main()
// {
//     A t("jj");
//     t.Modify(string("hh"));
//     // "hh" -> string -> A
//     //
//     // 从 C 风格字符串 显式转换成 string 类型，
//     // 然后再隐式转换成 A 类型，
//     // 最后传参。
//
//     t.Modify(A("hh"));
//     // 从 C 风格字符串 隐式转换成 string 类型，
//     // 然后再显式转换成 A 类型，
//     // 最后传参。
//     return 0;
// }

/*
 * 隐式类型转换只有一步。
 * 比如
 * t.Modify("hh"); // 错！
 *
 * 需要将 "hh" 转换成 string，
 * 再把这个临时的 string 转换成 A。
 *
 * 显式构造函数
 * explicit
 * 抑制由构造函数定义的隐式转换。
 * （但还是可以显式转换的）
 *
 * 关键字 explicit 只对一个实参的构造函数有效，
 * 只放在类内的构造函数声明开头。
 *
 * 使用 explicit 构造函数初始化对象，
 * 只能用 (),{}，不能用 =,= {}
 *
 * 标准库中的显式构造函数
 * . 接受一个 const char* 的 string，不是 explicit 的
 * . 接受一个 容量参数 的 vector，是 explicit 的
 */

/*
 * 友元
 * 类的友元可以访问类的所有成员。
 *
 * 分类：
 * 友元函数，友元类，友元成员函数
 *
 * 在原来的声明的基础上，以关键字 friend 开头，
 * 即为友元声明。
 * 友元声明只能出现在类内部。
 *
 * 友元声明仅仅指定了访问权限，
 * 换句话说，
 * 友元声明只是关于访问权限的声明，
 * 不是通常意义上的声明。
 *
 * 友元函数可以定义在类的内部，自动视为 inline。
 *
 * 一个类指定了友元类，
 * 则友元类的成员函数可以访问该类的所有成员。
 * 相当于说，
 * 声明一个类为友元 <-> 声明该类的所有成员函数为友元
 *
 * 友元关系不存在传递性。
 */

// class Dog
// {
// private:
//     string _breed;
// public:
//     Dog() = default;
//     Dog(string breed);
//     ~Dog();
//     friend Dog &Mate(Dog &a, Dog &b);
//     friend istream &Read(const Dog &dog, istream &is = cin);
// };
// Dog &Mate(Dog &a, Dog &b);
// istream &Read(const Dog &dog, istream &is = cin);
// Dog::Dog(string breed) : _breed(breed) {}
// Dog::~Dog() {}

// 注意
// 友元声明，函数或类的声明及定义的顺序。

/*
 * 类型成员
 * 必须先定义才能使用，
 * 通常放在类定义的开头，
 * 确保所有成员都在类型成员的定义之后。
 *
 * 可变数据成员
 * 关键字 mutable
 *
 * 可变数据成员不属于类的“常量”属性。
 */

// class C
// {
//     // private:
//     //     C_type _c = 0; // 错！C_type 还未定义。
// public:
//     typedef int C_type; // 类型成员 C_type
//     C() = default;
//     C(C_type c);
//     ~C();
// private:
//     C_type _c = 0;
// };
// C::C(C_type c) : _c(c) {}
// C::~C() {}

/*
 * 类的作用域
 * 一个类就是一个作用域。
 *
 * 在类外部的成员定义，类名:: 之后都在类的作用域内。
 * 比如
 * 定义在类外部的成员函数，
 * 类名:: 之后的参数列表和函数体，
 * 在该类的作用域内。
 * 但注意，返回类型不在。
 *
 * 名字查找
 * 编译器先处理类内的所有声明，
 * 然后才处理成员函数的定义。
 *
 * 所以除了类型成员，其他成员对声明没有顺序要求。
 *
 * 建议：数据成员的名字都以下划线开头，防止命名冲突。
 */

/*
 * 静态成员
 * 关键字 static
 *
 * 静态数据成员存在于静态区，
 * 对象中不包含任何静态数据成员（不为其分配内存）。
 * 类似的，
 * 静态成员函数也不与任何对象绑定，
 * 没有 this 指针。
 *
 * 类内声明。
 *
 * 静态数据成员类外定义，静态成员函数类内外皆可，
 * 其中，类外定义不能重复 static 关键字。
 *
 * 静态数据成员不是由构造函数初始化的，
 * 必须在类外初始化。
 * 除非
 * static constexpr 类型 a = 常量表达式;
 * （有些编译器不支持类内初始值）
 *
 * 建议：
 * 1.把 静态数据成员的定义 和 成员函数的类外定义
 *   放在一起。
 * 2.即使静态数据成员在类内初始化，
 *   也要在类外定义一下。
 *
 * 与普通成员的不同
 * 静态数据成员的类型可以是所属类的类型，
 * 静态成员可以用于成员函数的默认实参。
 */

// #include <vector>
// class classroom
// {
// private:
//     double _area;
//     vector<string> _equipment;
//     static string _teachingBuilding;
//     static classroom _member;
// public:
//     classroom() = default;
//     classroom(double, vector<string> = {"desk", "podium"});
//     void Display();
//     static void SetBuilding(const string &);
// };
// classroom::classroom(double area, vector<string> equipment)
//     : _area(area), _equipment(equipment) {}
// inline void classroom::Display()
// {
//     cout << "area: " << _area << "\n"
//          << "equipment: ";
//     for (int i = 0; i < _equipment.size(); ++i)
//         cout << _equipment[i] << ", ";
//     cout << "\n"
//          << "building: " << _teachingBuilding
//          << endl;
// }
// string classroom::_teachingBuilding = "TeachOne";
// inline void classroom::SetBuilding(const string &building)
// {
//     _teachingBuilding = building;
// }
// int main()
// {
//     classroom c(134);
//     c.Display();
//     return 0;
// }