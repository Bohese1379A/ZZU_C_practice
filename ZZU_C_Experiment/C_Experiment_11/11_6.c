/*
 * 实验十一 6: 从键盘输入一串符号（以回车键结束），将其以字符串形式存入一维字符数组，然后再输出该字符串。
 *
 * 知识点：字符数组、getchar、EOF、字符串结束符。
 * 解题思路：逐字节读入一行，遇到换行、文件结束或缓冲区已满时停止。
 * 代码逻辑：保留最后一个位置写入空字符，把已保存的内容作为字符串打印。
 */
#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    char str[MAX_SIZE];
    int i = 0;
    int ch; // getchar 的 int 返回值还能表示 EOF。
    
    printf("请输入一串符号（以回车键结束）: ");
    
    while (i < MAX_SIZE - 1 && (ch = getchar()) != EOF && ch != '\n')
    {
        str[i] = (char)ch;
        i++;
    }
    str[i] = '\0'; // 字符串结束符
    
    printf("输入的字符串: %s\n", str);
    
    return 0;
}
