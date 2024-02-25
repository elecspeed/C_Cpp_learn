#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//关机程序
//int main(void){
//	char input[20] = {0};
//	//cmd(command)命令shutdown -s -t 60	:60秒后关机
//	//system()执行系统命令函数
//	system("shutdown -s -t 60");
//again:
//	printf("请注意，你的电脑将在1分钟内关机，如果输入：我是猪，就取消关机\n请输入：");
//	scanf("%s", input);
//	if(strcmp(input, "我是猪") == 0)	//字符串比较函数strcmp()
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}
//授课(goto)
//用于一步跳出多重循环，除此之外少用

//猜数字游戏
//1.生成一个随机数
//2.猜数字
/*void game(){
//1.生成一个随机数
int ret = 0;
//拿时间戳来设置变化的值
//time_t time(time_t* timer)
//ret = rand();//生成随机数0-RAND_MAX
ret = rand()%100 + 1;//生成0-100以内的随机数
//printf("%d\n", ret);
//2.猜数字
while(1){
int guess = 0;

printf("请猜数字：");
scanf("%d", &guess);
if(guess > ret){
printf("猜大了\n");
}else if(guess < ret){
printf("猜小了\n");
}else{
printf("恭喜你，猜中了\n");
break;
}
}

}
//RAND_MAX-32767
//时间戳 当前计算机的时间-计算机的起始时间(1979.1.1.0:0:0)
void menu(){
printf("*************************************\n");
printf("********   1.play   0.exit   ********\n");
printf("*************************************\n");
}
int main(void){
int input = 0;
srand((unsigned int)time(NULL));
do
{
menu();
printf("请选择：");
scanf("%d", &input);
switch (input) {
case 1:
game();
break;
case 0:
printf("游戏退出\n");
break;
default:
printf("选择错误\n");
break;
}
}while(input);
return 0;
}*/


//打印乘法口诀表
//
//int main(void){
//	int i = 0;
//	for(i = 1; i < 9; i++){
//		int j = 0;
//		for(j = 1; j <= i; j++){
//			printf("%d*%d=%-2d ", i, j, i*j);	//-2左对齐
//		}
//		printf("\n");
//	}
//	return 0;
//}


//数字4出现的次数
/*int main(void){
int count = 0;

for(int i=1; i<=100; i++){
if(i%10 == 4)
count++;
if(i/10 == 4)
count++;
}
printf("%d\n", count);
return 0;
}*/


//找最大公约数
/*int main(void){
int m = 0, n = 0;
int r;

scanf("%d%d", &m, &n);
while(r = m%n){
m = n;
n = r;
}
printf("%d", n);
return 0;
}*/


//输入密码
/*int main(void){
char Password[20] = {0};

for(int i=0; i<3; i++){
//		if(Password == "123456")	不能用 == 来比较两个字符串
printf("请输入密码:");
scanf("%s", &Password);
if(strcmp(Password, "123456") == 0){
printf("密码正确\n");
break;
}
if(i == 2){
printf("密码锁定");
}
else{
printf("密码错误，还有%d次机会\n", 2-i);
}
}
return 0;
}*/


//输出延迟和清屏的效果
/*int main(void){
char A[] = "welcome to bit!!!!!!";
char B[] = "####################";

int left = 0;
//	int right = sizeof(A)/sizeof(A[0]) - 2;		//不能只减一；
int right = strlen(A) - 1;


while(left <= right){
system("cls");			//执行系统命令的函数,stdlib库
B[left] = A[left];
B[right] = A[right];
printf("%s\n", B);
Sleep(500);				//延迟0.5秒,window库
left++;
right--;
}
//	printf("%s\n", B);
return 0;
}*/


//二分查找
/*int main(void){
int A[] = {1,2,3,4,5,6,7,8,9,10};			//有序数列
int k;										//要找的数
int left = 0;								//左下标
int right = sizeof(A)/sizeof(A[0]) - 1;		//右下标

scanf("%d", &k);

while(left <= right){
int mid = (left + right) / 2;
if(k < A[mid]){
right = mid - 1;
}else if(k > A[mid]){
left = mid + 1;
}else{
printf("找到了\n");
break;
}
}
if(left > right)
printf("不存在\n");

return 0;
}*/


//授课(if,switch,for,while,do...while,continue,break)
/*int main(void){
char A[100] = {0};
char ch;
int i = 0;

while((ch=getchar()) != '\n')
{
//		if(ch>'9' || ch<'0')			只读入数字
//			continue;
A[i] = ch;
i++;
}
printf("%s", A);

//ctrl + z;
//EOF -> end of file -> -1
while((ch=getchar()) != EOF)
{
putchar(ch);
}

return 0;
}*/


//良好的代码风格
//缓冲区以及三种输入方式gets,scanf,getchar,常见的代码如上
//建议：尽量不在for内部改变循环控制变量，防止失去控制
//for(;;)无限循环；for有两个循环控制变量
//do{...}while其实是至少执行一次的while

