#include <stdio.h>
#include <math.h>

//练习：两道经典递归迭代题
//汉诺塔问题
//青蛙跳台阶问题
//递归实现本质：递归调用前面的语句顺序执行n次，然后调用后面的语句逆序执行n次（也可能0次）

//汉诺塔
/*	    递归实现	  */
void move(char x, char y)
{
	printf("%c -> %c\n", x, y);
}
void hanoi(int n, char a, char b, char c)	//妙用参数改变柱子顺序
{
	if(n == 1)
	{
		move(a, c);					//将打印细节交给move实现
	}
	else
	{
		hanoi(n-1, a, c, b);		//将a上的n-1个盘子通过c移到b
		move(a, c);					//把最底下的盘子从a移到c
		hanoi(n-1, b, a, c);		//将b上的n-1个盘子通过a移到c
	}
	
}
//1.递归也是函数，使用递归要考虑函数要素（参数个数、类型，函数返回类型等）
//2.明确递归的核心算法，其他的细节可由其他函数实现
void picture(int n)
{
	for(int i=0; i<12; i++){
		int j = 0;
		printf("*");
		for(j=0; j<=i+n-12; j++)
		{
			printf("-");
		}
		if(j<7){
			printf("\t\t\t*\t\t\t*\n");
		}else{
			printf("\t\t*\t\t\t*\n");
		}
	}
	printf("A\t\t\tB\t\t\tC\n");
}
int main()
{
	int n = 0;
	
	printf("请输入盘子的数量：");
	scanf("%d", &n);
	picture(n);
	printf("\n");
	printf("三根柱子，第一根柱子从大到小摞着%d片圆盘。把圆盘按大小顺序重新摆放在第三根柱子上。\n规定：在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘。\n", n);
	printf("实现顺序：\n");
	hanoi(n, 'A', 'B', 'C');
	
	return 0;
}

//递归与迭代（包括循环，goto）
//系统用栈保存函数，而迭代是队列。因此理论上递归都能用迭代实现，而使用栈的迭代才能转化为递归


//求菲布..数列第n项函数(思想：用三个变量存相邻三项，迭代)
/*
int Fib(int n)
{
int a = 1, b = 1, c = 1;

while(n>2){			//while实现，也可以用for
c = a + b;
a = b;
b = c;
n--;
}
return c;

}
*/


//递归：程序直接或间接调用自身的编程技巧称为递归。
//核心：把大规模复杂问题层层化为与原问题相似的小规模问题，转化过程重复，直到我们设置的停止条件
//		1.停止条件	2.每次递归后要接近停止条件
//注意：大量递归可能会栈溢出

//栈区：局部变量，函数形参
//堆区：动态开辟的内存
//静态区：全局变量，static修饰的变量


//不创建变量，求字符串长度——递归手搓strlen()
/*		递归实现	  */
/*
int my_strlen(char* a)
{
if(*a == '\0'){
return 0;
}
return 1 + my_strlen(a + 1);
}
*/
/*		循环实现	  */
/*
int my_strlen(char* a)
{
int count = 0;
while(*a != '\0'){
count++;
a++;
}
return count;
}
*/

/*
int main()
{
char arr[] = "hhh";
//int len = strlen(arr);	//strlen函数
//printf("%d\n", len);
int len = my_strlen(arr);
printf("len = %d\n", len);

return 0;
}
*/

//递归顺序打印无符号整型每位上的数字
/*
void print(int n)
{
if(n>9){
print(n/10);
}
printf("%d ", n%10);
}
int main()
{
unsigned int num = 0;

scanf("%u", &num);
print(num);

return 0;
}
*/

/*
int main()
{
printf("hhh\n");
main();

return 0;
}
*/



//函数声明的正确用法
//#include "add.h"	//把函数声明放进头文件，函数体放进同路径文件

//同一源文件一般不需要函数声明
//意义：增加开发速度（一个源文件不能被多人同时编写），功能模块化，封装功能实现过程，隐藏不必要的细节
/*
int main()
{
int a = 10;
int b = 20;
int sum = 0;
sum = Add(a, b);
printf("%d", sum);

return 0;
}
*/

//函数的链式访问（把一个函数的返回值作为另一个函数的参数）
/*
int main()
{
printf("%d", printf("%d", printf("%d", 43)));	//printf返回打印字符的个数
return 0;
}
*/

//自增函数
/*
void Add(int* p)
{
// *p++;	//++优先级比*高；
(*p)++;
}
*/

/*int main()
{
int num = 0;

Add(&num);
printf("num = %d\n", num);
Add(&num);
printf("num = %d\n", num);
return 0;
}*/

//二分查找函数
/*
int binary_search(int* a, int b, int c)	//函数内部想使用数组长度，要在函数外传进去
{
int left = 0;
int right = c;
//int right = sizeof(a)/sizeof(a[0]) - 1;//数组在传参时发生类型退化(为了节省空间)，退化为首元素地址
while(left <= right){
int mid = (left + right) / 2;
if(a[mid] == b){
return mid;
}else if(a[mid] < b){
left = mid + 1;
}else{
right = mid - 1;
}
}
return -1;	//没有找到返回-1
}
*/

/*
int main()
{
int arr[] = {1,2,3,4,5,6,7,8,9,10};	
int input = 0, index = 0;
int arr_len = sizeof(arr)/sizeof(arr[0]) - 1;

printf("请输入要找的数字：");
scanf("%d", &input);
index = binary_search(arr, input, arr_len);
if(index == -1){
printf("%d 不存在", input);
}else{
printf("找到了，%d 的下标是 %d", input, index);
}
return 0;
}
*/

//判断素数函数，是返回1，不是返回0
/*
int is_prime(int a)
{
for(int i=2; i<=sqrt(a); i++){
if(a%i == 0)
return 0;
}
return 1;
}
*/

/*
int main(void){
for(int i=100; i<201; i++){
if(is_prime(i)){
printf("%d ", i);
}
}
return 0;
}
*/
