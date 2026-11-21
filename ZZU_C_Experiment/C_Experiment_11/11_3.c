/*
实验十一 3: 利用指针完成两个变量值互换。
*/
#include <stdio.h>
#include "../common/lab_input.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int x, y;
    printf("请输入两个整数: ");
    if (!lab_read_int(&x) || !lab_read_int(&y))
    {
        fputs("输入错误：需要两个整数。\n", stderr);
        return 1;
    }

    printf("交换前: x=%d, y=%d\n", x, y);

    swap(&x, &y);

    printf("交换后: x=%d, y=%d\n", x, y);

    return 0;
}
