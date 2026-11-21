/*
 * 实验十一 5: 用选择法对10个整数排序（降序）。
 *
 * 知识点：选择排序、指针算术、交换。
 * 解题思路：每轮找未排序部分的最大值，放到当前待填位置。
 * 代码逻辑：读取 10 个数，函数用指针寻找和交换元素，最后显示降序结果。
 */
#include <stdio.h>

#define SIZE 10

void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (*(arr + j) > *(arr + max_index)) // *(arr+j) 等价于 arr[j]，读取第 j 个整数。
                max_index = j;
        }
        if (max_index != i)
        {
            int temp = *(arr + i);
            *(arr + i) = *(arr + max_index);
            *(arr + max_index) = temp;
        }
    }
}

int main(void)
{
    int arr[SIZE];
    
    printf("请输入10个整数: ");
    for (int i = 0; i < SIZE; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            fputs("请输入 10 个整数。\n", stderr);
            return 1;
        }
    }
    
    printf("排序前: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    selection_sort(arr, SIZE);
    
    printf("排序后(降序): ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
