/*
实验十一 8：统计一个子串在另一个字符串中出现的次数。
*/
#include <stdio.h>
#include <string.h>

int count_substring(const char *str, const char *substr)
{
    int count = 0;
    int str_len = strlen(str);
    int substr_len = strlen(substr);

    if (substr_len == 0)
        return 0;

    for (int i = 0; i <= str_len - substr_len; i++)
    {
        if (strncmp(str + i, substr, substr_len) == 0)
        {
            count++;
        }
    }

    return count;
}

int main(void)
{
    char str[100], substr[100];

    printf("?????????????: ");
    scanf("%s", str);

    printf("?????????????: ");
    scanf("%s", substr);

    int count = count_substring(str, substr);
    printf("???????????: %d\n", count);

    return 0;
}
