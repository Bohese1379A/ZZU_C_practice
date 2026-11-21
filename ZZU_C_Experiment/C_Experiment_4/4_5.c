/*
 * 实验四 5: 求方程 ax^2+bx+c=0 的根，考虑判别式及 a=0 的情况，可能为实根或复根。
 *
 * 知识点：判别式、sqrt、实根与共轭复根。
 * 解题思路：先处理 a=0 的退化情形，再用 b*b-4*a*c 判断根的类型。
 * 代码逻辑：按判别式的符号分别计算两个实根、重根或复根的实部和虚部。
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
            double D = b * b - 4 * a * c; // 先算判别式，按它的符号决定根的类型。
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
