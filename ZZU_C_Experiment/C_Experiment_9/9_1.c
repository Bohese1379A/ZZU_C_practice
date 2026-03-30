/*
实验九 1: 利用函数过程计算 n!/(n!/(n-m)!) = (n-m)!
*/
#include <stdio.h>

long long factorial(int n)
{
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
        return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main(void)
{
    int n, m;
    printf("请输入n和m: ");
    scanf("%d %d", &n, &m);
    
    if (m > n)
    {
        printf("错误：m不能大于n\n");
        return 1;
    }
    
    long long result = factorial(n - m);
    printf("n!/(n!/(n-m)!) = %lld\n", result);
    
    return 0;
}
