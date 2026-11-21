/*
 * 实验九 11: 用递归方法求Fibonacci数列前20项以及这20项的和。
 *
 * 知识点：递归、递归出口、斐波那契关系。
 * 解题思路：保留递归练习方法，将第 n 项拆成前两项之和，以初始项作为出口。
 * 代码逻辑：逐项调用递归函数输出前 20 项，同时累加每次获得的结果。
 */
#include <stdio.h>

long long fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2); // 将当前问题拆成两个规模更小的同类问题。
}

int main(void)
{
    int n = 20;
    long long sum = 0;
    
    printf("斐波那契数列前20项：\n");
    for (int i = 1; i <= n; i++)
    {
        long long term = fibonacci(i);
        printf("%lld ", term);
        sum += term;
    }
    printf("\n");
    
    printf("前20项的和: %lld\n", sum);
    
    return 0;
}
