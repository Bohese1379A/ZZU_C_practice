/*
实验九 7: 编写函数过程，求两个正整数的最大公约数和最小公倍数。
*/
#include <stdio.h>

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

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main(void)
{
    int a, b;
    printf("请输入两个正整数: ");
    scanf("%d %d", &a, &b);
    
    if (a <= 0 || b <= 0)
    {
        printf("错误：请输入正整数\n");
        return 1;
    }
    
    int greatest_common_divisor = gcd(a, b);
    int least_common_multiple = lcm(a, b);
    
    printf("最大公约数: %d\n", greatest_common_divisor);
    printf("最小公倍数: %d\n", least_common_multiple);
    
    return 0;
}
