/*
 * 实验三 6: 将 12345678, 3456789 赋给 m,n 并正确输出。
 *
 * 知识点：long、整数常量后缀 L、%ld。
 * 解题思路：让存储类型、常量和输出格式匹配。
 * 代码逻辑：用带 L 后缀的常量初始化 m、n，再用 %ld 输出。
 */
#include <stdio.h>

int main(void)
{
    long m = 12345678L, n = 3456789L;
    printf("m=%ld n=%ld\n", m, n);
    return 0;
}
