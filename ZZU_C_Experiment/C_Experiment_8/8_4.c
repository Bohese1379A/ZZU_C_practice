/*
实验八 4: 有一个m×n矩阵，各元素值由随机数产生，将矩阵增加一列，求每一行的元素值之和，并将和放入增加列。
*/
#include <stdio.h>
#include "../common/lab_input.h"
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main(void)
{
    int m, n;
    int matrix[MAX_ROWS][MAX_COLS + 1]; // 额外一列存放和

    printf("请输入行数m: ");
    if (!lab_read_int(&m) || m < 1 || m > MAX_ROWS)
    {
        fputs("输入错误：行数必须在 1 到 10 之间。\n", stderr);
        return 1;
    }
    printf("请输入列数n: ");
    if (!lab_read_int(&n) || n < 1 || n > MAX_COLS)
    {
        fputs("输入错误：列数必须在 1 到 10 之间。\n", stderr);
        return 1;
    }

    srand(time(NULL));

    // 生成随机矩阵并计算每行和
    for (int i = 0; i < m; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 100; // 0-99
            row_sum += matrix[i][j];
        }
        matrix[i][n] = row_sum; // 最后一列存放和
    }

    // 输出结果
    printf("矩阵（最后一列为每行和）：\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
