/*
 * 实验六 3(3): 星号和加号交替的三角形。
 *
 * 知识点：嵌套循环、余数、条件运算符。
 * 解题思路：每行有奇数个字符，用列下标的奇偶性交替选择星号和加号。
 * 代码逻辑：先补前导空格，再输出 2*row+1 个字符，最后换行。
 */
#include <stdio.h>

int main(void)
{
    const int rows = 4;
    for (int row = 0; row < rows; ++row)
    {
        for (int column = row + 1; column < rows; ++column)
            putchar(' ');
        for (int column = 0; column < 2 * row + 1; ++column)
            putchar(column % 2 == 0 ? '*' : '+'); // 奇偶列交替，首尾都是星号。
        putchar('\n');
    }
    return 0;
}
