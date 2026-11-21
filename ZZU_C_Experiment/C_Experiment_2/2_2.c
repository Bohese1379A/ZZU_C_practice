/*
 * 实验二 2：输入两个整数，分别求它们的积、商和余数。
 *
 * 知识点：long、整数除法、取余。
 * 解题思路：在 long 可表示的范围内计算乘积，并在除数非零时成对求商和余数。
 * 代码逻辑：读入 a、b，输出乘积，根据 b 是否为零输出结果或提示。
 */
#include <stdio.h>

int main(void)
{
    long a, b;
    if (scanf("%ld %ld", &a, &b) == 2)
    {
        printf("prod=%ld\n", a * b);
        if (b != 0)
        {
            printf("quot=%ld remainder=%ld\n", a / b, a % b);
        }
        else
            printf("division by zero\n");
    }
    else
    {
        fprintf(stderr, "Input error: expected two integers\n");
        return 1;
    }
    return 0;
}
