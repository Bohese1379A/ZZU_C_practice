/*
实验十一 7: 编写一个程序计算一个字符串的长度。
*/
#include <stdio.h>

int string_length(const char *str)
{
    int length = 0;
    while (*str)
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
    scanf("%s", str);
    
    int len = string_length(str);
    printf("字符串长度: %d\n", len);
    
    return 0;
}
