/*
 * 实验九 10：编写函数，求正整数 n1 到 n2 范围内所有素数之和。
 *
 * 知识点：素数试除、闭区间遍历、扩大循环变量。
 * 解题思路：先让两端有序，再逐个判素并求和；从奇数因子试除到平方根。
 * 代码逻辑：校验正整数端点，通过 sum_primes 求闭区间内各素数的和。
 */
#include <stdio.h>

int is_prime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i <= n / i; i += 2) // 等价于 i*i <= n，并避免乘法溢出。
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

long long sum_primes(int n1, int n2)
{
    long long sum = 0;
    for (long long i = n1; i <= n2; i++)
    {
        if (is_prime((int)i))
            sum += i;
    }
    return sum;
}

int main(void)
{
    int n1, n2;
    printf("请输入n1和n2: ");
    if (scanf("%d %d", &n1, &n2) != 2 || n1 < 1 || n2 < 1)
    {
        fputs("请输入两个正整数。\n", stderr);
        return 1;
    }
    
    if (n1 > n2)
    {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    
    long long result = sum_primes(n1, n2);
    printf("%d到%d之间所有素数之和: %lld\n", n1, n2, result);
    
    return 0;
}
