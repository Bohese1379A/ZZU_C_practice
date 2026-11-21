/*
 * 实验九 5: 用梯形法求一元函数f(x)在[a,b]上的积分近似值。
 *
 * 知识点：复合梯形公式、函数参数、步长。
 * 解题思路：把区间等分，端点各计半个权重，内部节点计完整权重。
 * 代码逻辑：由 n 算步长 h，累加 f 在各节点的值并乘 h，分别计算 n=10 和 n=20。
 */
#include <stdio.h>
#include <math.h>

double f(double x)
{
    return sin(2 * x) + x;
}

double trapezoidal_integration(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b)); // 端点只属于一个梯形，权重是内部节点的一半。
    
    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        sum += f(x);
    }
    
    return h * sum;
}

int main(void)
{
    double a = 0.0;
    double b = 3.14159;
    int n1 = 10;
    int n2 = 20;
    
    double s1 = trapezoidal_integration(a, b, n1);
    double s2 = trapezoidal_integration(a, b, n2);
    
    printf("n=10时的积分近似值s1: %.3f\n", s1);
    printf("n=20时的积分近似值s2: %.3f\n", s2);
    
    return 0;
}
