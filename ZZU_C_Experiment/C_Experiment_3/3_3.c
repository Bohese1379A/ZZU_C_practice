/*
 * 实验三 3：用一次 scanf 读入 a、b、c，按题设格式输出和与差。
 *
 * 知识点：多项 scanf 输入、表达式与占位符对应。
 * 解题思路：用一次 scanf 拿到 a、b、c，再分别求和、求差。
 * 代码逻辑：确认读到三项，用 long long 完成计算，并把操作数和结果一起打印。
 */
#include <stdio.h>

int main(void)
{
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) == 3)
    {
        printf("x1=a+b+c= %d+ %d+ %d= %lld\n", a, b, c, (long long)a + b + c);
        printf("x2=a-b-c= %d- %d- %d= %lld\n", a, b, c, (long long)a - b - c);
    }
    else
    {
        fprintf(stderr, "Input error: expected three integers\n");
        return 1;
    }
    return 0;
}
