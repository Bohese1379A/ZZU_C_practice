/*
实验九 11: 用递归方法求Fibonacci数列前20项以及这20项的和。
*/
#include <stdio.h>

long long fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

long long sum_fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return sum_fibonacci(n - 1) + fibonacci(n);
}

int main(void)
{
    int n = 20;
    long long sum = 0;
    
    printf("斐波那契数列前20项：\n");
    for (int i = 1; i <= n; i++)
    {
        long long term = fibonacci(i);
        printf("%lld ", term);
        sum += term;
    }
    printf("\n");
    
    printf("前20项的和: %lld\n", sum);
    
    return 0;
}
