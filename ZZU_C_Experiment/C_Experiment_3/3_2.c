/*
实验三 2: 使用6个 scanf 完成输入并按格式输出（占位模板）。
*/
#include <stdio.h>

int main(void)
{
    int a, b, c;
    double x, y, z;
    if (scanf("%d %d %d %lf %lf %lf", &a, &b, &c, &x, &y, &z) == 6)
    {
        printf("a=%d b=%d c=%d x=%.3f y=%.3f z=%.3f\n", a, b, c, x, y, z);
    }
    else
    {
        fprintf(stderr, "Input error: expected 6 values (3 ints and 3 floats)\n");
        return 1;
    }
    return 0;
}
