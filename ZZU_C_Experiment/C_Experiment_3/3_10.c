/* 实验三 10：用 getchar 读取三个字母，用 putchar 输出其小写形式。 */
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 3; ++i) {
        int ch;
        do {
            ch = getchar();
        } while (ch != EOF && isspace(ch));
        if (ch == EOF || !isalpha(ch)) {
            fputs("Input error: expected three letters\n", stderr);
            return 1;
        }
        putchar(tolower(ch));
        putchar('\n');
    }
    return 0;
}
