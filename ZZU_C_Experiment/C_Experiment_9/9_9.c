/* 实验九 9：用牛顿迭代求 x^5 + 2x^3 - x^2 + x + 1 = 0 在 0 附近的根。 */
#include <math.h>
#include <stdio.h>

static double f(double x)
{
    double x2 = x * x;
    return x2 * x2 * x + 2 * x2 * x - x2 + x + 1;
}

static double derivative(double x)
{
    double x2 = x * x;
    return 5 * x2 * x2 + 6 * x2 - 2 * x + 1;
}

static int newton(double initial, double tolerance, int max_iterations, double *root)
{
    double x = initial;
    for (int i = 0; i <= max_iterations; ++i) {
        double value = f(x);
        if (!isfinite(value))
            return 0;
        if (fabs(value) <= tolerance) {
            *root = x;
            return 1;
        }
        double slope = derivative(x);
        if (i == max_iterations || !isfinite(slope) || fabs(slope) <= 1e-12)
            return 0;
        x -= value / slope;
    }
    return 0;
}

int main(void)
{
    double root;
    if (!newton(0.0, 1e-12, 100, &root)) {
        fputs("牛顿迭代未收敛。\n", stderr);
        return 1;
    }
    printf("近似根: %.10f\n", root);
    printf("f(root) = %.6e\n", f(root));
    return 0;
}
