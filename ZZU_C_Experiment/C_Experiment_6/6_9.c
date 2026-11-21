/*
 * 实验六 7: 计算销售收入翻两番需要的年数（每年增长10%）。
 *
 * 知识点：while 循环、复利增长、倍数关系。
 * 解题思路：把初始收入设为 1，每年乘 1.1，直到达到 4 倍。
 * 代码逻辑：每次循环代表一年，更新收入并将累计年数加 1。
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
