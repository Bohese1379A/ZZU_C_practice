/*
实验九 7: 编写函数过程，求两个正整数的最大公约数和最小公倍数。
*/
#include <stdio.h>
#include "../common/lab_input.h"

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(int a, int b)
{
    return (long long)(a / gcd(a, b)) * b;
}

int main(void)
{
    int a, b;
    printf("请输入两个正整数: ");
    if (!lab_read_int(&a) || !lab_read_int(&b) || a <= 0 || b <= 0)
    {
        printf("错误：请输入正整数\n");
        return 1;
    }

    int greatest_common_divisor = gcd(a, b);
    long long least_common_multiple = lcm(a, b);

    printf("最大公约数: %d\n", greatest_common_divisor);
    printf("最小公倍数: %lld\n", least_common_multiple);

    return 0;
}
