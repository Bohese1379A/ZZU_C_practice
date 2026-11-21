/*
 * 实验三 10: 用 getchar() 分别输入 'A','B','C' 并转换为小写输出。
 *
 * 知识点：getchar、EOF、tolower 和 putchar。
 * 解题思路：用 int 接收字符或 EOF，读取成功后再转成小写。
 * 代码逻辑：连续取三个输入字符，逐个转换和输出，每个字符单独占一行。
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int a = getchar(); // 用 int 保存字符值，同时能区分 EOF。
    int b = getchar();
    int c = getchar();
    if (a == EOF || b == EOF || c == EOF)
        return 0;
    putchar(tolower(a));
    putchar('\n');
    putchar(tolower(b));
    putchar('\n');
    putchar(tolower(c));
    putchar('\n');
    return 0;
}
