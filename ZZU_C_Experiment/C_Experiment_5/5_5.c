/*
实验五 5: 求出 Fibonacci 数列的前20项并输出。
*/
#include <stdio.h>

int main(void)
{
    long a = 1, b = 1;
    printf("1 1 ");
    for (int i = 3; i <= 20; i++)
    {
        long c = a + b;
        printf("%ld ", c);
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}
