/*
实验一 1: 编程且上机运行：求3个整数的和。
*/
#include <stdio.h>

int main(void)
{
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) == 3)
    {
        printf("%d\n", a + b + c);
    }
    else
    {
        fprintf(stderr, "Input error: expected three integers\n");
        return 1;
    }
    return 0;
}
