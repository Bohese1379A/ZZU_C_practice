/*
实验三 10: 用 getchar() 分别输入 'A','B','C' 并转换为小写输出。
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int a = getchar();
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
