/*
 * 实验一 5：输入圆的半径，求圆的面积和周长。
 *
 * 知识点：宏常量、圆面积和周长公式。
 * 解题思路：用同一个 PI 宏代入面积和周长公式，并检查半径是否有效。
 * 代码逻辑：读取半径 r，依次计算 PI*r*r 和 2*PI*r。
 */
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

int main(void)
{
    double r;
    if (scanf("%lf", &r) == 1)
    {
        if (r < 0)
        {
            fprintf(stderr, "Invalid input: radius must be non-negative\n");
            return 1;
        }
        printf("area=%.6f\n", PI * r * r);
        printf("circumference=%.6f\n", 2 * PI * r);
    }
    else
    {
        fprintf(stderr, "Input error: expected radius\n");
        return 1;
    }
    return 0;
}
