/*
 * 实验七 1: 随机产生10个[50,100]的正整数，求最大值、最小值和平均值。
 *
 * 知识点：一维数组、闭区间随机值、极值和均值。
 * 解题思路：生成全部元素后，以首项作为最大值和最小值的共同初值。
 * 代码逻辑：生成并输出 10 个数，同时累加；再扫一遍得到极值和平均值。
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
    
    max = min = arr[0]; // 以实际元素为初值，避免假设随机数会包含上下界。
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
