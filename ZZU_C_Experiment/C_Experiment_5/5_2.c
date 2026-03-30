/*
实验五 2: 计算 sum = sum_{n=1}^{10} n! 并输出。
*/
#include <stdio.h>

int main(void)
{
    long sum = 0;
    long fact = 1;
    for (int n = 1; n <= 10; n++)
    {
        fact *= n;
        sum += fact;
    }
    printf("%ld\n", sum);
    return 0;
}
