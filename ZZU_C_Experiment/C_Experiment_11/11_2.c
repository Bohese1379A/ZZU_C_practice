/*
实验十一 2: 输入n个单精度数存入一维数组，用指针变量处理数组元素的方式将其逆序存放后输出。
*/
#include <stdio.h>
#include "../common/lab_input.h"

#define MAX_SIZE 20

void reverse_array(float *arr, int n)
{
    if (n < 2)
        return;

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
    if (!lab_read_int(&n) || n < 1 || n > MAX_SIZE)
    {
        fputs("输入错误：数组长度必须在 1 到 20 之间。\n", stderr);
        return 1;
    }

    printf("请输入%d个单精度数: ", n);
    for (int i = 0; i < n; i++)
    {
        if (!lab_read_float(&arr[i]))
        {
            fputs("输入错误：需要指定数量的单精度数。\n", stderr);
            return 1;
        }
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
