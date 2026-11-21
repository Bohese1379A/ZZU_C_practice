/*
 * 实验二 3：已知华氏温度 F，按 C = 5/9 * (F-32) 求摄氏温度。
 *
 * 知识点：浮点除法、温标换算、输出精度。
 * 解题思路：按公式先减去华氏温标偏移量 32，再乘浮点比例 5/9。
 * 代码逻辑：读入华氏温度 F，计算摄氏温度 C，按两位小数输出。
 */
#include <stdio.h>

int main(void)
{
    double F;
    if (scanf("%lf", &F) == 1)
    {
        double C = 5.0 / 9.0 * (F - 32.0); // 比例用浮点常量，保留 5/9 的小数部分。
        printf("%.2f\n", C);
    }
    else
    {
        fprintf(stderr, "Input error: expected temperature\n");
        return 1;
    }
    return 0;
}
