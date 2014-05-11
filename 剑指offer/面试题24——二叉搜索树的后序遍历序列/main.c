#include <stdio.h>
#define N 10001
 
int input[N];
 
int main()
{
    //freopen("/home/lintingbin/test.txt", "r", stdin);
    int n, i, j, k, Yes;
     
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &input[i]);
        Yes = 1;
        for (i = n-1; i >=0; i--)
        {
            k = -1;
            for (j = i - 1; i >= 0 && j >= 0; j--)
            {
                if (input[j] < input[i])
                {
                    k = j;
                    break;
                }
            }
            for (j = 0; j <= k; j++)
                if (input[j] > input[i])
                    Yes = 0;
            for (j = k+1; j < i; j++)
                if (input[j] < input[i])
                    Yes = 0;
        }
        if (Yes)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
 
/**************************************************************
    Problem: 1367
    User: lintingbin2009
    Language: C
    Result: Accepted
    Time:70 ms
    Memory:952 kb
****************************************************************/
