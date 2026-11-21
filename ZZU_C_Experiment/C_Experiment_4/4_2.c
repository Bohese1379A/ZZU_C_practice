/*
 * 实验四 2：求分段函数 y；x<1 时 y=x，1<=x<10 时 y=2x-1，其余 y=3x-11。
 *
 * 知识点：分段函数、if/else if/else。
 * 解题思路：按边界从小到大检查，让每个 x 只进入一个区间。
 * 代码逻辑：先判断 x<1，其次判断 x<10，其余输入按第三段公式求值。
 */
#include <stdio.h>

int main(void)
{
    double x;
    if (scanf("%lf", &x) == 1)
    {
        double y;
        if (x < 1)
            y = x;
        else if (x < 10) // 走到这里时 x 已经大于或等于 1。
            y = 2 * x - 1;
        else
            y = 3 * x - 11;
        printf("%.6f\n", y);
    }
    else
    {
        fprintf(stderr, "Input error: expected a number\n");
        return 1;
    }
    return 0;
}
