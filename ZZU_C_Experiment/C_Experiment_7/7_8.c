/*
实验七 8: 将一个一维数组反序放置。
*/
#include <stdio.h>

#define ARRAY_SIZE 5

int main(void)
{
    int arr[ARRAY_SIZE] = {67, 89, 76, 98, 66};
    int temp;
    
    printf("原始数组：");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 反序操作
    for (int i = 0, j = ARRAY_SIZE - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    printf("反序后：");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
