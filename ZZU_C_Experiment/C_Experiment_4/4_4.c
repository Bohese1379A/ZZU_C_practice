/*
实验四 4: 输入不多于五位的正整数，求位数、输出每个数字并逆序输出。
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[16];
    if (scanf("%15s", s) == 1)
    {
        int n = strlen(s);
        printf("digits=%d\n", n);
        for (int i = 0; i < n; i++)
            printf("%c ", s[i]);
        printf("\n");
        for (int i = n - 1; i >= 0; i--)
            putchar(s[i]);
        putchar('\n');
    }
    return 0;
}
