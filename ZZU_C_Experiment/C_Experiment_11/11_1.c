/*
实验十一 1: 用指针变量按从小到大的顺序输出三个整数。
*/
#include <stdio.h>
#include "../common/lab_input.h"

void sort_three(int *a, int *b, int *c)
{
    if (*a > *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c)
    {
        int temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c)
    {
        int temp = *b;
        *b = *c;
        *c = temp;
    }
}

int main(void)
{
    int x, y, z;
    printf("请输入三个整数: ");
    if (!lab_read_int(&x) || !lab_read_int(&y) || !lab_read_int(&z))
    {
        fputs("输入错误：需要三个整数。\n", stderr);
        return 1;
    }

    sort_three(&x, &y, &z);

    printf("从小到大排序: %d %d %d\n", x, y, z);

    return 0;
}
