/* 实验六 3(3)：用循环输出星号与加号交替的四行三角形。 */
#include <stdio.h>

int main(void)
{
    const int rows = 4;
    for (int row = 0; row < rows; ++row) {
        for (int space = row + 1; space < rows; ++space)
            putchar(' ');
        for (int col = 0; col < 2 * row + 1; ++col)
            putchar(col % 2 ? '+' : '*');
        putchar('\n');
    }
    return 0;
}
