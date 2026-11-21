/* 实验五 3：按题面首项 1 累加 1 - 1/5 + 1/10 - 1/17 + ...。 */
#include <math.h>
#include <stdio.h>

int main(void)
{
    double sum = 1.0;
    for (int n = 2; ; ++n) {
        double term = (n % 2 ? 1.0 : -1.0) / ((double)n * n + 1.0);
        sum += term;
        if (fabs(term) < 1e-5)
            break;
    }
    printf("%.10f\n", sum);
    return 0;
}
