/*
 * 实验一 2: 编程且上机运行：求2个数的和、差、积和商。
 *
 * 知识点：double、四则运算、分支判断。
 * 解题思路：和、差、积可以直接计算，商需要先判断除数。
 * 代码逻辑：用 %lf 读两个数并依次输出各项，除数为零时输出提示。
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
        if (b != 0) // 先排除零除数，再求商。
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
