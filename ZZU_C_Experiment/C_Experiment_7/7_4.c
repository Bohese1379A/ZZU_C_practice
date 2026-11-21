/*
 * 实验七 4: 随机产生20个100以内的正整数，分四行输出，每行5个数。
 *
 * 知识点：一维数组下标、行列映射、格式化对齐。
 * 解题思路：每行打印五个元素，用行号乘列数再加列号定位。
 * 代码逻辑：先生成 20 项，再按四行五列的两个循环访问数组和输出。
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int arr[20];
    
    srand(time(NULL));
    
    for (int i = 0; i < 20; i++)
    {
        arr[i] = rand() % 100 + 1; // 1-100
    }
    
    printf("输出结果：\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%4d", arr[i * 5 + j]); // 行号乘每行元素数，再加列号。
        }
        printf("\n");
    }
    
    return 0;
}
