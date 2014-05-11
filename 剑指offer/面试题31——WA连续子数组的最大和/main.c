#include <stdio.h>
#define N 100001

int input[N];

int main()
{
    //freopen("/home/lintingbin/test.txt", "r", stdin);
    int n, i, start, end, sum, start_test, end_test, sum_test;

    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &input[i]);
        start = end = start_test = end_test = 0;
        sum = sum_test = input[0];
        for (i = 1; i < n; i++)
        {
            if (sum_test < 0)
            {
                start_test = end_test = i;
                sum_test = input[i];
            }
            else
            {
                sum_test += input[i];
                end_test = i;
            }
            if (sum_test > sum || (sum_test==sum && (end_test-start_test) > (end-start)))
            {
                sum = sum_test;
                start = start_test;
                end = end_test;
            }
        }
        if (n > 0)
            printf("%d %d %d\n", sum, start, end);
        else
            printf("\n");
    }



    return 0;
}

