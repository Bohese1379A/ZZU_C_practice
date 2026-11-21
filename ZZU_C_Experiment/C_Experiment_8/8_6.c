/*
实验八 6: 有n名考生，每位考生有考号和1个总分成绩，如果录取m人，确定录取分数线，并输出录取考生的考号和成绩。
*/
#include <stdio.h>
#include "../common/lab_input.h"

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
    if (!lab_read_int(&n) || n < 1 || n > MAX_STUDENTS)
    {
        fputs("输入错误：考生人数必须在 1 到 100 之间。\n", stderr);
        return 1;
    }

    // 输入考生信息
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d个考生的考号和成绩: ", i + 1);
        if (!lab_read_int(&students[i].id) || !lab_read_int(&students[i].score))
        {
            fputs("输入错误：需要整数考号和总分。\n", stderr);
            return 1;
        }
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
    if (!lab_read_int(&m) || m < 1 || m > n)
    {
        fputs("输入错误：录取人数应为 1 到考生总数之间的整数。\n", stderr);
        return 1;
    }

    int cutoff = students[m - 1].score;

    printf("录取分数线: %d\n", cutoff);
    printf("录取考生信息: \n");
    for (int i = 0; i < m; i++)
    {
        printf("考号: %d, 成绩: %d\n", students[i].id, students[i].score);
    }

    return 0;
}
