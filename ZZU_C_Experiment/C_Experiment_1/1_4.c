/*
 * 实验一 4：输入三个数，求这三个数的平方根之和。
 *
 * 知识点：math.h、sqrt 的定义域、逻辑或。
 * 解题思路：每个数先独立开平方，再把三个平方根相加。
 * 代码逻辑：读入三个数，排除负数后调用三次 sqrt，并按六位小数输出。
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        if (a < 0 || b < 0 || c < 0)
        {
            fprintf(stderr, "Invalid input: negative value for sqrt\n");
            return 1;
        }
        printf("%.6f\n", sqrt(a) + sqrt(b) + sqrt(c));
    }
    else
    {
        fprintf(stderr, "Input error: expected three numbers\n");
        return 1;
    }
    return 0;
}
