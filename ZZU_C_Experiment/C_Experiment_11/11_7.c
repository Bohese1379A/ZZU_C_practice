/*
 * 实验十一 7: 编写一个程序计算一个字符串的长度。
 *
 * 知识点：fgets、字符串结束符、指针遍历。
 * 解题思路：读取整行并去掉行尾换行，从首地址数到字符串结束符。
 * 代码逻辑：调用 string_length 逐字节递增指针，返回长度并输出。
 */
#include <stdio.h>
#include <string.h>

int string_length(const char *str)
{
    int length = 0;
    while (*str) // 逐字节前移，遇到字符串结束符时循环结束。
    {
        length++;
        str++;
    }
    return length;
}

int main(void)
{
    char str[100];
    printf("请输入一个字符串: ");
    if (fgets(str, sizeof str, stdin) == NULL)
    {
        fputs("无法读取字符串。\n", stderr);
        return 1;
    }
    str[strcspn(str, "\r\n")] = '\0'; // 去掉行尾换行，字符串里的空格照常计数。
    
    int len = string_length(str);
    printf("字符串长度: %d\n", len);
    
    return 0;
}
