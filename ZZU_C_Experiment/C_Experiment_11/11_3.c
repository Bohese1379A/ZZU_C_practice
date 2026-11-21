/*
 * 实验十一 3: 利用指针完成两个变量值互换。
 *
 * 知识点：指针参数、取地址、解引用赋值。
 * 解题思路：把两个变量的地址传给 swap，用临时变量保护其中一个原值。
 * 代码逻辑：先输出交换前的值，通过指针交换，再输出交换后的值。
 */
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a; // 先保存 a 指向的原值，避免第一次赋值把它覆盖。
    *a = *b;
    *b = temp;
}

int main(void)
{
    int x, y;
    printf("请输入两个整数: ");
    if (scanf("%d %d", &x, &y) != 2)
    {
        fputs("请输入两个整数。\n", stderr);
        return 1;
    }
    
    printf("交换前: x=%d, y=%d\n", x, y);
    
    swap(&x, &y);
    
    printf("交换后: x=%d, y=%d\n", x, y);
    
    return 0;
}
