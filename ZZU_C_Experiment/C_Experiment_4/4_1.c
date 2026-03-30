/*
????? 1: ????????????????? a,b,c?????????????????
*/
#include <stdio.h>

int main(void)
{
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) == 3)
    {
        int m = a;
        if (b > m)
            m = b;
        if (c > m)
            m = c;
        printf("%d\n", m);
    }
    else
    {
        fprintf(stderr, "Input error: expected three integers\n");
        return 1;
    }
    return 0;
}
