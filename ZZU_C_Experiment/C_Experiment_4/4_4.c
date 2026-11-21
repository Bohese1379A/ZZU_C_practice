/* 实验四 4：显示正整数的位数、各位数字及其逆序。 */
#include <stdio.h>
#include <string.h>
#include "../common/lab_input.h"

int main(void)
{
    char digits[6];
    if (!lab_read_token(digits, sizeof digits) || digits[0] == '0' ||
        digits[strspn(digits, "0123456789")] != '\0') {
        fputs("Input error: expected a positive integer with at most five digits\n", stderr);
        return 1;
    }

    size_t length = strlen(digits);
    printf("digits=%zu\n", length);
    for (size_t i = 0; i < length; ++i)
        printf("%s%c", i == 0 ? "" : " ", digits[i]);
    putchar('\n');
    for (size_t i = length; i > 0; --i)
        putchar(digits[i - 1]);
    putchar('\n');
    return 0;
}
