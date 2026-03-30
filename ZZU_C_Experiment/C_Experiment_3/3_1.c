/*
实验三 1: 格式化输出给定若干变量，域宽为7位。
*/
#include <stdio.h>

int main(void)
{
    int a = 3, b = 4, c = 5;
    double x = 1.414, y = 1.732, z = 2.712;
    printf("a=%7d b=%7d c=%7d x=%7.3f y=%7.3f z=%7.3f\n", a, b, c, x, y, z);
    return 0;
}
