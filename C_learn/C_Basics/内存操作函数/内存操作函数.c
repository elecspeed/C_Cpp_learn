#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

// 虽然有了字符函数和字符串函数，
// 但这些函数只对字符和字符串有用。
//
// 字符是一个字节；
// 字符串是最后一个字节为 0 的数组。
// 对于更一般的整型数组、浮点型数组，
// 甚至是结构体数组，
// 这些函数就不适用了。

// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[10] = {0};
//     strcpy((char *)arr2, (char *)arr1);
//     // 调试观察
//     return 0;
// }

// 由此引出内存操作函数
// （需要 memory.h 库或 string.h 库）

/*
 * 1.memcpy
 * 将 strncpy 声明中的 char* 改为 void*，就是 memcpy 的声明
 *
 * 声明
 * void *memcpy( void *dest, const void *src, size_t count );
 * count 的单位是字节
 */

// struct S
// {
//     char name[10];
//     int age;
// };
// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[10] = {0};
//     memcpy(arr2, arr1, sizeof(arr1));
//
//     struct S arr3[] = {{"peter", 18}, {"mike", 20}};
//     struct S arr4[3] = {0};
//     memcpy(arr4, arr3, sizeof(arr3));
//
//     // 调试观察
//     return 0;
// }

// 注意事项：拷贝的双方（拷贝源与拷贝目的）不能重叠
//
// C 标准规定：
// memcpy 至少可以完成不重叠的拷贝，
// memmove 则是都可以完成。
// 考虑兼容性，尽量使用 memmove。
//
// 因为我当前的编译环境下 memcpy 等同于 memmove，
// 所以不作示例

// 手搓 memcpy（仅仅满足标准）
// #include <assert.h>
// void *MyMemcpy(void *dest, const void *sour, size_t count)
// {
//     assert(dest);
//     assert(sour);
//     // 我写的
//     if (!count)
//         return dest;
//
//     char *d = (char *)dest;
//     char *s = (char *)sour;
//     while (*d++ = *s++, --count)
//         ;
//     return dest;
//
//     // 鹏哥写的
//     // void *ret = dest;
//     // while (count--)
//     // {
//     //     *(char *)dest = *(char *)sour;
//     //     ++(char *)dest;
//     //     ++(char *)sour;
//     //     // 在 VS 下可以编译，但在 VScode,MinGW 下不行
//     // }
//     // return ret;
// }

/*
 * 2.memmove
 *
 * 声明
 * void *memmove( void *dest, const void *src, size_t count );
 * 和 memcpy 的声明一模一样
 * （memcpy 是 memmove 的一种情况而已）
 *
 * 注意事项：搞清楚从哪里拷贝到哪里，容易乱
 */

// 手搓 memmove
// #include <assert.h>
// void *MyMemmove(void *dest, const void *sour, size_t count)
// {
//     assert(dest);
//     assert(sour);
//     if (!count)
//         return dest;
//     char *d = (char *)dest;
//     char *s = (char *)sour;
//
//     // 1.dest < sour，则从低位到高位逐个拷贝
//     // 2.dest == sour，重叠，不用拷贝
//     // 3.dest > sour && dest <= sour + count，
//     //   则从高位到低位逐个拷贝
//     // 4.dest > sour + count，
//     //   既可以从低位到高位，也可以从高位到低位。
//     //
//     // 画区间图方便理解。
//
//     if (d < s)
//         while (*d++ = *s++, --count)
//             ;
//     else if (d == s)
//         return dest;
//     else if (d <= s + count)
//     {
//         // 从高位到低位逐个拷贝
//         s += count - 1;
//         d += count - 1;
//         while (*d-- = *s--, --count)
//             ;
//     }
//     else
//     {
//         // 可以从左到右逐个拷贝
//         // while (*d++ = *s++, --count);
//
//         // 也可以从右到左逐个拷贝
//         s += count - 1;
//         d += count - 1;
//         while (*d-- = *s--, --count)
//             ;
//     }
//     return dest;
// }
// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//     // MyMemmove(arr, arr + 2, 5 * sizeof(arr[0]));
//     MyMemmove(arr + 3, arr + 1, 20);
//
//     // 调试观察
//     return 0;
// }

/*
 * 3.memcmp
 * 将 strncmp 声明中的 char* 改为 void*，即为 memcmp 的声明
 *
 * 声明
 * int memcmp( const void *buf1, const void *buf2, size_t count );
 *
 * 标准规定同 strcmp
 */

// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[] = {1, 2, 5, 6, 7};
//
//     int ret = memcmp(arr1, arr2, 8);
//     printf("%d\n", ret);
//
//     ret = memcmp(arr1, arr2, 9);
//     printf("%d\n", ret);
//     return 0;
// }

// 手搓 memcmp（略，可参考 strncmp）

/*
 * 4.memset
 * Sets buffers to a specified character.
 *
 * 声明
 * void *memset( void *dest, int c, size_t count );
 */

// int main()
// {
//     char arr[10] = "";
//     memset(arr, '!', 10);
//
//     int arr2[10] = {0};
//     memset(arr2, 1, 10);
//
//     // 调试观察
//     return 0;
// }