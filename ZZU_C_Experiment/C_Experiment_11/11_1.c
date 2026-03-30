/*
实验十一 1: 用指针变量按从小到大的顺序输出三个整数。
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
    scanf("%d %d %d", &x, &y, &z);
    
    sort_three(&x, &y, &z);
    
    printf("从小到大排序: %d %d %d\n", x, y, z);
    
    return 0;
}
