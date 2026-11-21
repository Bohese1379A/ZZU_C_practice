/* 实验二 2：输入两个整数，计算积、商和余数。 */
#include <stdio.h>
#include "../common/lab_input.h"

int main(void)
{
    int first, second;
    if (!lab_read_int(&first) || !lab_read_int(&second)) {
        fputs("Input error: expected two integers\n", stderr);
        return 1;
    }

    long long a = first, b = second;
    printf("prod=%lld\n", a * b);
    if (b == 0)
        puts("division by zero");
    else
        printf("quot=%lld remainder=%lld\n", a / b, a % b);
    return 0;
}
