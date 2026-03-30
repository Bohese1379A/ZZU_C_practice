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
            break;
        if (isdigit(ch))
            digits++;
        else if (isalpha(ch))
            letters++;
        else if (ch != '\n' && ch != '\r')
            others++;
    }
    printf("digits=%d letters=%d others=%d\n", digits, letters, others);
    return 0;
}
