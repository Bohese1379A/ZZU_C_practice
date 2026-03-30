/*
实验九 6: 编写一个函数过程，求任意字符串CH中数字字符的个数。
*/
#include <stdio.h>
#include <ctype.h>

int count_digits(const char *ch)
{
    int count = 0;
    while (*ch)
    {
        if (isdigit(*ch))
            count++;
        ch++;
    }
    return count;
}

int main(void)
{
    char ch[100];
    printf("请输入一个字符串: ");
    scanf("%s", ch);
    
    int result = count_digits(ch);
    printf("数字字符的个数: %d\n", result);
    
    return 0;
}
