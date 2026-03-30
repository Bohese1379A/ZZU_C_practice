/*
实验六 1: 使用双循环计算 s = sum_{n=1}^{10} n!（等同于实验五第2题，但用双循环示例）。
*/
#include <stdio.h>

int main(void)
{
    long sum = 0;
    for (int n = 1; n <= 10; n++)
    {
        long fact = 1;
        for (int k = 1; k <= n; k++)
            fact *= k;
        sum += fact;
    }
    printf("%ld\n", sum);
    return 0;
}
