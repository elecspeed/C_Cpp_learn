#include <stdio.h>
#include <stdlib.h>

/*
 * 练习使用 qsort
 *
 * 声明
 * void qsort(
 *     void *base,
 *     size_t num,
 *     size_t width,
 *     int(__cdecl *compare)(const void *elem1,
 *                           const void *elem2));
 *
 * qsort 可以排序任一数据类型的数组，但需要提供四个参数。
 * base：第一个元素的地址，
 * num：需要排序的元素个数，
 * width：单个元素的字节长度，
 * compare：两个元素间的比较方法。用回调函数实现。
 *
 * 这四个参数是排序的核心要素。
 * 只有知道这四个要素，才能进行排序。
 * 或者说，
 * 只要知道了这四个要素，不管哪种类型的数组都能进行排序。
 */

// 排序 int 数组
// int cmp_int(const void *e1, const void *e2)
// {
//     // 回调函数要对应函数指针，而函数指针的类型已经限定：
//     // int (*)(const void*, const void*)
//     if (*(int *)e1 > *(int *)e2)
//         return 1;
//     else if (*(int *)e1 == *(int *)e2)
//         return 0;
//     else
//         return -1;
//
//     // 简化（形式上的）
//     // 升序
//     return (*(int *)e1 > *(int *)e2) -
//            (*(int *)e1 < *(int *)e2);
//     // 降序
//     return (*(int *)e1 < *(int *)e2) -
//            (*(int *)e1 > *(int *)e2);
// }
// int main()
// {
//     int arr[] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
//     int num = sizeof(arr) / sizeof(arr[0]);
//
//     qsort(arr, num, sizeof(arr[0]), cmp_int);
//     // 升降序在回调函数内部决定
//
//     int i = 0;
//     for (i = 0; i < num; i++)
//         printf("%d ", arr[i]);
//     return 0;
// }

// 排序结构体数组
// #include <string.h>
// struct student
// {
//     char name[3];
//     int high;
// };
// typedef struct student Stu;
// int cmp_Stu_by_high(const void *e1, const void *e2)
// {
//     if (((Stu *)e1)->high < ((Stu *)e2)->high)
//         return -1;
//     else if (((Stu *)e1)->high > ((Stu *)e2)->high)
//         return 1;
//     else
//         return 0;
// }
// int cmp_Stu_by_name(const void *e1, const void *e2)
// {
//     return strcmp(((Stu *)e1)->name, ((Stu *)e2)->name);
// }
// int main()
// {
//     Stu s[3] = {
//         {"B", 172},
//         {"C", 171},
//         {"A", 170},
//     };
//     int num = sizeof(s) / sizeof(s[0]);
//
//     // 以身高排序
//     qsort(s, num, sizeof(s[0]), cmp_Stu_by_high);
//     // 以名字排序
//     qsort(s, num, sizeof(s[0]), cmp_Stu_by_name);
//     // 调试观察
//     return 0;
// }

/*
 * 手搓 qsort
 *
 * 算法、函数。
 * 先搞定算法，再进行函数封装。
 * 在算法的基础上设计函数接口，并根据接口调整函数内容。
 *
 * 如果只是一般的封装尚可，
 * 关键是 qsort 本身还是递归函数（分治算法），
 * 难度就上来了。
 * （初学的话先写出适用于 int 数组的，再调整）
 */

// 利用 int 数组初步实现快速排序算法：intQuickSort
// #include <time.h>
// void intQuickSort(int *arr, int num)
// {
//     // 排序四要素
//     // 第一个元素的地址：arr
//     // 需要排序的元素个数：num
//     // 单个元素的字节长度：此处默认是 4
//     // 两个元素间的比较方法：此处默认是数值比较
//
//     // 递归终止
//     if (num <= 1)
//         return;
//
//     // 设置随机种子
//     static int s_recursionFlag = 1;
//     if (s_recursionFlag == 1)
//     {
//         srand((unsigned int)time(NULL));
//         s_recursionFlag = 0;
//     }
//
//     // 左右下标、随机下标、中间数
//     int left = 0;
//     int right = num - 1;
//     int randIndex = rand() % num;
//     int mid = arr[randIndex];
//
//     while (left < right)
//     {
//         // 从左往右找比中间数大的
//         // （也可以找比中间数小的，只是升降序的区别）
//         while (arr[left] <= mid && left < right)
//             ++left;
//         // 从右往左找比中间数小的
//         while (arr[right] >= mid && left < right)
//             --right;
//
//         if (left < right)
//         {
//             // 找到了就交换
//             int tmp = arr[left];
//             arr[left] = arr[right];
//             arr[right] = tmp;
//         }
//     }
//     // 最后把中间数交换到中间
//     if (arr[left] < mid && left < randIndex)
//     {
//         arr[randIndex] = arr[left + 1];
//         arr[left + 1] = mid;
//     }
//     else if (arr[left] > mid && left > randIndex)
//     {
//         arr[randIndex] = arr[left - 1];
//         arr[left - 1] = mid;
//     }
//     else
//     {
//         arr[randIndex] = arr[left];
//         arr[left] = mid;
//     }
//
//     // 此时的中间数才是真正意义上的“中间数”：
//     // 中间数左边的都比中间数小，右边的都比中间数大。
//     // （或者，左边的都比中间数大，右边的都比中间数小）
//     // 显然，
//     // 对中间数两边进行同样的操作（递归），
//     // 便能实现排序。
//     intQuickSort(arr, left);
//     intQuickSort(arr + left, num - left);
// }

