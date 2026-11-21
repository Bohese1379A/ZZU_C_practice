/*
 * 实验五 4: 输入30个字符，统计数字、字母及其他字符个数。
 *
 * 知识点：getchar、EOF、isdigit 和 isalpha。
 * 解题思路：逐字节读取输入，用字符分类函数区分数字、字母和其他字符。
 * 代码逻辑：至多读 30 次，遇到 EOF 提前停止，行尾换行符由程序单独跳过统计。
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
