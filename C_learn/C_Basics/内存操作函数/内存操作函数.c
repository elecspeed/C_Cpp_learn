#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

// ��Ȼ�����ַ��������ַ���������
// ����Щ����ֻ���ַ����ַ������á�
//
// �ַ���һ���ֽڣ�
// �ַ��������һ���ֽ�Ϊ 0 �����顣
// ���ڸ�һ����������顢���������飬
// �����ǽṹ�����飬
// ��Щ�����Ͳ������ˡ�

// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[10] = {0};
//     strcpy((char *)arr2, (char *)arr1);
//     // ���Թ۲�
//     return 0;
// }

// �ɴ������ڴ��������
// ����Ҫ memory.h ��� string.h �⣩

/*
 * 1.memcpy
 * �� strncpy �����е� char* ��Ϊ void*������ memcpy ������
 *
 * ����
 * void *memcpy( void *dest, const void *src, size_t count );
 * count �ĵ�λ���ֽ�
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
//     // ���Թ۲�
//     return 0;
// }

// ע�����������˫��������Դ�뿽��Ŀ�ģ������ص�
//
// C ��׼�涨��
// memcpy ���ٿ�����ɲ��ص��Ŀ�����
// memmove ���Ƕ�������ɡ�
// ���Ǽ����ԣ�����ʹ�� memmove��
//
// ��Ϊ�ҵ�ǰ�ı��뻷���� memcpy ��ͬ�� memmove��
// ���Բ���ʾ��

// �ִ� memcpy�����������׼��
// #include <assert.h>
// void *MyMemcpy(void *dest, const void *sour, size_t count)
// {
//     assert(dest);
//     assert(sour);
//     // ��д��
//     if (!count)
//         return dest;
//
//     char *d = (char *)dest;
//     char *s = (char *)sour;
//     while (*d++ = *s++, --count)
//         ;
//     return dest;
//
//     // ����д��
//     // void *ret = dest;
//     // while (count--)
//     // {
//     //     *(char *)dest = *(char *)sour;
//     //     ++(char *)dest;
//     //     ++(char *)sour;
//     //     // �� VS �¿��Ա��룬���� VScode,MinGW �²���
//     // }
//     // return ret;
// }

/*
 * 2.memmove
 *
 * ����
 * void *memmove( void *dest, const void *src, size_t count );
 * �� memcpy ������һģһ��
 * ��memcpy �� memmove ��һ��������ѣ�
 *
 * ע�����������������������������
 */

// �ִ� memmove
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
//     // 1.dest < sour����ӵ�λ����λ�������
//     // 2.dest == sour���ص������ÿ���
//     // 3.dest > sour && dest <= sour + count��
//     //   ��Ӹ�λ����λ�������
//     // 4.dest > sour + count��
//     //   �ȿ��Դӵ�λ����λ��Ҳ���ԴӸ�λ����λ��
//     //
//     // ������ͼ������⡣
//
//     if (d < s)
//         while (*d++ = *s++, --count)
//             ;
//     else if (d == s)
//         return dest;
//     else if (d <= s + count)
//     {
//         // �Ӹ�λ����λ�������
//         s += count - 1;
//         d += count - 1;
//         while (*d-- = *s--, --count)
//             ;
//     }
//     else
//     {
//         // ���Դ������������
//         // while (*d++ = *s++, --count);
//
//         // Ҳ���Դ��ҵ����������
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
//     // ���Թ۲�
//     return 0;
// }

/*
 * 3.memcmp
 * �� strncmp �����е� char* ��Ϊ void*����Ϊ memcmp ������
 *
 * ����
 * int memcmp( const void *buf1, const void *buf2, size_t count );
 *
 * ��׼�涨ͬ strcmp
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

// �ִ� memcmp���ԣ��ɲο� strncmp��

/*
 * 4.memset
 * Sets buffers to a specified character.
 *
 * ����
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
//     // ���Թ۲�
//     return 0;
// }