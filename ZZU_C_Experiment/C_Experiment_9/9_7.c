/*
 * 实验九 7: 编写函数过程，求两个正整数的最大公约数和最小公倍数。
 *
 * 知识点：欧几里得算法、余数、最小公倍数。
 * 解题思路：反复用余数替换除数得到最大公约数，再根据公倍数关系计算。
 * 代码逻辑：校验两个正整数；先除公约数再做乘法，用 long long 保存最小公倍数。
 */
#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b; // gcd(a,b) 等于 gcd(b,a%b)，用余数缩小下一轮范围。
        a = temp;
    }
    return a;
}

long long lcm(int a, int b)
{
    return (long long)(a / gcd(a, b)) * b; // 先除公约数，再用更宽的类型做乘法。
}

int main(void)
{
    int a, b;
    printf("请输入两个正整数: ");
    if (scanf("%d %d", &a, &b) != 2 || a <= 0 || b <= 0)
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
