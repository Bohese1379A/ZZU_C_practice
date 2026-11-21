/*
 * 实验六 1: 使用双循环计算 s = sum_{n=1}^{10} n!（等同于实验五第2题，但用双循环示例）。
 *
 * 知识点：嵌套循环、阶乘、内层变量初始化。
 * 解题思路：外层选择阶乘的阶数，内层从 1 开始计算该阶乘。
 * 代码逻辑：每轮重设 fact，算出 n! 后加入总和，最后输出结果。
 */
#include <stdio.h>

int main(void)
{
    long sum = 0;
    for (int n = 1; n <= 10; n++)
    {
        long fact = 1;
        for (int k = 1; k <= n; k++)
            fact *= k;
        sum += fact;
    }
    printf("%ld\n", sum);
    return 0;
}
