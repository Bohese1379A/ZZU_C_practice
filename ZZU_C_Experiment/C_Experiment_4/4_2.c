/*
????? 2: ??¦Ê??? y ?????
 y = x (x<1);
 y = 2x-1 (1<=x<10);
 y = 3x-11 (x>=10)
*/
#include <stdio.h>

int main(void)
{
    double x;
    if (scanf("%lf", &x) == 1)
    {
        double y;
        if (x < 1)
            y = x;
        else if (x < 10)
            y = 2 * x - 1;
        else
            y = 3 * x - 11;
        printf("%.6f\n", y);
    }
    else
    {
        fprintf(stderr, "Input error: expected a number\n");
        return 1;
    }
    return 0;
}
