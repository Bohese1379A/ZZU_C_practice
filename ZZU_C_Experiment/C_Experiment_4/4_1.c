/*
 * 实验四 1：输入三个整数 a、b、c，输出其中最大者。
 *
 * 知识点：比较运算、if、最大值维护。
 * 解题思路：把第一个数当作当前最大值，仅在遇到更大的数时更新。
 * 代码逻辑：读入 a、b、c，依次拿 b、c 与当前最大值比较，再输出结果。
 */
#include <stdio.h>

int main(void)
{
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) == 3)
    {
        int m = a;
        if (b > m)
            m = b;
        if (c > m)
            m = c;
        printf("%d\n", m);
    }
    else
    {
        fprintf(stderr, "Input error: expected three integers\n");
        return 1;
    }
    return 0;
}
