/*
 * 实验九 9：用牛顿迭代法求 x⁵+2x³−x²+x+1=0 在 0 附近的近似根。
 *
 * 知识点：多项式求值、求导、牛顿迭代、误差阈值。
 * 解题思路：给出题设多项式及其导数，从零开始反复更新 x，直到残差足够小。
 * 代码逻辑：先检查残差，再检查导数和迭代次数；收敛后通过指针交回根并显示残差。
 */
#include <stdio.h>
#include <math.h>

static double f(double x)
{
    double square = x * x;
    return square * square * x + 2 * square * x - square + x + 1;
}

static double f_prime(double x)
{
    double square = x * x;
    return 5 * square * square + 6 * square - 2 * x + 1;
}

// 返回 1 时，root 指向的值已达到题中使用的误差要求。
static int newton_method(double x, double tolerance, int max_iter, double *root)
{
    for (int i = 0; i <= max_iter; ++i)
    {
        double value = f(x);
        if (fabs(value) < tolerance)
        {
            *root = x;
            return 1;
        }
        if (i == max_iter)
            break;

        double slope = f_prime(x);
        if (fabs(slope) < 1e-12)
            break;

        x -= value / slope; // 用当前位置切线与横轴的交点作为下一次近似值。
    }
    return 0;
}

int main(void)
{
    double initial = 0.0;
    double tolerance = 1e-6;
    int max_iter = 100;
    
    double root;
    if (!newton_method(initial, tolerance, max_iter, &root))
    {
        fputs("牛顿迭代未在设定次数内收敛。\n", stderr);
        return 1;
    }
    
    printf("方程在0附近的近似根: %.6f\n", root);
    printf("f(root) = %.6e\n", f(root));
    
    return 0;
}
