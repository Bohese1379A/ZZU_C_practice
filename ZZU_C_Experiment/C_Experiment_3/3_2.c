/* 实验三 2：用六次 scanf 分别读入和验证六个值。 */
#include <stdio.h>
#include "../common/lab_input.h"

int main(void)
{
    char token[64];
    int a, b, c;
    double x, y, z;
    if (scanf("%63s", token) != 1 || !lab_parse_int(token, &a) ||
        scanf("%63s", token) != 1 || !lab_parse_int(token, &b) ||
        scanf("%63s", token) != 1 || !lab_parse_int(token, &c) ||
        scanf("%63s", token) != 1 || !lab_parse_double(token, &x) ||
        scanf("%63s", token) != 1 || !lab_parse_double(token, &y) ||
        scanf("%63s", token) != 1 || !lab_parse_double(token, &z)) {
        fputs("Input error: expected three integers and three numbers\n", stderr);
        return 1;
    }

    printf("a=%d b=%d c=%d\nx=%.3f y=%.3f z=%.3f\n", a, b, c, x, y, z);
    return 0;
}
