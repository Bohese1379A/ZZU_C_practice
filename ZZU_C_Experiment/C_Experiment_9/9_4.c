/*
实验九 4: 编写函数过程求斐波那契数列前n项和FS及平均值V。
*/
#include <stdio.h>

long long fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    
    long long a = 1, b = 1, c;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void fibonacci_sum_avg(int n, long long *fs, double *v)
{
    *fs = 0;
    for (int i = 1; i <= n; i++)
    {
        *fs += fibonacci(i);
    }
    *v = (double)*fs / n;
}

int main(void)
{
    int n = 20;
    long long fs;
    double v;
    
    fibonacci_sum_avg(n, &fs, &v);
    
    printf("斐波那契数列前%d项和FS: %lld\n", n, fs);
    printf("平均值V: %.6f\n", v);
    
    return 0;
}
