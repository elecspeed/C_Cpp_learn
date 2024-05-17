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
 * public: 所有用户。通常为类的函数接口。
 * private: 类的内部成员及友元。
 * protected: 类的内部成员，派生类的成员及友元
 */

class Student
{
protected:
    int _protected;

private:
    int _age;
    string _name;

public:
    Student(int age = 0, string name = "?", int a = 0);
    void Display();
    ~Student();
};
Student::Student(int age, string name, int a)
{
    _age = age;
    _name = name;
    _protected = a;
}
Student::~Student()
{
}
void Student::Display()
{
    cout << "name: " << _name << ","
         << "age: " << _age << ","
         << "protected: " << _protected << endl;
}

int main()
{
    Student s;
    s.Display();

    Student *p = &s;
    p->Display();
    return 0;
}
// 只有定义了对象，系统才会给对象分配内存空间

/*
 * 成员函数有权访问所有内部成员
 *
 * 成员函数可以在
 */
