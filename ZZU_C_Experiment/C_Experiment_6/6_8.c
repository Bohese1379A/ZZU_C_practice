/*
 * 实验六 6: 求 x、y、z 的值，使得 xxz + yzz = 532。
 *
 * 知识点：多层枚举、数字位权、逻辑表达式。
 * 解题思路：用百位、十位和个位的权重，把 x、y、z 拼成两个整数。
 * 代码逻辑：枚举各位数字，构造 xxz 与 yzz，满足加和条件时输出。
 */
#include <stdio.h>

int main(void)
{
    for (int x = 0; x <= 9; x++)
    {
        for (int y = 0; y <= 9; y++)
        {
            for (int z = 0; z <= 9; z++)
            {
                int xxz = x * 100 + x * 10 + z; // 按十进制位权拼接，不把 xxz 当成乘积。
                int yzz = y * 100 + z * 10 + z;
                if (xxz + yzz == 532)
                {
                    printf("x=%d, y=%d, z=%d\n", x, y, z);
                }
            }
        }
    }
    return 0;
}
