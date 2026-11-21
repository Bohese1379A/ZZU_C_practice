/*
 * 实验十一 2: 输入n个单精度数存入一维数组，用指针变量处理数组元素的方式将其逆序存放后输出。
 *
 * 知识点：数组首地址、指针算术、成对交换。
 * 解题思路：用两个指针从输入数组的两端向中间移动，交换它们指向的元素。
 * 代码逻辑：验证元素数量和输入值，显示原数组后调用 reverse_array 并输出结果。
 */
#include <stdio.h>

#define MAX_SIZE 20

void reverse_array(float *arr, int n)
{
    float *start = arr;
    float *end = arr + n - 1; // 指针加 n-1 个 float 的距离，到达最后一个有效元素。
    
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
    // 合法长度保证 arr + n - 1 指向数组中的最后一个输入元素。
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE)
    {
        fprintf(stderr, "数组长度必须是 1 到 %d 的整数。\n", MAX_SIZE);
        return 1;
    }
    
    printf("请输入%d个单精度数: ", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%f", &arr[i]) != 1)
        {
            fputs("请输入单精度数值。\n", stderr);
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
