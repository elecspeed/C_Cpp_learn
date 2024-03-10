#include <stdio.h>

/*
 * 探究数组越界访问
 */
// int main()
// {
//     int i, a[10];
//     for (i = -1; i < 10; ++i)
//     {
//         a[i] = i;
//         printf("%d ", i);
//     }
//     return 0;
// }

/*
 * 二分查找函数
 */
#include <assert.h>
int *Binary_search_int(int *numsArray, int nums, int aid)
{
    assert(numsArray != NULL);

    // 递归实现
    // int mid = nums / 2;
    // while (mid >= 0 && nums > 0)
    // {
    //     if (numsArray[mid] < aid)
    //         return Binary_search_int(numsArray + mid + 1, nums - mid - 1, aid);
    //     else if (numsArray[mid] > aid)
    //         return Binary_search_int(numsArray, mid, aid);
    //     else
    //         return &numsArray[mid];
    // }

    // 循环实现
    int left, right, mid; // 三个下标
    left = 0;
    right = nums - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (numsArray[mid] < aid)
            left = mid + 1;
        else if (numsArray[mid] > aid)
            right = mid - 1;
        else
            return &numsArray[mid];
    }

    return NULL;
}
#define N 3
int main()
{
    int arr[N];
    int i = 0;
    for (i = 0; i < N; ++i)
    {
        arr[i] = i;
    }

    int *ptr_to_find = Binary_search_int(arr, N, N - 1);

    if (ptr_to_find == NULL)
        printf("No find\n");
    else
        printf("The position is %d\n", ptr_to_find - arr);

    return 0;
}
