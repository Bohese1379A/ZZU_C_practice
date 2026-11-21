/*
 * 实验七 5: 随机产生n个[-10,10]范围内的随机数，删除数组中相同的数，只剩一个。
 *
 * 知识点：下标映射、计数标记、稳定去重。
 * 解题思路：数字只有 -10 到 10 共 21 种，用 seen 数组直接记录是否出现过。
 * 代码逻辑：生成并显示原数组，依原顺序扫描一次，把首次出现的数字追加到结果。
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main(void)
{
    int arr[MAX_SIZE];
    int unique_arr[21];
    int seen[21] = {0};
    int n, unique_count = 0;
    
    printf("请输入n: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE)
    {
        fprintf(stderr, "请输入 1 到 %d 之间的整数。\n", MAX_SIZE);
        return 1;
    }
    
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
        int index = arr[i] + 10; // 值域 [-10, 10] 平移后恰好对应下标 [0, 20]。
        if (!seen[index])
        {
            seen[index] = 1;
            unique_arr[unique_count++] = arr[i];
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
