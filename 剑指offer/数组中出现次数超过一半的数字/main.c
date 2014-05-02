#include <stdio.h>
#define N 100001


int input[N];
int main()
{
    //freopen("/home/lintingbin/test.txt", "r", stdin);
    int n, i, num, count;

    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &input[i]);
        count = 0;
        for (i = 0; i < n; i++)
        {
            if (count == 0)
            {
                num = input[i];
                count = 1;
            }
            else 
                if (num != input[i]) //这边为什么不是input[i] != input[i-1]
                    count--;
                else
                    count++;
        }
        count = 0;
        for (i = 0; i < n; i++)
            if (input[i] == num)
                count++;
        if (2*count > n)
            printf("%d\n", num);
        else
            printf("-1\n");
    }
    return 0;
}

