/*
 * 实验五 2: 计算 sum = sum_{n=1}^{10} n! 并输出。
 *
 * 知识点：循环、阶乘递推、累加。
 * 解题思路：用 n! = (n-1)! * n 复用上一次的阶乘，避免从头计算。
 * 代码逻辑：每轮先更新 fact 得到 n!，再把 fact 加入 sum。
 */
#include <stdio.h>

int main(void)
{
    long sum = 0;
    long fact = 1;
    for (int n = 1; n <= 10; n++)
    {
        fact *= n; // 上一轮的 (n-1)! 乘 n 就是当前阶乘。
        sum += fact;
    }
    printf("%ld\n", sum);
    return 0;
}
