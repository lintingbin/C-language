#include <stdio.h>
#define N 1001
long long input[N][N];

void printArray(int x, int y, int n, int m)
{
    int i, startX = x, startY = y, endX = x + n - 1, endY = y + m - 1;

    for (i = 0; i <= m - 1; i++)
        printf("%d ", input[startX][startY+i]);
    for (i = 1; i <= n - 1; i++)
        printf("%d ", input[startX+i][endY]);
    for (i = 1; i <= m - 1&&n > 1; i++)//打印的时候注意识别是不是一行
        printf("%d ", input[endX][endY-i]);
    for (i = 1; i < n - 1&&m > 1; i++)
        printf("%d ", input[endX-i][startY]);
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, m, j, i, size;

    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n < 1 || m < 1)
            continue;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                scanf("%d", &input[i][j]);
        size = m < n ? m : n;
        for (i = 0; i < size/2; i++)
            printArray(i, i, n-2*i, m-2*i);
        if (size%2 == 1)
            printArray(i, i, n-2*i, m-2*i);

        printf("\n");
    }
    return 0;
}

/**************************************************************
Problem: 1391
User: lintingbin2009
Language: C
Result: Accepted
Time:530 ms
Memory:8740 kb
 ****************************************************************/
