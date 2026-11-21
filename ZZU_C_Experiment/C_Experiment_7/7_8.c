/*
 * 实验七 8: 将一个一维数组反序放置。
 *
 * 知识点：数组原地反转、双下标、交换。
 * 解题思路：从两端成对交换元素，下标相遇或交错时结束。
 * 代码逻辑：显示反转前数组，使用临时变量交换左右元素，随后输出反转结果。
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
    for (int i = 0, j = ARRAY_SIZE - 1; i < j; i++, j--) // 左右下标相遇时，所有对称位置均已处理。
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
