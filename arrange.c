#include <stdio.h>
//排列的实现方法，和八皇后的实现方法是类似的

int isOK(int *a, int index, int n)
{
    int i;

    if (a == NULL || index < 0)
        return 0;
    for (i = 0; i < index; i++)
        if (a[i] == n)
            return 0;
    return 1;
}
void DoArrange(int *a, int n, int index)
{
    int i;

    if (a == NULL || n < 1 || index < 0)
        return;
    if (index >= n)
    {
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
        return;
    }
    for (i = 0; i < n; i++)
    {
        if (isOK(a, index, i))
        {
            a[index] = i;
            DoArrange(a, n, index+1);
        }
    }
}

void arrange(int n)
{
    int a[100];

    DoArrange(a, n, 0);
}
