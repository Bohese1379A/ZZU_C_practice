/*
???? 5: ?????????????????????????
*/
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

int main(void)
{
    double r;
    if (scanf("%lf", &r) == 1)
    {
        if (r < 0)
        {
            fprintf(stderr, "Invalid input: radius must be non-negative\n");
            return 1;
        }
        printf("area=%.6f\n", PI * r * r);
        printf("circumference=%.6f\n", 2 * PI * r);
    }
    else
    {
        fprintf(stderr, "Input error: expected radius\n");
        return 1;
    }
    return 0;
}
