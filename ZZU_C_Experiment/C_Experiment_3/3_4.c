/*
????? 4: ??1?? scanf ?????????? A B C D?????????? ASCII ??
*/
#include <stdio.h>

int main(void)
{
    char c1, c2, c3, c4;
    if (scanf(" %c %c %c %c", &c1, &c2, &c3, &c4) == 4)
    {
        printf("%d %d %d %d\n", (int)c1, (int)c2, (int)c3, (int)c4);
    }
    else
    {
        fprintf(stderr, "Input error: expected four characters\n");
        return 1;
    }
    return 0;
}
