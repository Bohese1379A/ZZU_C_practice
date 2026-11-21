/*
 * 实验七 2: 随机产生20个学生的成绩，统计各分数段人数。
 *
 * 知识点：一维数组、分段计数、随机生成成绩。
 * 解题思路：用五个计数器分别记录题目给出的分数区间。
 * 代码逻辑：每生成一个成绩，就用递增的阈值找到对应区间并增加计数。
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int scores[20];
    int counts[5] = {0}; // 0-59, 60-69, 70-79, 80-89, 90-100
    
    srand(time(NULL));
    
    printf("学生成绩：");
    for (int i = 0; i < 20; i++)
    {
        scores[i] = rand() % 101; // 0-100
        printf("%d ", scores[i]);
        
        if (scores[i] < 60)
            counts[0]++;
        else if (scores[i] < 70)
            counts[1]++;
        else if (scores[i] < 80)
            counts[2]++;
        else if (scores[i] < 90)
            counts[3]++;
        else
            counts[4]++;
    }
    printf("\n");
    
    printf("各分数段人数：\n");
    printf("0-59: %d\n", counts[0]);
    printf("60-69: %d\n", counts[1]);
    printf("70-79: %d\n", counts[2]);
    printf("80-89: %d\n", counts[3]);
    printf("90-100: %d\n", counts[4]);
    
    return 0;
}
