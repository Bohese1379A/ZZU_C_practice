/*
实验八 5: 有一个m×n矩阵，找出最大元素值及最大元素所在的行、列位置。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#define MAX_ROWS 10
#define MAX_COLS 10

static int read_integer(int *result)
{
    char text[32];
    char *end;

    if (scanf("%31s", text) != 1 || strlen(text) == sizeof text - 1)
        return 0;

    errno = 0;
    long value = strtol(text, &end, 10);
    if (errno == ERANGE || end == text || *end != '\0' ||
        value < INT_MIN || value > INT_MAX)
        return 0;

    *result = (int)value;
    return 1;
}

int main(void)
{
    int m, n;
    int matrix[MAX_ROWS][MAX_COLS];
    int max_val, max_row, max_col;
    
        printf("请输入行数m: ");
    if (!read_integer(&m) || m < 1 || m > MAX_ROWS)
    {
        fprintf(stderr, "行数必须是 1 到 %d 的整数。\n", MAX_ROWS);
        return 1;
    }

    printf("请输入列数n: ");
    if (!read_integer(&n) || n < 1 || n > MAX_COLS)
    {
        fprintf(stderr, "列数必须是 1 到 %d 的整数。\n", MAX_COLS);
        return 1;
    }
    
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
