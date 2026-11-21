/*
 * 实验六 2: 输出九九乘法表。
 *
 * 知识点：双层循环、三角形循环范围、列宽。
 * 解题思路：第 i 行需要 i 个算式，所以内层上界随外层行号改变。
 * 代码逻辑：外层从第 1 行到第 9 行，内层输出 1 到 i 的乘法算式，然后换行。
 */
#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++) // 第 i 行的算式只排列到第 i 列。
            printf("%d*%d=%2d ", j, i, i * j);
        printf("\n");
    }
    return 0;
}
