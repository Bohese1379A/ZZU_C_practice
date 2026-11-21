/*
 * 实验三 2: 使用6个 scanf 完成输入并按格式输出。
 *
 * 知识点：scanf 返回值、短路求值、格式匹配。
 * 解题思路：按题意分别读取三个整数和三个 double，每读一项就确认转换成功。
 * 代码逻辑：串接六次 scanf，全部成功时按整数与小数分两行输出。
 */
#include <stdio.h>

int main(void)
{
    int a, b, c;
    double x, y, z;
    // 每次转换的返回值都是 1，才说明六个变量都已读入。
    if (scanf("%d", &a) == 1 && scanf("%d", &b) == 1 && scanf("%d", &c) == 1 &&
        scanf("%lf", &x) == 1 && scanf("%lf", &y) == 1 && scanf("%lf", &z) == 1)
    {
        printf("a=%d b=%d c=%d\n", a, b, c);
        printf("x=%.3f y=%.3f z=%.3f\n", x, y, z);
    }
    else
    {
        fprintf(stderr, "Input error: expected 6 values (3 ints and 3 floats)\n");
        return 1;
    }
    return 0;
}
