/*
实验七 4: 随机产生20个100以内的正整数，分四行输出，每行5个数。
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
            printf("%4d", arr[i * 5 + j]);
        }
        printf("\n");
    }
    
    return 0;
}
