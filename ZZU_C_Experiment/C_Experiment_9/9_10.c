/*
实验九 10: 编写函数程序，计算正整数 n1 到 n2之间所有素数之和。
*/
#include <stdio.h>
#include "../common/lab_input.h"

int is_prime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i <= n / i; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

long long sum_primes(int n1, int n2)
{
    long long sum = 0;
    for (int i = n1; ; ++i)
    {
        if (is_prime(i))
            sum += i;
        if (i == n2)
            break;
    }
    return sum;
}

int main(void)
{
    int n1, n2;
    printf("请输入n1和n2: ");
    if (!lab_read_int(&n1) || !lab_read_int(&n2) || n1 < 1 || n2 < 1)
    {
        fputs("输入错误：需要两个正整数。\n", stderr);
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
