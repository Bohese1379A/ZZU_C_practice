/*
实验十一 4: 用12个月份的英文名称初始化一个字符指针数组，根据输入的整数显示相应的月份名。
*/
#include <stdio.h>

int main(void)
{
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    int month;
    printf("请输入月份(1-12): ");
    scanf("%d", &month);
    
    if (month >= 1 && month <= 12)
    {
        printf("月份名: %s\n", months[month - 1]);
    }
    else
    {
        printf("错误：请输入1-12之间的整数\n");
    }
    
    return 0;
}
