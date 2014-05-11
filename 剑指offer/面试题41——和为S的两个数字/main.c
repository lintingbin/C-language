#include <stdio.h>
#define N 1000001

int input[N];

int main()
{
    freopen("test.txt", "r", stdin);
    int n, k, i, j;

    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &input[i]);
        i = 0;
        j = n-1;
        while ((input[i]+input[j]) != k && i != j)
        {
            if ((input[i]+input[j]) > k)
                j--;
            else
                i++;
        }
        if ( i == j)
            printf("%d %d\n", -1, -1);
        else
            printf("%d %d\n", input[i], input[j]);
    }
    return 0;
}
