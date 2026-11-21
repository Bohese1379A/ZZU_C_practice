/* 实验六 3(1)：用循环输出四行数字回文三角形。 */
#include <stdio.h>

int main(void)
{
    const int rows = 4;
    for (int row = 1; row <= rows; ++row) {
        for (int space = row; space < rows; ++space)
            putchar(' ');
        for (int digit = 1; digit <= row; ++digit)
            printf("%d", digit);
        for (int digit = row - 1; digit >= 1; --digit)
            printf("%d", digit);
        putchar('\n');
    }
    return 0;
}
