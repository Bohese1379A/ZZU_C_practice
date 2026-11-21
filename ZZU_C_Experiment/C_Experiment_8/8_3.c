/*
 * 实验八 3: 将方阵m(n,n)对角线上的元素置为1，其余元素置为0。
 *
 * 知识点：主对角线、单位矩阵、行列下标。
 * 解题思路：主对角线上的行下标与列下标相等，可以据此决定单元格的值。
 * 代码逻辑：校验阶数，遍历全部位置写入 1 或 0，再输出方阵。
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
