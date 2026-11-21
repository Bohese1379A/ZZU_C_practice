/*
 * 实验九 2: 编写函数过程，计算1! + 2! + 3! + … + 10!
 *
 * 知识点：函数调用、阶乘和、循环累加。
 * 解题思路：将单个阶乘和阶乘序列求和分给两个函数。
 * 代码逻辑：对 1 到 10 逐次调用 factorial，把各返回值相加后输出。
 */
#include <stdio.h>

long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

long long sum_factorials(int n)
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += factorial(i);
    }
    return sum;
}

int main(void)
{
    long long result = sum_factorials(10);
    printf("1! + 2! + 3! + ... + 10! = %lld\n", result);
    
    return 0;
}
