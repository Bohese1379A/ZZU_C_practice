/* 实验十一 8：统计子串（含重叠匹配）在另一个字符串中出现的次数。 */
#include <stdio.h>
#include <string.h>
#include "../common/lab_input.h"

static size_t count_substring(const char *text, const char *pattern)
{
    size_t count = 0, length = strlen(pattern);
    if (length == 0)
        return 0;
    for (; *text; ++text)
        if (strncmp(text, pattern, length) == 0)
            ++count;
    return count;
}

int main(void)
{
    char text[1024], pattern[1024];
    if (!lab_read_line(text, sizeof text) || !lab_read_line(pattern, sizeof pattern)) {
        fputs("输入错误：请先输入原字符串，再输入子串，每行最多 1023 字节。\n", stderr);
        return 1;
    }
    printf("出现次数: %zu\n", count_substring(text, pattern));
    return 0;
}
