/*
qsort声明
void qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
stdlib库
*/

//从qsort的声明看出，qsort可以排序任一数据类型
//但需要提供四个参数
//四个参数分别表示：排序首地址，排序个数，单个元素长度，两个元素间的比较方法
//其中，比较方法用回调函数实现
//思想：这四个参数是排序的核心要素，即只有知道这四个要素，才能进行排序
