/*
 * 实验七 6: 求出n名学生某一门课程中的最高成绩、最低成绩和高于平均成绩的人数。
 *
 * 知识点：数组边界、极值、均值和二次遍历。
 * 解题思路：先得到全部成绩和平均值，再比较每个成绩是否高于平均值。
 * 代码逻辑：检查人数及各成绩输入，扫数组求最大最小值，最后统计高于均值的人数。
 */
#include <stdio.h>
#define MAX_SIZE 100

int main(void)
{
    int scores[MAX_SIZE];
    int n, max, min, count = 0;
    double sum = 0, avg;
    
    printf("请输入学生人数n: ");
    // 人数至少为 1，才能以首项初始化极值，并用 n 求平均。
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE)
    {
        fprintf(stderr, "请输入 1 到 %d 之间的整数。\n", MAX_SIZE);
        return 1;
    }
    
    printf("请输入%d个成绩：", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &scores[i]) != 1)
        {
            fprintf(stderr, "请为每名学生输入一个整数成绩。\n");
            return 1;
        }
        sum += scores[i];
    }
    
    max = min = scores[0];
    for (int i = 1; i < n; i++)
    {
        if (scores[i] > max)
            max = scores[i];
        if (scores[i] < min)
            min = scores[i];
    }
    
    avg = sum / n;
    for (int i = 0; i < n; i++)
    {
        if (scores[i] > avg)
            count++;
    }
    
    printf("最高成绩：%d\n", max);
    printf("最低成绩：%d\n", min);
    printf("平均成绩：%.2f\n", avg);
    printf("高于平均成绩的人数：%d\n", count);
    
    return 0;
}