/*
 * 快速排序几个关键点
 * 1.中间数的选择（中间数是我自己叫的，其实有更专业的名称）
 *   a.不稳妥的
 *     常见的选择是将第一个元素作为中间数。
 *     如果输入是随机的，这是可以接受的。
 *     但如果输入已经有序，（这种情况不少见）
 *     那么对应的时间复杂度为 O(N^2)。
 *   b.保守的
 *     随机选择。
 *     这几乎可以应对所有情况，除非随机数生成器有 bug。
 *     但是，随机数的生成也会有昂贵的开销。
 *   c.中值分割法
 *     比较最左、最右和中心位置的元素，
 *     以三个元素的中间数为中间数。
 * 2.分割策略
 *   实践中有几种分割策略。
 *   分割策略主要考虑的是，怎么样使得
 *   中间数左边的都比其小，右边的都比其大。
 *   （或者左边的都比其大，右边的都比其小）
 * 3.小数组的情形
 *   对于小数组，快速排序不如插入排序。
 *   真正的 qsort 实现会将小数组交给别的排序方式，
 *   这样既可以提高效率，也可以避免一些特殊情况：
 *   面对只有两个元素的数组，选择中间数。
 */

// 仿造 intQuickSort 写 MyQuickSort
static void InsertSort(
	char *base,
	size_t num,
	size_t width,
	int (*const compare)(const void *element1,
						 const void *element2))
{
	// 插入排序
	char *extreme; // 最值元素地址
	char tmp;
	size_t i;
	while (num--)
	{
		extreme = base;
		// 找到其余元素中的最值元素
		for (i = width; i <= num * width; i += width)
			if (compare(extreme, base + i) < 0)
				extreme = base + i;
		// 以字节为单位，将最值元素和当前元素交换
		for (i = 0; i < width; ++i)
		{
			tmp = *base;
			*base++ = *extreme;
			*extreme++ = tmp;
		}
	}
}
#define SWAP(e1, e2, width)                          \
	for (size_t QSORT = 0; QSORT < (width); ++QSORT) \
	{                                                \
		char tmp = (e1)[QSORT];                      \
		(e1)[QSORT] = (e2)[QSORT];                   \
		(e2)[QSORT] = tmp;                           \
	}
void MyQuickSort(
	void *const base,
	const size_t num,
	const size_t width,
	int (*const compare)(const void *element1,
						 const void *element2))
{
	// 检查参数
	if (num < 2 || !base || !width || !compare)
		return;

	// 递归终止
	if (num <= 8)
		InsertSort((char *)base, num, width, compare);
	else
	{
		// 左右端元素地址、中心元素地址
		char *left = (char *)base;
		char *right = (char *)base + (num - 1) * width;
		char *mid = (char *)base + num / 2 * width;

		// 中值分割法选择中间元素，顺便给这三个元素排序（有妙处）
		if (compare(left, mid) > 0)
		{
			SWAP(left, mid, width)
		}
		if (compare(mid, right) > 0)
		{
			SWAP(mid, right, width)
		}
		if (compare(left, mid) > 0)
		{
			SWAP(left, mid, width)
		}
		// 此时，left <= mid <= right
		// 中间元素和倒数第二个元素交换
		SWAP(mid, right - width, width)
		char *median = right - width;
		// 此时，倒数第二个元素是中间元素。

		char *i = left + width;
		char *j = median - width;
		for (;;)
		{
			while (compare(i, median) < 0)
				i += width;
			while (compare(j, median) > 0)
				j -= width;
			// 得益于前面的排序，i 和 j 不会越界

			if (i < j)
			{
				SWAP(i, j, width)
			}
			else
				break;
		}
		SWAP(i, median, width)
		// 成为了真正意义上的“中间元素”

		size_t leftnum = (i - left) / width - 1;
		size_t rightnum = num - leftnum - 1;
		MyQuickSort(left, leftnum, width, compare);
		MyQuickSort(i + width, rightnum, width, compare);
	}
}
// 用 MyQuickSort 排序结构体数组
#include <string.h>
struct book
{
	char name[3];
	float price;
};
typedef struct book Book;
int cmp_Book_by_price(const void *e1, const void *e2)
{
	if (((Book *)e1)->price > ((Book *)e2)->price)
		return 1;
	else if (((Book *)e1)->price < ((Book *)e2)->price)
		return -1;
	else
		return 0;
}
int cmp_Book_by_name(const void *e1, const void *e2)
{
	return strcmp(((Book *)e1)->name, ((Book *)e2)->name);
}
int main()
{
	Book b[3] = {{"a", 3.0}, {"c", 2.0}, {"b", 4.0}};
	int num = sizeof(b) / sizeof(b[0]);

	// 以价格排序
	MyQuickSort(b, num, sizeof(b[0]), cmp_Book_by_price);
	// 以名字排序
	MyQuickSort(b, num, sizeof(b[0]), cmp_Book_by_name);

	// 调试观察
	return 0;
}