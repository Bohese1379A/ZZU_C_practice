/*
 * 实验十一 1: 用指针变量按从小到大的顺序输出三个整数。
 *
 * 知识点：取地址、间接访问、三数比较交换。
 * 解题思路：函数收到变量地址后，可以直接交换调用者变量中的数值。
 * 代码逻辑：逐对比较三数并通过指针交换，把最小值放在第一位，再输出。
 */
#include <stdio.h>

void sort_three(int *a, int *b, int *c)
{
    if (*a > *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c)
    {
        int temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c)
    {
        int temp = *b;
        *b = *c;
        *c = temp;
    }
}

int main(void)
{
    int x, y, z;
    printf("请输入三个整数: ");
    if (scanf("%d %d %d", &x, &y, &z) != 3)
    {
        fputs("请输入三个整数。\n", stderr);
        return 1;
    }
    
    sort_three(&x, &y, &z); // 取地址后，排序函数能修改 main 中的三个变量。
    
    printf("从小到大排序: %d %d %d\n", x, y, z);
    
    return 0;
}
