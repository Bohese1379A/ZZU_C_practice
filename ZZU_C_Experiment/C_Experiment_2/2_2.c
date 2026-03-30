/*
???? 2: ???? a, b ??????????????????????????????
*/
#include <stdio.h>

int main(void)
{
    long a, b;
    if (scanf("%ld %ld", &a, &b) == 2)
    {
        printf("prod=%ld\n", a * b);
        if (b != 0)
        {
            printf("quot=%ld remainder=%ld\n", a / b, a % b);
        }
        else
            printf("division by zero\n");
    }
    else
    {
        fprintf(stderr, "Input error: expected two integers\n");
        return 1;
    }
    return 0;
}
