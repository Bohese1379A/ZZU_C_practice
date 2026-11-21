/*
 * 实验二 5: float c=3.123456789 后按 %f 输出，观察舍入变化（程序打印示例）。
 *
 * 知识点：float 的存储精度、printf 的默认精度。
 * 解题思路：观察常量存入单精度变量后，再用 %f 输出时的舍入结果。
 * 代码逻辑：用 f 后缀构造 float 常量，调用 printf 观察默认六位小数的显示。
 */
#include <stdio.h>

int main(void)
{
    float c = 3.123456789f;
    printf("c = %f\n", c); // float 传入 printf 时提升为 double，%f 默认显示六位小数。
    return 0;
}
