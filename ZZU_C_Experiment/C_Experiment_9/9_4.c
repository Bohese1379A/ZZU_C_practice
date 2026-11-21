/*
 * 实验九 4: 编写函数过程求斐波那契数列前n项和FS及平均值V。
 *
 * 知识点：滚动递推、一次累加、用指针返回多个结果。
 * 解题思路：一次生成斐波那契数列并累加，最后用总和除以项数。
 * 代码逻辑：用前一项与当前项推进循环，通过 fs 和 v 两个指针写回结果。
 */
#include <stdio.h>

// n 为项数；调用者通过两个指针接收前 n 项和与平均值。
static void fibonacci_sum_avg(int n, long long *fs, double *v)
{
    long long previous = 0;
    long long current = 1;
    *fs = 0;
    for (int i = 0; i < n; ++i)
    {
        *fs += current;
        long long next = previous + current; // 保留滚动的两项，避免重新求每一项。
        previous = current;
        current = next;
    }
    *v = (double)*fs / n; // 先转为浮点数，再除以项数，保留平均值的小数。
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
