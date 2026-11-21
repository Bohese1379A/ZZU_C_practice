/*
 * 实验五 5: 求出 Fibonacci 数列的前20项并输出。
 *
 * 知识点：递推关系、滚动变量、定次循环。
 * 解题思路：只保存相邻两项即可计算下一项。
 * 代码逻辑：输出两个初始的 1，循环产生第 3 到第 20 项，并在每轮后更新相邻两项。
 */
#include <stdio.h>

int main(void)
{
    long a = 1, b = 1;
    printf("1 1 ");
    for (int i = 3; i <= 20; i++)
    {
        long c = a + b;
        printf("%ld ", c);
        a = b; // 旧的第二项成为下一轮的第一项。
        b = c;
    }
    printf("\n");
    return 0;
}
