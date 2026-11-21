/*
实验四 5: 求方程 ax^2+bx+c=0 的根，考虑判别式及 a=0 的情况，可能为实根或复根。
*/
#include <stdio.h>
#include "../common/lab_input.h"
#include <math.h>

int main(void)
{
    double a, b, c;
    if (lab_read_double(&a) && lab_read_double(&b) && lab_read_double(&c))
    {
        if (a == 0)
        {
            puts("Not a quadratic equation");
            if (b != 0)
                printf("one root: %.6f\n", -c / b);
            else
                printf("Not an equation or infinite solutions\n");
        }
        else
        {
            double D = b * b - 4 * a * c;
            if (!isfinite(D))
            {
                fputs("Discriminant is out of range\n", stderr);
                return 1;
            }
            if (D > 0)
                printf("x1=%.6f x2=%.6f\n", (-b + sqrt(D)) / (2 * a), (-b - sqrt(D)) / (2 * a));
            else if (D == 0)
                printf("x=%.6f\n", -b / (2 * a));
            else
            {
                double real = -b / (2 * a);
                double imaginary = fabs(sqrt(-D) / (2 * a));
                printf("complex roots: %.6f+%.6fi and %.6f-%.6fi\n", real, imaginary, real, imaginary);
            }
        }
    }
    else
    {
        fputs("Input error: expected three finite coefficients\n", stderr);
        return 1;
    }
    return 0;
}
