/*
实验九 3: 编写一个函数过程，判定一个数是否为"回文数"。
*/
#include <stdio.h>

int is_palindrome(int n)
{
    if (n < 0)
        return 0;
    
    int original = n;
    int reversed = 0;
    
    while (n > 0)
    {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    
    return original == reversed;
}

int main(void)
{
    int num;
    printf("请输入一个整数: ");
    scanf("%d", &num);
    
    if (is_palindrome(num))
        printf("%d 是回文数\n", num);
    else
        printf("%d 不是回文数\n", num);
    
    return 0;
}
