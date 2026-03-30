/*
实验八 2: 输出n×n的数字方阵。
*/
#include <stdio.h>

#define MAX_SIZE 10

int main(void)
{
    int n, matrix[MAX_SIZE][MAX_SIZE];
    
    printf("请输入n (1-%d): ", MAX_SIZE);
    scanf("%d", &n);
    
    if (n > MAX_SIZE)
        n = MAX_SIZE;
    
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
