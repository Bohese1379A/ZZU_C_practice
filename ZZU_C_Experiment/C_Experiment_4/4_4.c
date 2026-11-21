/*
 * 实验四 4: 输入不多于五位的正整数，求位数、输出每个数字并逆序输出。
 *
 * 知识点：字符数组、strlen、strspn、逆序下标。
 * 解题思路：把输入当作数字串保留各位，验证位数、首字符和字符范围。
 * 代码逻辑：合法时打印位数和各位数字，再从最后一个字符向首字符输出。
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[7];
    // 多读一位，把六位及以上的输入判为无效，同时给结束符留位置。
    if (scanf("%6s", s) != 1 || strlen(s) > 5 || s[0] == '0' ||
        s[strspn(s, "0123456789")] != '\0') // 第一段连续数字之后必须正好是字符串结尾。
    {
        fprintf(stderr, "Input error: expected a positive integer with up to five digits\n");
        return 1;
    }

    size_t n = strlen(s);
    printf("digits=%zu\n", n);
    for (size_t i = 0; i < n; ++i)
        printf("%c ", s[i]);
    putchar('\n');
    for (size_t i = n; i > 0; --i)
        putchar(s[i - 1]); // 从 n - 1 开始访问，避免无符号下标减到零以下。
    putchar('\n');
    return 0;
}
