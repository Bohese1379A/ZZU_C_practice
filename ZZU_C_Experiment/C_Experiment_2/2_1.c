/*
 * 实验二 1: 求多项式 ax^3 + bx^2 + c 的值（a=2,b=3,c=4,x=1.414）。
 *
 * 知识点：算术表达式、浮点数、乘法优先级。
 * 解题思路：把多项式中的平方和立方写成连续乘法，再合并各项。
 * 代码逻辑：给 a、b、c、x 赋题设数值，计算 y 并按六位小数输出。
 */
#include <stdio.h>

int main(void)
{
    double a = 2, b = 3, c = 4, x = 1.414;
    double y = a * x * x * x + b * x * x + c;
    printf("%.6f\n", y);
    return 0;
}
