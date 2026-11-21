/* 实验九 6：统计一行文字里的 ASCII 数字字符。 */
#include <ctype.h>
#include <stdio.h>
#include "../common/lab_input.h"

static size_t count_digits(const char *text)
{
    size_t count = 0;
    for (; *text; ++text)
        if (isdigit((unsigned char)*text))
            ++count;
    return count;
}

int main(void)
{
    char text[1024];
    if (!lab_read_line(text, sizeof text)) {
        fputs("输入错误：需要一行不超过 1023 字节的文本。\n", stderr);
        return 1;
    }
    printf("数字字符的个数: %zu\n", count_digits(text));
    return 0;
}
