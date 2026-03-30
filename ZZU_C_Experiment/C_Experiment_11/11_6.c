/*
实验十一 6: 从键盘输入一串符号（以回车键结束），将其以字符串形式存入一维字符数组，然后再输出该字符串。
*/
#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    char str[MAX_SIZE];
    int i = 0;
    char ch;
    
    printf("请输入一串符号（以回车键结束）: ");
    
    while ((ch = getchar()) != '\n' && i < MAX_SIZE - 1)
    {
        str[i] = ch;
        i++;
    }
    str[i] = '\0'; // 字符串结束符
    
    printf("输入的字符串: %s\n", str);
    
    return 0;
}
