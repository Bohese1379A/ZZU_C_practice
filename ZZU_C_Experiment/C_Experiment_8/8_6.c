/*
 * 实验八 6: 有n名考生，每位考生有考号和1个总分成绩，如果录取m人，确定录取分数线，并输出录取考生的考号和成绩。
 *
 * 知识点：结构体数组、稳定排序、名次下标。
 * 解题思路：把考号和成绩作为一条记录整体交换，成绩降序排列后按名次取分数线。
 * 代码逻辑：校验考生信息与录取人数，取第 m 个成绩并输出前 m 条记录。
 */
#include <stdio.h>

#define MAX_STUDENTS 100

struct Student {
    int id;      // 考号
    int score;   // 成绩
};

int main(void)
{
    struct Student students[MAX_STUDENTS];
    int n, m;
    
    printf("请输入考生人数n: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_STUDENTS)
    {
        fprintf(stderr, "考生人数必须是 1 到 %d 的整数。\n", MAX_STUDENTS);
        return 1;
    }
    
    // 输入考生信息
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d个考生的考号和成绩: ", i + 1);
        if (scanf("%d %d", &students[i].id, &students[i].score) != 2)
        {
            fprintf(stderr, "请输入整数考号和成绩。\n");
            return 1;
        }
    }
    
    // 按成绩从高到低排序
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].score < students[j + 1].score) // 分数相等时保持原先顺序，交换时同时移动考号和成绩。
            {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    printf("请输入录取人数m: ");
    if (scanf("%d", &m) != 1 || m < 0 || m > n)
    {
        fprintf(stderr, "录取人数必须是 0 到 %d 的整数。\n", n);
        return 1;
    }
    
    int cutoff = 0;
    if (m > 0)
        cutoff = students[m - 1].score; // 第 m 名对应从零开始的下标 m-1。
    
    printf("录取分数线: %d\n", cutoff);
    printf("录取考生信息: \n");
    for (int i = 0; i < m; i++)
    {
        printf("考号: %d, 成绩: %d\n", students[i].id, students[i].score);
    }
    
    return 0;
}
