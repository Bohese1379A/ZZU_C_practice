/*
实验八 1: 将一维数组a[9]中各元素值按行的顺序放入二维数组b[3×3]。
*/
#include <stdio.h>

int main(void)
{
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[3][3];
    
    // 按行顺序填充二维数组
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            b[i][j] = a[i * 3 + j];
        }
    }
    
    // 输出结果
    printf("二维数组b[3×3]：\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%4d", b[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
