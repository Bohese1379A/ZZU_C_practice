/*
 * 实验七 3: 随机产生10个50以内的正整数，从大到小排序。
 *
 * 知识点：冒泡排序、相邻比较、交换。
 * 解题思路：相邻元素逆序时交换，顺序扫描一轮会把当前最小值移到末端。
 * 代码逻辑：打印初始数组，多轮冒泡逐步缩小未排序范围，再打印降序结果。
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
        for (int j = 0; j < 9 - i; j++) // 数组尾部已有 i 个元素就位，本轮跳过它们。
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
