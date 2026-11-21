/*
 * 实验一 1: 编程且上机运行：求3个整数的和。
 *
 * 知识点：整数输入、类型转换、格式化输出。
 * 解题思路：三个整数相加时，用更宽的类型保存中间结果和总和。
 * 代码逻辑：确认已经读到三个数，再将第一个操作数提升为 long long 并输出总和。
 */
#include <stdio.h>

int main(void)
{
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) == 3)
    {
        printf("%lld\n", (long long)a + b + c); // 先提升第一个操作数，再做两次加法。
    }
    else
    {
        fprintf(stderr, "Input error: expected three integers\n");
        return 1;
    }
    return 0;
}
