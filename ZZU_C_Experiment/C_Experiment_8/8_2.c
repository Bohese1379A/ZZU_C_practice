/*
实验八 2: 输出n×n的数字方阵。
*/
#include <stdio.h>
#include "../common/lab_input.h"

#define MAX_SIZE 10

int main(void)
{
    int n, matrix[MAX_SIZE][MAX_SIZE];

    printf("请输入n (1-%d): ", MAX_SIZE);
    if (!lab_read_int(&n) || n < 1 || n > MAX_SIZE)
    {
        fputs("输入错误：方阵边长必须在 1 到 10 之间。\n", stderr);
        return 1;
    }

    // 填充数字方阵
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = num++;
        }
    }

    // 输出结果
    printf("%d×%d数字方阵：\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
