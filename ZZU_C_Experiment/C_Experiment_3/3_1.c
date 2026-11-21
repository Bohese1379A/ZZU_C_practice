/*
 * 实验三 1: 格式化输出给定若干变量，域宽为7位。
 *
 * 知识点：printf 字段宽度、整数和浮点格式。
 * 解题思路：按题面把整数和小数分两行，每个数值至少占七个字符。
 * 代码逻辑：赋好六个变量，第一行用 %7d，第二行用 %7.3f。
 */
#include <stdio.h>

int main(void)
{
    int a = 3, b = 4, c = 5;
    double x = 1.414, y = 1.732, z = 2.712;
    printf("a=%7d b=%7d c=%7d\n", a, b, c);
    printf("x=%7.3f y=%7.3f z=%7.3f\n", x, y, z);
    return 0;
}
