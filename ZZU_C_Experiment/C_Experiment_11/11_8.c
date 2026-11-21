/*
 * 实验十一 8：编写函数，求一个子串在主串中出现的次数。
 *
 * 知识点：strlen、strncmp、滑动下标、无符号长度。
 * 解题思路：在主串的每个可行起点比较固定长度的片段，移动一步允许重叠匹配。
 * 代码逻辑：有界读取两个词，先检查子串长度，再逐位置比较并统计次数。
 */
#include <stdio.h>
#include <string.h>

static size_t count_substring(const char *str, const char *substr)
{
    size_t count = 0;
    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);

    if (substr_len == 0 || substr_len > str_len)
        return 0; // 先处理长子串，避免无符号长度相减发生回绕。

    for (size_t i = 0; i <= str_len - substr_len; ++i)
    {
        if (strncmp(str + i, substr, substr_len) == 0)
            ++count; // 每次只移动一格，因此会统计重叠出现。
    }
    return count;
}

int main(void)
{
    char str[101], substr[101];

    printf("请输入主串: ");
    if (scanf("%100s", str) != 1 || strlen(str) > 99)
    {
        fputs("主串必须包含 1 到 99 个非空白字节。\n", stderr);
        return 1;
    }

    printf("请输入子串: ");
    if (scanf("%100s", substr) != 1 || strlen(substr) > 99)
    {
        fputs("子串必须包含 1 到 99 个非空白字节。\n", stderr);
        return 1;
    }

    size_t count = count_substring(str, substr);
    printf("子串出现次数: %zu\n", count);
    
    return 0;
}
