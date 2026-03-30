/*
????? 3: ???????????????? A(>=90), B(80-89), C(70-79), D(60-69), E(<60)
*/
#include <stdio.h>

int main(void)
{
    int score;
    if (scanf("%d", &score) == 1)
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
        fprintf(stderr, "Input error: expected an integer score\n");
        return 1;
    }
    return 0;
}
