/*
实验五 3: 计算级数 1 - 1/3 + 1/10 - 1/17 + ... 直到最后一项小于 1e-5。
   通项 (-1)^{n-1} / (n^2 + 1)
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    double sum = 0.0;
    for (int n = 1;; n++)
    {
        double term = ((n % 2 == 1) ? 1.0 : -1.0) / (n * n + 1.0);
        if (fabs(term) < 1e-5)
            break;
        sum += term;
    }
    printf("%.10f\n", sum);
    return 0;
}
