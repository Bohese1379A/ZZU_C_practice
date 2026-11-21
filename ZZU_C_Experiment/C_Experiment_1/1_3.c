/*
实验一 3: 输入5个数，求这5个数的平方后的和。
*/
#include <stdio.h>
#include "../common/lab_input.h"

int main(void)
{
    double x, sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (!lab_read_double(&x))
        {
            fputs("Input error: expected five numbers\n", stderr);
            return 1;
        }
        sum += x * x;
    }
    printf("%.6f\n", sum);
    return 0;
}
