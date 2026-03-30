/*
实验九 9: 编写函数程序，用牛顿迭代法求方程x?+2x??x?+x+1=0在0附近的近似值。
*/
#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 2 * x * x * x + x + 1; // 简化后：2x? + x + 1
}

double f_prime(double x)
{
    return 6 * x * x + 1; // 导数：6x? + 1
}

double newton_method(double initial, double tolerance, int max_iter)
{
    double x = initial;
    for (int i = 0; i < max_iter; i++)
    {
        double fx = f(x);
        if (fabs(fx) < tolerance)
            return x;
        double fpx = f_prime(x);
        if (fpx == 0)
            break;
        x = x - fx / fpx;
    }
    return x;
}

int main(void)
{
    double initial = 0.0;
    double tolerance = 1e-6;
    int max_iter = 100;
    
    double root = newton_method(initial, tolerance, max_iter);
    
    printf("方程在0附近的近似根: %.6f\n", root);
    printf("f(root) = %.6e\n", f(root));
    
    return 0;
}
