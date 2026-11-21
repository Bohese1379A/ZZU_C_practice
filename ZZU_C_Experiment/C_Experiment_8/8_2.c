/*
 * 实验八 2: 输出n×n的数字方阵。
 *
 * 知识点：方阵、嵌套循环、后置自增。
 * 解题思路：按行遍历 n×n 个位置，把从 1 开始的连续数字逐个填进去。
 * 代码逻辑：校验方阵阶数，完成填充后再按相同的行列范围打印。
 */
#include <stdio.h>

#define MAX_SIZE 10

int main(void)
{
    int n, matrix[MAX_SIZE][MAX_SIZE];
    
    printf("请输入n (1-%d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE)
    {
        fprintf(stderr, "方阵阶数必须是 1 到 %d 的整数。\n", MAX_SIZE);
        return 1;
    }
    
    // 填充数字方阵
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = num++; // 先把 num 当前值写入，再增加 num。
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
