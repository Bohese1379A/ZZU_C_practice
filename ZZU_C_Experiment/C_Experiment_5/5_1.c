/*
实验五 1: 计算 s = sum_{n=1}^{100} n
*/
#include <stdio.h>

int main(void)
{
    long s = 0;
    for (int n = 1; n <= 100; n++)
        s += n;
    printf("%ld\n", s);
    return 0;
}
