/*
 * 实验五 1: 计算 s = sum_{n=1}^{100} n
 *
 * 知识点：for 循环、求和、循环边界。
 * 解题思路：让 n 从 1 遍历到 100，每取一项就加到累加器。
 * 代码逻辑：s 从零开始，处理完第 100 项后输出总和。
 */
#include <stdio.h>

int main(void)
{
    long s = 0;
    for (int n = 1; n <= 100; n++)
        s += n;
    printf("%ld\n", s);
    return 0;
}
