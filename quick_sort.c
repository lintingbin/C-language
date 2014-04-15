#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//快速排序的随机化版本
void quick_sort(int *a, int s, int d)
{
    int i, j;

    if (s > d)
        return;
    srand(time(NULL));
    i = rand()%(d+1-s) + s;
    swap(&a[i], &a[d]);
    for(i = s - 1, j = s; j < d; j++)
    {
        if (a[j] < a[d])
        {
            swap(&a[++i], &a[j]);
        }
    }
    swap(&a[++i], &a[d]);
    quick_sort(a, s, i-1);
    quick_sort(a, i+1, d);
}
