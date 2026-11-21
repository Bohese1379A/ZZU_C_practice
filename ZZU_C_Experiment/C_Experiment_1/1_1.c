/*
实验一 1: 编程且上机运行：求3个整数的和。
*/
#include <stdio.h>
#include "../common/lab_input.h"

int main(void)
{
    int a, b, c;
    if (lab_read_int(&a) && lab_read_int(&b) && lab_read_int(&c))
    {
        printf("%lld\n", (long long)a + b + c);
    }
    else
    {
        fprintf(stderr, "Input error: expected three integers\n");
        return 1;
    }
    return 0;
}
