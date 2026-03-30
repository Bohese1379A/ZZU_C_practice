/*
实验六 6: 求 x、y、z 的值，使得 xxz + yzz = 532。
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
                int xxz = x * 100 + x * 10 + z;
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
