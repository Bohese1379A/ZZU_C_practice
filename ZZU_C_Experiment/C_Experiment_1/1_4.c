/*
实验一 4：输入三个非负数，计算平方根之和。
*/
#include <stdio.h>
#include "../common/lab_input.h"
#include <math.h>

int main(void)
{
    double a, b, c;
    if (lab_read_double(&a) && lab_read_double(&b) && lab_read_double(&c))
    {
        if (a < 0 || b < 0 || c < 0)
        {
            fprintf(stderr, "Invalid input: negative value for sqrt\n");
            return 1;
        }
        printf("%.6f\n", sqrt(a) + sqrt(b) + sqrt(c));
    }
    else
    {
        fprintf(stderr, "Input error: expected three numbers\n");
        return 1;
    }
    return 0;
}
