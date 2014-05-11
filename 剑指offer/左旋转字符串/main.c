#include <stdio.h>
#include <string.h>

#define N 1001

char str[N];

void swap_string(int start, int end)
{
    char tmp;
    while (start < end)
    {
        tmp = str[end];
        str[end] = str[start];
        str[start] = tmp;
        start++;
        end--;
    }
}
int main()
{
    //freopen("test.txt", "r", stdin);

    int len, cnt;
    while(scanf("%s", str) != EOF)
    {
        len = strlen(str);
        scanf("%d", &cnt);
        cnt = cnt % len;
        swap_string(0, cnt - 1);
        swap_string(cnt, len - 1);
        swap_string(0, len - 1);
        printf("%s\n", str);
    }
    return 0;
}

/**************************************************************
    Problem: 1362
    User: lintingbin2009
    Language: C
    Result: Accepted
    Time:70 ms
    Memory:916 kb
****************************************************************/
