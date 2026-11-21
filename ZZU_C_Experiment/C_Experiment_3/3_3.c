/*
实验三 3：用一次 scanf 读入三个整数，计算 a+b+c 和 a-b-c。
*/
#include <stdio.h>
#include "../common/lab_input.h"

int main(void)
{
    char first[64], second[64], third[64];
    int a, b, c;
    if (scanf("%63s %63s %63s", first, second, third) == 3 &&
        lab_parse_int(first, &a) && lab_parse_int(second, &b) && lab_parse_int(third, &c))
    {
        printf("x1=a+b+c=%d+%d+%d=%lld\n", a, b, c, (long long)a + b + c);
        printf("x2=a-b-c=%d-%d-%d=%lld\n", a, b, c, (long long)a - b - c);
    }
    else
    {
        fprintf(stderr, "Input error: expected three integers\n");
        return 1;
    }
    return 0;
}
