/*
实验一 3: 输入5个数，求这5个数的平方后的和。
*/
#include <stdio.h>

int main(void)
{
    double x, sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (scanf("%lf", &x) != 1)
        {
            printf("Please input 5 numbers\n");
            return 0;
        }
        sum += x * x;
    }
    printf("%.6f\n", sum);
    return 0;
}
