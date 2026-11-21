/*
 * 实验六 3(2): 字母三角形。
 *
 * 知识点：字符数组、行列循环、奇数列数。
 * 解题思路：每行选一个字母，并按 1、3、5、7 的规律增加当行宽度。
 * 代码逻辑：先补前导空格，再用行下标取 A 到 D 中的对应字母循环输出。
 */
#include <stdio.h>

int main(void)
{
    const char letters[] = "ABCD";
    const int rows = 4;
    for (int row = 0; row < rows; ++row)
    {
        for (int column = row + 1; column < rows; ++column)
            putchar(' ');
        for (int column = 0; column < 2 * row + 1; ++column)
            putchar(letters[row]); // 行下标从 0 开始，因此每行分别有 1、3、5、7 个字符。
        putchar('\n');
    }
    return 0;
}
