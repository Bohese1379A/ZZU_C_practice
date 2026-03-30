/*
实验八 3: 将方阵m(n,n)对角线上的元素置为1，其余元素置为0。
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
    
    // 初始化矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) // 主对角线
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    
    // 输出结果
    printf("%d×%d单位矩阵：\n", n, n);
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
