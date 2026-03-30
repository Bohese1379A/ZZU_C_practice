/*
实验二 6: 观察复合赋值后的 a 值：int a=2; a+=a; a-=2; a*=2+3; a/=a+a;
*/
#include <stdio.h>

int main(void)
{
    int a = 2;
    a += a;     // a = 4
    a -= 2;     // a = 2
    a *= 2 + 3; // a = 10
    // a /= a + a -> a/(a+a) = 10/20 = 0
    a /= a + a;
    printf("%d\n", a);
    return 0;
}
