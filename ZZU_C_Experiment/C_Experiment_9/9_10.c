/*
实验九 10: 编写函数程序，计算正整数n1?n2之间所有素数之和。
*/
#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

long long sum_primes(int n1, int n2)
{
    long long sum = 0;
    for (int i = n1; i <= n2; i++)
    {
        if (is_prime(i))
            sum += i;
    }
    return sum;
}

int main(void)
{
    int n1, n2;
    printf("请输入n1和n2: ");
    scanf("%d %d", &n1, &n2);
    
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
