#include <stdio.h>
#include <string.h>

#define N 50001

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

    int i, j, len;
    while(gets(str) != NULL)
    {
        len = strlen(str);
        for (i = 0; i < len; i++)
        {
            if (str[i] != ' ')
            {
                j = i;
                while (str[j] != ' ' && j < len)
                {
                    if (str[j+1] == ' ' || j+1 == len)
                        break;
                    j++;
                }
                swap_string(i, j);
                i = j + 1;
            }
        }
        swap_string(0, len-1);
        printf("%s\n", str);
    }
    return 0;
}

/**************************************************************
    Problem: 1361
    User: lintingbin2009
    Language: C
    Result: Accepted
    Time:50 ms
    Memory:964 kb
****************************************************************/
