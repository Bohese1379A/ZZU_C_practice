/*
实验二 1: 求多项式 ax^3 + bx^2 + c 的值（a=2,b=3,c=4,x=1.414）。
*/
#include <stdio.h>

int main(void)
{
    double a = 2, b = 3, c = 4, x = 1.414;
    double y = a * x * x * x + b * x * x + c;
    printf("%.6f\n", y);
    return 0;
}
