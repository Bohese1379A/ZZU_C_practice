/*
实验七 1: 随机产生10个[50,100]的正整数，求最大值、最小值和平均值。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int arr[10];
    int max, min;
    double sum = 0;
    
    srand(time(NULL));
    
    printf("生成的数组：");
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 51 + 50; // 50-100
        printf("%d ", arr[i]);
        sum += arr[i];
    }
    printf("\n");
    
    max = min = arr[0];
    for (int i = 1; i < 10; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    
    printf("最大值：%d\n", max);
    printf("最小值：%d\n", min);
    printf("平均值：%.2f\n", sum / 10);
    
    return 0;
}
