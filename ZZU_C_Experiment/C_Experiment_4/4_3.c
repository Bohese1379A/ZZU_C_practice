/*
 * 实验四 3：读入百分制成绩，输出 A、B、C、D 或 E。
 *
 * 知识点：取值范围、成绩分档、条件判断顺序。
 * 解题思路：先确认输入在 0 到 100，再按等级下限由高到低匹配。
 * 代码逻辑：从 90、80、70、60 依次判断，输出第一个匹配的等级。
 */
#include <stdio.h>

int main(void)
{
    int score;
    if (scanf("%d", &score) == 1 && score >= 0 && score <= 100)
    {
        char grade;
        if (score >= 90)
            grade = 'A';
        else if (score >= 80)
            grade = 'B';
        else if (score >= 70)
            grade = 'C';
        else if (score >= 60)
            grade = 'D';
        else
            grade = 'E';
        printf("%c\n", grade);
    }
    else
    {
        fprintf(stderr, "Input error: expected an integer score from 0 to 100\n");
        return 1;
    }
    return 0;
}
