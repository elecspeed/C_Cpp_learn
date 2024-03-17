## 章节

> 1. 词法“陷阱”
> 2. 语法“陷阱”
> 3. 语义“陷阱”
> 4. 链接
> 5. ***库函数***
> 6. 预处理
> 7. 可移植性
> 8. 建议
> 9. 附录

---

#### 5.1 返回 int 的 getchar

看代码：

```C
#include <stdio.h>
int main()
{
    char ch;
    while((ch = getchar()) != EOF)
        putchar(ch);
    return 0;
}
```

这个程序乍一看似乎是把标准输入复制到标准输出，实则不然。
