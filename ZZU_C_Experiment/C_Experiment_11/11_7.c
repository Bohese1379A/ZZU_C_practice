/* 实验十一 7：通过移动指针统计 C 字符串的字节长度。 */
#include <stdio.h>
#include "../common/lab_input.h"

static size_t string_length(const char *text)
{
    const char *start = text;
    while (*text)
        ++text;
    return (size_t)(text - start);
}

int main(void)
{
    char text[1024];
    if (!lab_read_line(text, sizeof text)) {
        fputs("输入错误：需要一行不超过 1023 字节的文本。\n", stderr);
        return 1;
    }
    printf("字符串长度: %zu\n", string_length(text));
    return 0;
}
