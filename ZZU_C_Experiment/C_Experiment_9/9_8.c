/*
实验九 8: 编写一个函数过程，解一元二次方程 ax^2 + bx + c = 0。
*/
#include <stdio.h>
#include "../common/lab_input.h"
#include <math.h>

// 返回值：0表示无实根，1表示一个实根，2表示两个实根
int solve_quadratic(double a, double b, double c, double *x1, double *x2)
{
    if (a == 0)
    {
        if (b == 0)
            return 0; // 不是方程
        *x1 = -c / b;
        *x2 = *x1;
        return 1; // 一次方程
    }

    double discriminant = b * b - 4 * a * c;

    if (!isfinite(discriminant))
        return -1;
    if (discriminant < 0)
        return 0; // 无实根
    else if (discriminant == 0)
    {
        *x1 = -b / (2 * a);
        *x2 = *x1;
        return 1; // 一个实根
    }
    else
    {
        double sqrt_d = sqrt(discriminant);
        *x1 = (-b + sqrt_d) / (2 * a);
        *x2 = (-b - sqrt_d) / (2 * a);
        return 2; // 两个实根
    }
}

int main(void)
{
    double a, b, c, x1, x2;
    printf("请输入a, b, c: ");
    if (!lab_read_double(&a) || !lab_read_double(&b) || !lab_read_double(&c))
    {
        fputs("输入错误：需要三个有限的数。\n", stderr);
        return 1;
    }

    int result = solve_quadratic(a, b, c, &x1, &x2);

    switch (result)
    {
        case -1:
            fputs("判别式超出可计算范围。\n", stderr);
            return 1;
        case 0:
            printf("无实根\n");
            break;
        case 1:
            printf("一个实根: x = %.6f\n", x1);
            break;
        case 2:
            printf("两个实根: x1 = %.6f, x2 = %.6f\n", x1, x2);
            break;
    }

    return 0;
}
