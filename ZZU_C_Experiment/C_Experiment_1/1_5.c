/*
实验一 5：输入圆的半径，求面积和周长。
*/
#include <stdio.h>
#include "../common/lab_input.h"
#include <math.h>
#define PI 3.14159265358979323846

int main(void)
{
    double r;
    if (lab_read_double(&r))
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
