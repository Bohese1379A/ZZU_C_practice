/*
实验十一 2: 输入n个单精度数存入一维数组，用指针变量处理数组元素的方式将其逆序存放后输出。
*/
#include <stdio.h>

#define MAX_SIZE 20

void reverse_array(float *arr, int n)
{
    float *start = arr;
    float *end = arr + n - 1;
    
    while (start < end)
    {
        float temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(void)
{
    float arr[MAX_SIZE];
    int n;
    
    printf("请输入n (不大于20): ");
    scanf("%d", &n);
    
    if (n > MAX_SIZE)
        n = MAX_SIZE;
    
    printf("请输入%d个单精度数: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    
    printf("原始数组: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    
    reverse_array(arr, n);
    
    printf("逆序后: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
