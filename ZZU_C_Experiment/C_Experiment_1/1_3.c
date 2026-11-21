/*
 * 实验一 3: 输入5个数，求这5个数的平方后的和。
 *
 * 知识点：定次循环、平方和、累加器。
 * 解题思路：每读一个数就计算平方并累加，一次只需存下当前读到的数。
 * 代码逻辑：循环五次，逐次检查输入、更新 sum，最后输出平方和。
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
