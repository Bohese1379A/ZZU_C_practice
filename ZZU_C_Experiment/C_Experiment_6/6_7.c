/*
 * 实验六 5：求 s=1+(1+2)+(1+2+3)+... 的前 100 项和。
 *
 * 知识点：累计和、递推、循环初值。
 * 解题思路：第 n 项是在上一项基础上加 n，再把它计入总和。
 * 代码逻辑：本例按前 100 项计算，每轮先更新 term，再更新 s。
 */
#include <stdio.h>

int main(void)
{
    long s = 0;
    long term = 0;
    for (int n = 1; n <= 100; n++) // 计算前100项的和
    {
        term += n;
        s += term;
    }
    printf("%ld\n", s);
    return 0;
}
