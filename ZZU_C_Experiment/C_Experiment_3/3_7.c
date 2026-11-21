/*
 * 实验三 7: 将 20,64,127 分别转换为八进制和十六进制并输出。
 *
 * 知识点：进制显示、%o 和 %X。
 * 解题思路：同一个整数可以按十进制、八进制或十六进制显示。
 * 代码逻辑：依次把三个给定值交给 printf，分别显示其不同进制写法。
 */
#include <stdio.h>

int main(void)
{
    int a = 20, b = 64, c = 127;
    printf("%d -> octal=%o hex=%X\n", a, a, a);
    printf("%d -> octal=%o hex=%X\n", b, b, b);
    printf("%d -> octal=%o hex=%X\n", c, c, c);
    return 0;
}
