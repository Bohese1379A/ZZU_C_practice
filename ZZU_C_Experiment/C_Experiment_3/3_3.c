/*
实验三 3：用一次 scanf 读入三个整数，计算 a+b+c 和 a-b-c。
*/
#include <stdio.h>

int main(void)
{
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) == 3)
    {
        printf("x1=a+b+c= %d+ %d+ %d= %d\n", a, b, c, a + b + c);
        printf("x2=a-b-c= %d- %d- %d= %d\n", a, b, c, a - b - c);
    }
    else
    {
        fprintf(stderr, "Input error: expected three integers\n");
        return 1;
    }
    return 0;
}
