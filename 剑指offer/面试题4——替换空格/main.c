#include <stdio.h>
#include <string.h>
#define N 1000000
int main()
{
    char input[N];
    int len, i, count;

    while (gets(input) != NULL)
    {

        count = 0;
        len = strlen(input);
        for (i = 0; i < len; i++)
            if (input[i] == ' ')
                count += 1;
        count = count * 2;
        for (i = len; i >= 0; i--)
        {
            if (input[i] == ' ')
            {
                input[i+count] = '0';
                input[i+--count] = '2';
                input[i+--count] = '%';
            }
            else
            {
                input[i+count] = input[i];
            }
        }
        printf("%s\n", input);
    }

    return 0;
}

/**************************************************************
Problem: 1510
User: lintingbin2009
Language: C
Result: Accepted
Time:10 ms
Memory:1820 kb
 ****************************************************************/
