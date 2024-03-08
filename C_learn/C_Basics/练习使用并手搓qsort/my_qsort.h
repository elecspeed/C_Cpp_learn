#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void quicksort_int(int* arr, int sz);

void my_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

void test1();	//qsort排序int数组

void test2();	//qsort排序结构体数组

void test3();	//quicksort_int排序int数组

void test4();	//my_qsort排序结构体数组

