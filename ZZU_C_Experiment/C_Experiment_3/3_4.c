/*
 * 实验三 4：用一次 scanf 读入四个字符，显示其 ASCII 码。
 *
 * 知识点：%c 输入、空白匹配、ASCII 码。
 * 解题思路：读取字符后以整数格式打印对应码值，格式串中的空格用于跳过分隔符。
 * 代码逻辑：用一次 scanf 接收四个字符，随后按输入顺序输出四个码值。
 */
#include <stdio.h>

int main(void)
{
    char c1, c2, c3, c4;
    if (scanf(" %c %c %c %c", &c1, &c2, &c3, &c4) == 4) // %c 前的空白会跳过输入中的分隔空白。
    {
        printf("%d %d %d %d\n", (int)c1, (int)c2, (int)c3, (int)c4);
    }
    else
    {
        fprintf(stderr, "Input error: expected four characters\n");
        return 1;
    }
    return 0;
}
