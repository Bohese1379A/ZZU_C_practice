/*
实验六 8: 求100至999之间的最大的三个素数。
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
