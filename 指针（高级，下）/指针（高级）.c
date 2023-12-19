#include <stdio.h>


//指向函数指针数组的指针
//
//int (*pf)(int, int);			//函数指针
//int (*pfArr[4])(int, int);		//函数指针数组
//int (*(*ppfArr)[4])(int, int);	//指向函数指针数组的指针



//模拟计算机(回调函数简化)
//
//void menu()
//{
//	printf("*************************\n");
//	printf("***  1.Add     2.Sub  ***\n");
//	printf("***  3.Mul     4.Div  ***\n");
//	printf("***       0.exit      ***\n");
//	printf("*************************\n");
//}
//int Add(int x, int y) { return x+y; }
//int Sub(int x, int y) { return x-y; }
//int Mul(int x, int y) { return x*y; }
//int Div(int x, int y) { return x/y; }
//
//void Calc(int (*pf)(int, int))
//{
//	int x = 0, y = 0;
//	
//	printf("请输入两个整数：\n");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pf(x, y));
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch(input)
//		{
//		case 1: Calc(Add);break;
//		case 2: Calc(Sub);break;
//		case 3: Calc(Mul);break;
//		case 4: Calc(Div);break;
//		case 0:
//			printf("计算结束\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//	}while(input);
//	return 0;
//}


//回调函数机制：把A函数的地址传参给B函数，在B函数内通过函数指针pf调用A函数，这就是回调函数机制，
//此时A被称为回调函数
//例：
//void A(...);
//void B(...,void (*pf)(...))	//函数指针作形参
//{
//	...;
//	pf(...);		//B函数内通过函数指针调用A函数（其实是调用传进来的函数，不管是不是A函数）
//	...;
//}
//int main()
//{
//	...;
//	B(...,A);		//把A函数地址传给B
//	...;
//}
//与直接在B函数内调用A函数不同，回调函数机制中只是调用传进来的函数，不一定是A函数
//意义：降低函数间的耦合性（解耦）
//耦合性：不同模块之间的交互程度。
//
//为什么要低耦合？
//因为耦合度过高会导致维护成本增加：改动一个地方会牵连其他地方，造成一系列不好的影响



//模拟计算器（转移表简化）
//
//void menu()
//{
//	printf("*************************\n");
//	printf("***  1.Add     2.Sub  ***\n");
//	printf("***  3.Mul     4.Div  ***\n");
//	printf("***  5.Xor     0.exit ***\n");
//	printf("*************************\n");
//}
//int Add(int x, int y) { return x+y; }
//int Sub(int x, int y) { return x-y; }
//int Mul(int x, int y) { return x*y; }
//int Div(int x, int y) { return x/y; }
//int Xor(int x, int y) { return x^y; }
//
//int main()
//{
//	int input = 0;
//	int x = 0, y = 0;
//	int (*pfArr[])(int, int) = {0, Add, Sub, Mul, Div, Xor};//转移表
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		if(input>=1 && input <=5)
//		{
//			printf("请输入两个整数：\n");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", pfArr[input](x, y));
//		}
//		else if(input == 0)
//			printf("计算结束\n");
//		else
//			printf("选择错误，请重新选择\n");
//		
//	}while(input);
//	return 0;
//}


//函数指针数组
//
//int Add(int x, int y) { return x+y; }
//int Sub(int x, int y) { return x-y; }
//int Mul(int x, int y) { return x*y; }
//int Div(int x, int y) { return x/y; }
//
//int main()
//{
//	int* arr[5];				//指针数组
//	int (*p)(int, int) = Add;	//函数指针
//	
//	//需要一个数组来存多个函数地址，即函数指针数组
//	int (*parr[4])(int, int) = {Add, Sub, Mul, Div};
//	int i = 0;
//	for(i = 0; i < 4; i++)
//		printf("%d ", parr[i](2,3));//5 -1 6 0
//	
//	return 0;
//}
//用法：转移表(见上)



//练习，解释下列代码
//(*(void (*)())0)();
//void (*signal(int, void(*)(int)))(int);
//
//第一个代码
//将0强制类型转换成函数指针类型，即把0看作某函数地址。然后调用该函数
//
//第二个代码等价于下面的代码
//typedef void (* pfun_t)(int);
//pfun_t signal(int, pfun_t);
//即函数signal有两个参数：int和函数指针，返回类型还是该函数指针


//函数指针，指向函数的指针
//&函数名 和 函数名都是函数地址
//
//int sum(int x,int y) { return x+y; }
//int (*p)(int,int) = sum;
//
//void Print(char* arr) { printf("%s", arr); }
//void (*p)(char*) = Print;
//
//通过指针调用函数时可以不写*


//1.字符指针
//2.数组指针
//3.指针数组
//4.数组传参和指针传参
//5.函数指针
//6.函数指针数组
//7.指向函数指针数组的指针
//8.回调函数

