/*
实验六 5: 求 s=1+(1+2)+(1+2+3)+? 的结果。
*/
#include <stdio.h>

int main(void)
{
    long s = 0;
    long term = 0;
    for (int n = 1; n <= 100; n++) // 计算前100项的和
    {
        term += n;
        s += term;
    }
    printf("%ld\n", s);
    return 0;
}
