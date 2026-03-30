/*
实验一 2: 编程且上机运行：求2个数的和、差、积和商。
*/
#include <stdio.h>

int main(void)
{
    double a, b;
    if (scanf("%lf %lf", &a, &b) == 2)
    {
        printf("sum=%.6g\n", a + b);
        printf("diff=%.6g\n", a - b);
        printf("prod=%.6g\n", a * b);
        if (b != 0)
            printf("quot=%.6g\n", a / b);
        else
            printf("quot=undefined (divide by zero)\n");
    }
    else
    {
        fprintf(stderr, "Input error: expected two numbers\n");
        return 1;
    }
    return 0;
}
