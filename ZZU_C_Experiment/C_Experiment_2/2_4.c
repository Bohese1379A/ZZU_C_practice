/*
 * 实验二 4: 使用宏定义 PI=3.14159，求 r=2.456 时的周长和面积。
 *
 * 知识点：预处理宏、符号常量、浮点表达式。
 * 解题思路：按题设固定 PI 和 r，把同一个 PI 代入两条公式。
 * 代码逻辑：定义宏 PI，设定半径，依次输出周长和面积。
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
