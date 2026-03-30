/*
实验七 3: 随机产生10个50以内的正整数，从大到小排序。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int arr[10];
    
    srand(time(NULL));
    
    printf("排序前：");
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 50 + 1; // 1-50
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 冒泡排序（从大到小）
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("排序后：");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
