/*
实验七 6: 求出n名学生某一门课程中的最高成绩、最低成绩和高于平均成绩的人数。
*/
#include <stdio.h>
#define MAX_SIZE 100

int main(void)
{
    int scores[MAX_SIZE];
    int n, max, min, count = 0;
    double sum = 0, avg;
    
    printf("请输入学生人数n: ");
    scanf("%d", &n);
    
    if (n > MAX_SIZE)
        n = MAX_SIZE;
    
    printf("请输入%d个成绩：", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &scores[i]);
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
