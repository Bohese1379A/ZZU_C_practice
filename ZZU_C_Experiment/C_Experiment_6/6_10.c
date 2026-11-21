/*
 * 实验六 8: 求100至999之间的最大的三个素数。
 *
 * 知识点：素数、奇偶性、试除上界。
 * 解题思路：从 999 向下找；检查一个数时，排除偶数，再试到平方根。
 * 代码逻辑：is_prime 负责素数判断，主循环找到前三个即停止并输出。
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
    for (int i = 3; i <= n / i; i += 2) // 因数成对出现，试除到平方根即可。
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main(void)
{
    int primes[3] = {0};
    int count = 0;
    
    for (int n = 999; n >= 100 && count < 3; n--)
    {
        if (is_prime(n))
        {
            primes[count] = n;
            count++;
        }
    }
    
    printf("100-999之间的最大三个素数：%d, %d, %d\n", primes[0], primes[1], primes[2]);
    return 0;
}
