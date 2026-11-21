/*
 * 实验九 1：利用函数计算组合数 n! / (m! * (n-m)!)。
 *
 * 知识点：函数分解、阶乘、整数可表示范围。
 * 解题思路：用同一个阶乘函数求 n!、m! 和 (n-m)!，再代入组合数公式。
 * 代码逻辑：验证 0<=m<=n<=20，分别计算三个阶乘，完成乘除并打印结果。
 */
#include <stdio.h>

static long long factorial(int n)
{
    long long result = 1; // n 为 0 或 1 时循环不执行，直接得到阶乘 1。
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

int main(void)
{
    int n, m;
    printf("请输入n和m: ");
    // 20! 仍能存入 long long，限制 n 后可直接使用题目的阶乘公式。
    if (scanf("%d %d", &n, &m) != 2 || m < 0 || n < m || n > 20)
    {
        fputs("输入必须满足 0 <= m <= n <= 20。\n", stderr);
        return 1;
    }

    long long result = factorial(n) / (factorial(m) * factorial(n - m));
    printf("C(%d, %d) = %lld\n", n, m, result);
    return 0;
}
