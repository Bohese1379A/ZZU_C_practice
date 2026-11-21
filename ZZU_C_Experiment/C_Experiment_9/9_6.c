/*
 * 实验九 6: 编写一个函数过程，求任意字符串CH中数字字符的个数。
 *
 * 知识点：字符串指针、fgets、isdigit 的合法参数。
 * 解题思路：逐字节扫描整行，仅当当前字节为数字字符时增加计数。
 * 代码逻辑：有界读取一行，由 count_digits 遍历至结束符并返回计数。
 */
#include <stdio.h>
#include <ctype.h>

int count_digits(const char *ch)
{
    int count = 0;
    while (*ch) // 当前字节为字符串结束符时停止。
    {
        if (isdigit((unsigned char)*ch)) // 转成无符号字节再交给字符分类函数。
            count++;
        ch++;
    }
    return count;
}

int main(void)
{
    char ch[100];
    printf("请输入一个字符串: ");
    if (fgets(ch, sizeof ch, stdin) == NULL)
    {
        fputs("无法读取字符串。\n", stderr);
        return 1;
    }
    
    int result = count_digits(ch);
    printf("数字字符的个数: %d\n", result);
    
    return 0;
}
