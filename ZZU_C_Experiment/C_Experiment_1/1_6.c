/*
 * 实验一 6: 在屏幕上输出固定字符串两行。
 *
 * 知识点：字符串字面量、puts、顺序执行。
 * 解题思路：题目要求固定文字，按给定顺序输出两个字符串即可。
 * 代码逻辑：连续调用两次 puts，每次输出一行并自动换行。
 */
#include <stdio.h>

int main(void)
{
    puts("What a beautiful campus !");
    puts("I wish you every success !");
    return 0;
}
