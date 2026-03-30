/*
实验六 4: 百钱买百鸡问题。
*/
#include <stdio.h>

int main(void)
{
    for (int x = 0; x <= 20; x++)     // 公鸡
        for (int y = 0; y <= 33; y++) // 母鸡
        {
            int z = 100 - x - y;
            if (z >= 0 && (5 * x + 3 * y + z / 3.0) == 100 && z % 3 == 0)
            {
                printf("cock=%d hen=%d chick=%d\n", x, y, z);
            }
        }
    return 0;
}
