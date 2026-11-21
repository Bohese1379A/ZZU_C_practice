/* 实验十一 6：读取以回车结束的字符串并原样输出。 */
#include <stdio.h>
#include "../common/lab_input.h"

int main(void)
{
    char text[1024];
    printf("请输入一行文字：");
    if (!lab_read_line(text, sizeof text)) {
        fputs("输入错误：需要一行不超过 1023 字节的文本。\n", stderr);
        return 1;
    }
    printf("输入的字符串: %s\n", text);
    return 0;
}
