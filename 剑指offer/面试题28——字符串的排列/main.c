#include <stdio.h>
#include <string.h>
#define N 11

char result[N];

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(char *str, int len)
{
    int chart[200], i, j;

    memset(chart, 0, 200*sizeof(int));
    for (i = 0; i < len; i++)
        chart[str[i]]++;
    for (i = j = 0; i < 200; i++)
        while (chart[i]-- != 0)
            str[j++] = i;
}
int used[N] = {0};
int isRepeat(int *num, int len, int rep)
{
    int i;
    for (i = 0; i < len; i++)
        if (rep == num[i])
            return 1;
    return 0;
}
void pailie(char *str, int len, int index)
{
    int i, j, repeat[N] = {0};

    if (index == len)
        printf("%s\n", result);
    for (i = 0; i < len; i++)
    {
        if (used[i] == 1)
            continue;
        result[index] = str[i];
        if (isRepeat(repeat, i, str[i]))
            continue;
        repeat[i] = str[i];
        used[i] = 1;
        pailie(str, len, index+1);
        used[i] = 0;
    }
}

int main()
{
    //freopen("/home/lintingbin/test.txt", "r", stdin);
    char str[N];
    int len;

    while (scanf("%s", str) != EOF)
    {
        memset(used, 0, N*sizeof(int));
        len = strlen(str);
        result[len] = '\0';
        sort(str, len);
        pailie(str, len, 0);
    }
    return 0;
}

