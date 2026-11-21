/*
 * 实验六 3(1): 数字回文三角形。
 *
 * 知识点：嵌套循环、居中排列、对称输出。
 * 解题思路：每行由前导空格、递增数字和递减数字三段组成。
 * 代码逻辑：外层控制四行，内层从 1 递增到行号，再从前一位递减到 1。
 */
#include <stdio.h>

int main(void)
{
    const int rows = 4;
    for (int row = 1; row <= rows; ++row)
    {
        for (int column = row; column < rows; ++column)
            putchar(' ');
        for (int digit = 1; digit <= row; ++digit)
            printf("%d", digit);
        for (int digit = row - 1; digit >= 1; --digit)
            printf("%d", digit); // 从峰值的前一位开始，峰值只输出一次。
        putchar('\n');
    }
    return 0;
}
