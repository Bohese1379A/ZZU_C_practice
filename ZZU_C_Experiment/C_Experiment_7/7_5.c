/*
实验七 5: 随机产生n个[-10,10]范围内的随机数，删除数组中相同的数，只剩一个。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main(void)
{
    int arr[MAX_SIZE];
    int unique_arr[MAX_SIZE];
    int n, unique_count = 0;
    
    printf("请输入n: ");
    scanf("%d", &n);
    
    if (n > MAX_SIZE)
        n = MAX_SIZE;
    
    srand(time(NULL));
    
    printf("原始数组：");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 21 - 10; // -10 到 10
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 去重
    for (int i = 0; i < n; i++)
    {
        int exists = 0;
        for (int j = 0; j < unique_count; j++)
        {
            if (arr[i] == unique_arr[j])
            {
                exists = 1;
                break;
            }
        }
        if (!exists)
        {
            unique_arr[unique_count] = arr[i];
            unique_count++;
        }
    }
    
    printf("去重后：");
    for (int i = 0; i < unique_count; i++)
    {
        printf("%d ", unique_arr[i]);
    }
    printf("\n");
    
    return 0;
}
