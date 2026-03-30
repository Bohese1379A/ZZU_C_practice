/*
实验七 7: 使用数组，求出数列的前20项：0, 1, 1, 2, 4, 7, 13, ……
*/
#include <stdio.h>

int main(void)
{
    long long arr[20];
    
    // 初始化前三项
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    
    // 计算后续项（从第四项开始，每一项是前三项的和）
    for (int i = 3; i < 20; i++)
    {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    
    printf("数列前20项：");
    for (int i = 0; i < 20; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
