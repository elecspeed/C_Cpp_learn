#include <stdio.h>

/*
 * 练习1_1:
 * 写一个测试程序，测试当前编译器是否允许嵌套注释
 */
int is_nest_comment()
{
    // 返回 0 说明不允许，返回非 0 说明允许

    if (/*/*/ 0 * /**/ 1 == 1)
        return 1;
    else if (/*/*/ 0 * /**/ 1 == 0)
        return 0;
}
int main()
{
    int ret = is_nest_comment();

    if (ret == 0)
        printf("No\n");
    else
        printf("Yes\n");

    return 0;
}