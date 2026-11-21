/* 实验六 3(2)：用循环输出 A、BBB、CCCCC、DDDDDDD。 */
#include <stdio.h>

int main(void)
{
    const int rows = 4;
    for (int row = 0; row < rows; ++row) {
        for (int space = row + 1; space < rows; ++space)
            putchar(' ');
        for (int col = 0; col < 2 * row + 1; ++col)
            putchar('A' + row);
        putchar('\n');
    }
    return 0;
}
