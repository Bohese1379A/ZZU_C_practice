/*
实验八 5: 有一个m×n矩阵，找出最大元素值及最大元素所在的行、列位置。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main(void)
{
    int m, n;
    int matrix[MAX_ROWS][MAX_COLS];
    int max_val, max_row, max_col;
    
    printf("请输入行数m: ");
    scanf("%d", &m);
    printf("请输入列数n: ");
    scanf("%d", &n);
    
    if (m > MAX_ROWS) m = MAX_ROWS;
    if (n > MAX_COLS) n = MAX_COLS;
    
    srand(time(NULL));
    
    // 生成随机矩阵
    printf("生成的矩阵：\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 100; // 0-99
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    
    // 找出最大值及其位置
    max_val = matrix[0][0];
    max_row = 0;
    max_col = 0;
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] > max_val)
            {
                max_val = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }
    
    printf("最大元素值：%d\n", max_val);
    printf("位置：第%d行，第%d列\n", max_row + 1, max_col + 1);
    
    return 0;
}
