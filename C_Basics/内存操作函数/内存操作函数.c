#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//��Ȼ�����ַ��������ַ�������������Щ����ֻ�ܲ����ַ���ֻ��һ���ֽڣ����ַ�����ֻ��һ���ֽ���0)
// �����������飬���������飬�ṹ����������Ͳ�����
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
//    //���Կ����
//    return 0;
//}
//
//��������ڴ������������Ҫmemory���string�⣩



//1.memcpy
// ��strncpy�����е�char*��Ϊvoid*����memcpy������
// 
// ����
// void *memcpy( void *dest, const void *src, size_t count );   //count��λ���ֽ�
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
//    //���Կ����
//    return 0;
//}

//ע�����������˫��������Դ�뿽��Ŀ�ģ������ص�
// C��׼�涨��
// memcpy���ٿ�����ɲ��ص�����
// memmove���ǲ����ز��ص����������
// 
// ��Ϊvs���뻷����memcpy��ͬ��memmove�����Բ���ʾ��
//

//�ִ�memcpy�����������׼��
//void* my_memcpy(void* dest, const void* sour, unsigned int count)
//{
//    assert(dest);
//    assert(sour);
//
//    //��д��
//    if (!count) return dest;
//    
//    char* d = (char*)dest;
//    char* s = (char*)sour;
//    while (*d++ = *s++, --count);
//    
//    return dest;
//
//    //�����
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
// ����
// void *memmove( void *dest, const void *src, size_t count );
// ��memcpy������һģһ���������⣩
// 
// ע�����������������������������
//

//�ִ�memmove
//void* my_memmove(void* dest, const void* sour, size_t count)
//{
//    assert(dest);
//    assert(sour);
//    char* d = (char*)dest;
//    char* s = (char*)sour;
//
//    if (d < s)
//        while (*d++ = *s++, --count);   //dest��sour��ߣ���������������
//    else if (d == s)
//        return dest;                       //dest == sour����ȫ�ص������ÿ���
//    else if (d <= s + count)
//    {
//        s += count - 1;
//        d += count - 1;
//        while (*d-- = *s--, --count);   //dest��(sour, sour+count]�м䣬����ҵ����������
//    }
//    else
//    {
//        //dest��sour+count�ұߣ����Դ������������
//        //while (*d++ = *s++, --count);
//
//        //Ҳ���Դ��ҵ����������
//        s += count - 1;
//        d += count - 1;
//        while (*d-- = *s--, --count);
//    }
//    //���Ի�����ͼ�������
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
//    //���Կ����
//    return 0;
//}



//3.memcmp
// ��strncmp������char*��Ϊvoid*��Ϊmemcmp������
// 
// ����
// int memcmp( const void *buf1, const void *buf2, size_t count );
// 
// ��׼�涨ͬstrcmp
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

//�ִ�memcmp���ԣ��ɲο�strncmp��



//4.memset - �ڴ�����
// Sets buffers to a specified character.
// 
// ����
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
//    //���Կ����
//    return 0;
//}
