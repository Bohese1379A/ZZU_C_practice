/*
实验二 3：将华氏温度转换成摄氏温度，保留两位小数。
*/
#include <stdio.h>
#include "../common/lab_input.h"

int main(void)
{
    double F;
    if (lab_read_double(&F))
    {
        double C = 5.0 / 9.0 * (F - 32.0);
        printf("%.2f\n", C);
    }
    else
    {
        fprintf(stderr, "Input error: expected temperature\n");
        return 1;
    }
    return 0;
}
