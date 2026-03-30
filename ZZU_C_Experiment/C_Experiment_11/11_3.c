/*
实验十一 3: 利用指针完成两个变量值互换。
*/
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int x, y;
    printf("请输入两个整数: ");
    scanf("%d %d", &x, &y);
    
    printf("交换前: x=%d, y=%d\n", x, y);
    
    swap(&x, &y);
    
    printf("交换后: x=%d, y=%d\n", x, y);
    
    return 0;
}
