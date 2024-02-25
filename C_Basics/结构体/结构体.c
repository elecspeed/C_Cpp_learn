#include <stdio.h>


//内存：栈区，堆区和静态区
//
//栈区：局部变量，形参，函数调用等
//堆区：动态内存分配malloc/free,realloc,calloc
//静态区：全局变量，静态变量


//结构体传参建议用指针（虽然也可以直接传结构体）
//理由：1.函数传参时参数压栈，所传结构体过大则系统开销较大，影响性能。2.传地址可以改变实参

//练手创建结构，声明结构变量并初始化，嵌套结构，访问等
typedef struct Book
{
	char name[20];
	char writer[20];
	double price;
}Book;

struct T
{
	char arr[10];
	int ret;
	double num;
};
struct S
{
	char ch;
	struct T t;
	int* p;
};

int main()
{
	struct S s = {'0', {"hh", 8, 3.14}, NULL};
	
	printf("%d\n", s.t.ret);
	printf("%p\n", s.p);
	printf("%lf\n", s.t.num);
	printf("%c\n", s.ch);
	printf("%s\n", s.t.arr);
	
	return 0;
}
