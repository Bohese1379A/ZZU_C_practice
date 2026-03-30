/*
实验八 6: 有n名考生，每位考生有考号和1个总分成绩，如果录取m人，确定录取分数线，并输出录取考生的考号和成绩。
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
    scanf("%d", &n);
    
    if (n > MAX_STUDENTS)
        n = MAX_STUDENTS;
    
    // 输入考生信息
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d个考生的考号和成绩: ", i + 1);
        scanf("%d %d", &students[i].id, &students[i].score);
    }
    
    // 按成绩从高到低排序
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].score < students[j + 1].score)
            {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    printf("请输入录取人数m: ");
    scanf("%d", &m);
    
    if (m > n)
        m = n;
    
    int cutoff = 0;
    if (m > 0)
        cutoff = students[m - 1].score;
    
    printf("录取分数线: %d\n", cutoff);
    printf("录取考生信息: \n");
    for (int i = 0; i < m; i++)
    {
        printf("考号: %d, 成绩: %d\n", students[i].id, students[i].score);
    }
    
    return 0;
}
