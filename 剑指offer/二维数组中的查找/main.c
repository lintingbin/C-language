#include <stdio.h>
#define N 1000
int input[N][N];
int m, n, num;

int IsExist(int arr, int cols)
{
    while (arr < n && cols >=0)
    {
        if (input[arr][cols] == num)
            return 1;
        else if (input[arr][cols] > num)
        {
            cols--;
        }
        else
        {
            arr++;
        }
    }
    return 0;
}
int main()
{
    //freopen("test.txt", "r", stdin);

    int i, j;

    while(scanf("%d%d", &n, &m) != EOF)
    {
        scanf("%d", &num);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                scanf("%d", &input[i][j]);
            }
        if (IsExist(0, m-1))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

/**************************************************************
Problem: 1384
User: lintingbin2009
Language: C
Result: Accepted
Time:690 ms
Memory:4820 kb
****************************************************************/
