#include <stdio.h>
//八皇后的实现方法
int isSafe(int *a, int index)
{
    int i;

    for (i = 0; i < index; i++)
    {
        if (a[i] == a[index])
            return 0;
        if (index - a[index] == i - a[i] || index + a[index] == i + a[i])
            return 0;
    }
    return 1;
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int QueenDo(int *a, int start, int n)
{
    int i, j;
    int count = 0;

    if (start >= n)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[j]);
        printf("\n");
        return 1;
    }
    for (i = start; i < n; i++)
    {
        swap(a+start, a+i);
        if (!isSafe(a, start))
        {
            swap(a+start, a+i);
            continue;
        }
        count = count + QueenDo(a, start+1, n);
        swap(a+start, a+i);
    }
    return count;
}
int eightQueen(int n)
{
    int a[100];
    int i;

    for (i = 0; i < n; i++)
    {
        a[i] = i;
    }
    //return QueenDo(a, 0, n);
    return simp(a, 0, n);
}
int simp(int *a, int index, int n)
{
    int i;
    static int count = 0;

    if (index >= n)
    {
        count++;
    } else
    {
        for (i = 0; i < n; i++)
        {
            a[index] = i;
            if (!isSafe(a, index))
                continue;
            simp(a, index+1, n);
        }
    }
    return count;
}
