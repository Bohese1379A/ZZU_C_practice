/*
实验三 7: 将 20,64,127 分别转换为八进制和十六进制并输出。
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
