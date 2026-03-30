/*
实验二 4: 使用宏定义 PI=3.14159，求 r=2.456 时的周长和面积。
*/
#include <stdio.h>
#define PI 3.14159

int main(void)
{
    double r = 2.456;
    printf("circumference=%.6f\n", 2 * PI * r);
    printf("area=%.6f\n", PI * r * r);
    return 0;
}
