/*
实验四 5: 求方程 ax^2+bx+c=0 的根，考虑判别式及 a=0 的情况，可能为实根或复根。
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        if (a == 0)
        {
            if (b != 0)
                printf("one root: %.6f\n", -c / b);
            else
                printf("Not an equation or infinite solutions\n");
        }
        else
        {
            double D = b * b - 4 * a * c;
            if (D > 0)
                printf("x1=%.6f x2=%.6f\n", (-b + sqrt(D)) / (2 * a), (-b - sqrt(D)) / (2 * a));
            else if (D == 0)
                printf("x=%.6f\n", -b / (2 * a));
            else
                printf("complex roots: %.6f+%.6fi and %.6f-%.6fi\n", -b / (2 * a), sqrt(-D) / (2 * a), -b / (2 * a), sqrt(-D) / (2 * a));
        }
    }
    return 0;
}
