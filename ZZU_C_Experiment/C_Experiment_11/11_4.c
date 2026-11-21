/*
 * 实验十一 4: 用12个月份的英文名称初始化一个字符指针数组，根据输入的整数显示相应的月份名。
 *
 * 知识点：字符串指针数组、const、数组下标。
 * 解题思路：预存 12 个月份名，用月份减 1 得到数组下标。
 * 代码逻辑：先确认成功读取并且月份在 1 到 12 内，再访问字符串指针数组。
 */
#include <stdio.h>

int main(void)
{
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    int month;
    printf("请输入月份(1-12): ");
    if (scanf("%d", &month) == 1 && month >= 1 && month <= 12)
    {
        printf("月份名: %s\n", months[month - 1]); // 月份从 1 开始，数组下标从 0 开始。
    }
    else
    {
        printf("错误：请输入1-12之间的整数\n");
    }
    
    return 0;
}
