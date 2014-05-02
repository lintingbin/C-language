#include <stdio.h>
#define N 100000

int main()
{
    //freopen("test.txt", "r", stdin);
    int count, input[N], output[N], i, j;

    while (scanf("%d", &count) != EOF)
    {
        for (i = 0; i < count; i++)
            scanf("%d", &input[i]);
        for (i = j = 0; i < count; i++)
            if ( input[i]%2 != 0)
                output[j++] = input[i];
        for (i = 0; i < count; i++)
            if ( input[i]%2 == 0)
                output[j++] = input[i];
        for (i = 0; i < count-1; i++)
            printf("%d ", output[i]);
        printf("%d", output[count-1]);
        printf("\n");
    }
    return 0;
}

/**************************************************************
Problem: 1516
User: lintingbin2009
Language: C
Result: Accepted
Time:80 ms
Memory:1624 kb
 ****************************************************************/
