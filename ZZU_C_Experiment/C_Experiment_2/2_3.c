/*
???? 3: ??????? F ??????????? C = 5/9*(F-32)????????¦Ë§³????
*/
#include <stdio.h>

int main(void)
{
    double F;
    if (scanf("%lf", &F) == 1)
    {
        double C = 5.0 / 9.0 * (F - 32.0);
        printf("%.2f\n", C);
    }
    else
    {
        fprintf(stderr, "Input error: expected temperature\n");
        return 1;
    }
    return 0;
}
