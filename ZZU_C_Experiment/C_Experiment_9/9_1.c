/* 实验九 1：计算组合数 C(n,m) = n! / (m! * (n-m)!)。 */
#include <stdio.h>
#include "../common/lab_input.h"

static unsigned long long factorial(int n)
{
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= (unsigned)i;
    return result;
}

int main(void)
{
    int n, m;
    printf("请输入 n 和 m：");
    /* 20! 仍可存入 64 位整数，因此可以直接练习阶乘公式。 */
    if (!lab_read_int(&n) || !lab_read_int(&m) || m < 0 || n < m || n > 20) {
        fputs("输入错误：需要满足 0 <= m <= n <= 20。\n", stderr);
        return 1;
    }
    unsigned long long combination = factorial(n) / (factorial(m) * factorial(n - m));
    printf("C(%d,%d) = %llu\n", n, m, combination);
    return 0;
}
