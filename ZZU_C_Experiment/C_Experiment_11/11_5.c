/*
实验十一 5: 用选择法对10个整数排序（降序）。
*/
#include <stdio.h>
#include "../common/lab_input.h"

#define SIZE 10

void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (*(arr + j) > *(arr + max_index))
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
        if (!lab_read_int(&arr[i]))
        {
            fputs("输入错误：需要 10 个整数。\n", stderr);
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
