#include <stdio.h>
//从一打印到n，要考虑大数
int plusOne(char *c)
{
    if (*c<='9'&&*c>='0')
    {
        if (*c == '9')
        {
            *c = '0';
            return 1;
        }
        else
        {
            (*c)++;
            return 0;
        }
    }
    return -1;
}
int stringPlusOne(char *str)
{
    int plus = 0, i = strlen(str) - 1;

    plus = plusOne(&str[i--]);
    for (; i >= 0; i--)
    {
        if (plus == 1)
            plusOne(&str[i]);
        else
            break;
        if (plus == -1)
            return -1;
    }
    for (i = 0; i < strlen(str); i++)
        if (str[i] == '0')
            continue;
        else
            return 0;
    return 1;
}
int print1toMax(int n)
{
    int i;
    char num[100];

    for (i = 0; i < n; i++)
        num[i] = '0';
    num[i] = '\0';

    while (stringPlusOne(num) == 0)
    {
        printf("%s\n", num);
    }
    if (stringPlusOne == -1)
        return -1;
    return 0;
}

void print1toNmax(int n)
{
    int i;
    char str[100];

    str[n] = '\0';
    print1toMaxRecurse(str, strlen(str), 0);
}
void printCharNum(char *str)
{
    while (*str == '0')
        str++;
    if (*str == '\0')
        printf("%d\n", 0);
    else
        printf("%s\n", str);
}
void print1toMaxRecurse(char *str, int len, int index)
{
    int i;

    if (index == len)
    {
        printCharNum(str);
        return;
    }
    for (i = 0; i < 10; i++)
    {
        str[index] = i + '0';
        print1toMaxRecurse(str, len, index + 1);
    }
}
