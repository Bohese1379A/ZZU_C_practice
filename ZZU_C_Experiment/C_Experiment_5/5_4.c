/*
实验五 4: 输入30个字符，统计数字、字母及其他字符个数。
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int digits = 0, letters = 0, others = 0;
    for (int i = 0; i < 30; i++)
    {
        int ch = getchar();
        if (ch == EOF)
        {
            fputs("Input error: expected 30 characters\n", stderr);
            return 1;
        }
        if (isdigit(ch))
            digits++;
        else if (isalpha(ch))
            letters++;
        else
            others++;
    }
    printf("digits=%d letters=%d others=%d\n", digits, letters, others);
    return 0;
}
