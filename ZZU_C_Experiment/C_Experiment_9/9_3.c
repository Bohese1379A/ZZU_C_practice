/*
 * 实验九 3: 编写一个函数过程，判定一个数是否为"回文数"。
 *
 * 知识点：取余、整除、回文判断、扩大整数类型。
 * 解题思路：从个位开始取数字并构造逆序数，再与原数比较。
 * 代码逻辑：读入整数，对非负数逐位翻转；逆序值使用更宽的类型以避免 int 溢出。
 */
#include <stdio.h>

int is_palindrome(int n)
{
    if (n < 0)
        return 0;
    
    int original = n;
    long long reversed = 0; // 十位 int 的逆序值可能超过 int 范围。
    
    while (n > 0)
    {
        int digit = n % 10; // 取出最末位后用整除丢弃这一位。
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    
    return original == reversed;
}

int main(void)
{
    int num;
    printf("请输入一个整数: ");
    if (scanf("%d", &num) != 1)
    {
        fputs("请输入一个整数。\n", stderr);
        return 1;
    }
    
    if (is_palindrome(num))
        printf("%d 是回文数\n", num);
    else
        printf("%d 不是回文数\n", num);
    
    return 0;
}
