/*
???? 4: ??3????????????????????? sqrt(x) ?? math.h
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        if (a < 0 || b < 0 || c < 0)
        {
            fprintf(stderr, "Invalid input: negative value for sqrt\n");
            return 1;
        }
        printf("%.6f\n", sqrt(a) + sqrt(b) + sqrt(c));
    }
    else
    {
        fprintf(stderr, "Input error: expected three numbers\n");
        return 1;
    }
    return 0;
}
