#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//虽然有了字符函数和字符串函数，但这些函数只能操作字符（只有一个字节）和字符串（只有一个字节是0)
// 对于整型数组，浮点型数组，结构体数组等类型不适用
//
//#include <string.h>
//
//int main()
//{
//    int arr1[] = { 1,2,3,4,5 };
//    int arr2[10] = { 0 };
//
//    //char* dest, const char* sour
//    strcpy(arr2, arr1);
//
//    //调试看结果
//    return 0;
//}
//
//因此引出内存操作函数（需要memory库或string库）



//1.memcpy
// 将strncpy声明中的char*改为void*就是memcpy的声明
// 
// 声明
// void *memcpy( void *dest, const void *src, size_t count );   //count单位是字节
// 
//struct S
//{
//    char name[10];
//    int age;
//};
//int main()
//{
//    int arr1[] = { 1,2,3,4,5 };
//    int arr2[10] = { 0 };
//    memcpy(arr2, arr1, sizeof(arr1));
//
//    struct S arr3[] = { {"peter", 18}, {"mike", 20} };
//    struct S arr4[3] = { 0 };
//    memcpy(arr4, arr3, sizeof(arr3));
//
//    //调试看结果
//    return 0;
//}

//注意事项：拷贝的双方（拷贝源与拷贝目的）不能重叠
// C标准规定：
// memcpy至少可以完成不重叠拷贝
// memmove则是不管重不重叠都可以完成
// 
// 因为vs编译环境下memcpy等同于memmove，所以不作示例
//

//手搓memcpy（仅仅满足标准）
//void* my_memcpy(void* dest, const void* sour, unsigned int count)
//{
//    assert(dest);
//    assert(sour);
//
//    //我写的
//    if (!count) return dest;
//    
//    char* d = (char*)dest;
//    char* s = (char*)sour;
//    while (*d++ = *s++, --count);
//    
//    return dest;
//
//    //鹏哥答案
//    //void* ret = dest;
//    //while (count--)
//    //{
//    //    *(char*)dest = *(char*)sour;
//    //    ++(char*)dest;
//    //    ++(char*)sour;
//    //}
//    //return ret;
//}



//2.memmove
// 
// 声明
// void *memmove( void *dest, const void *src, size_t count );
// 和memcpy的声明一模一样（有深意）
// 
// 注意事项：搞清楚从哪里拷贝到哪里，容易乱
//

//手搓memmove
//void* my_memmove(void* dest, const void* sour, size_t count)
//{
//    assert(dest);
//    assert(sour);
//    char* d = (char*)dest;
//    char* s = (char*)sour;
//
//    if (d < s)
//        while (*d++ = *s++, --count);   //dest在sour左边，则从左到右逐个拷贝
//    else if (d == s)
//        return dest;                       //dest == sour，完全重叠，不用拷贝
//    else if (d <= s + count)
//    {
//        s += count - 1;
//        d += count - 1;
//        while (*d-- = *s--, --count);   //dest在(sour, sour+count]中间，则从右到左逐个拷贝
//    }
//    else
//    {
//        //dest在sour+count右边，可以从左到右逐个拷贝
//        //while (*d++ = *s++, --count);
//
//        //也可以从右到左逐个拷贝
//        s += count - 1;
//        d += count - 1;
//        while (*d-- = *s--, --count);
//    }
//    //可以画区间图方便理解
//
//    return dest;
//}
//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//    //my_memmove(arr, arr + 2, 5 * sizeof(arr[0]));
//    my_memmove(arr + 3, arr + 1, 20);
//
//    //调试看结果
//    return 0;
//}



//3.memcmp
// 将strncmp声明的char*改为void*即为memcmp的声明
// 
// 声明
// int memcmp( const void *buf1, const void *buf2, size_t count );
// 
// 标准规定同strcmp
//
//int main()
//{
//    int arr1[] = { 1,2,3,4,5 };
//    int arr2[] = { 1,2,5,6,7 };
//
//    int ret = memcmp(arr1, arr2, 8);
//    printf("%d\n", ret);
//
//    ret = memcmp(arr1, arr2, 9);
//    printf("%d\n", ret);
//
//    return 0;
//}

//手搓memcmp（略，可参考strncmp）



//4.memset - 内存设置
// Sets buffers to a specified character.
// 
// 声明
// void *memset( void *dest, int c, size_t count );
//
//int main()
//{
//    char arr[10] = "";
//    memset(arr, '!', 10);
//
//    int arr2[10] = { 0 };
//    memset(arr2, 1, 10);
//
//    //调试看结果
//    return 0;
//}
