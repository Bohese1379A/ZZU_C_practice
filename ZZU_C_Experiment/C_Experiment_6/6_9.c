/*
实验六 7: 计算销售收入翻两番需要的年数（每年增长10%）。
*/
#include <stdio.h>

int main(void)
{
    double sales = 1.0; // 初始销售收入
    int years = 0;
    
    while (sales < 4.0) // 翻两番即4倍
    {
        sales *= 1.1; // 每年增长10%
        years++;
    }
    
    printf("需要 %d 年实现销售收入翻两番\n", years);
    return 0;
}
