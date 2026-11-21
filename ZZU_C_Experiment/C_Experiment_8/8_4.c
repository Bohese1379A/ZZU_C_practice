/*
 * 实验八 4: 有一个m×n矩阵，各元素值由随机数产生，将矩阵增加一列，求每一行的元素值之和，并将和放入增加列。
 *
 * 知识点：二维数组、行累加、额外列的下标。
 * 解题思路：分配矩阵时预留一列，每处理一行就重新开始计算该行的和。
 * 代码逻辑：校验行列数，生成随机值并累加；每行的和写入下标 n 的额外列，再一起打印。
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main(void)
{
    int m, n;
    int matrix[MAX_ROWS][MAX_COLS + 1]; // 额外一列存放和
    
    printf("请输入行数m: ");
    if (scanf("%d", &m) != 1 || m < 1 || m > MAX_ROWS)
    {
        fprintf(stderr, "行数必须是 1 到 %d 的整数。\n", MAX_ROWS);
        return 1;
    }
    printf("请输入列数n: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_COLS)
    {
        fprintf(stderr, "列数必须是 1 到 %d 的整数。\n", MAX_COLS);
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
        matrix[i][n] = row_sum; // 原列下标为 0 到 n-1，额外列的下标为 n。
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
