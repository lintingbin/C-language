#include <stdio.h>
#define N 200001

int input[N];

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int *array, int start, int end)
{
    int i, j;

    if (start > end)
        return;
    j = start - 1;
    for (i = start; i < end; i++)
    {
        if (array[i] < array[end])
        {
            swap(&array[++j], &array[i]);
        }
    }
    swap(&array[++j], &array[end]);

    quick_sort(array, start, j-1);
    quick_sort(array, j+1, end);
}
void find_k(int *array, int start, int end, int k) //由上面的快速排序来改造
{
    int i, j;

    if (start > end)
        return;
    j = start - 1;
    for (i = start; i < end; i++)
    {
        if (array[i] < array[end])
        {
            swap(&array[++j], &array[i]);
        }
    }
    swap(&array[++j], &array[end]);
    if (j == k-1)
        return;
    else if (j > k-1)
        find_k(array, start, j-1, k);
    else
        find_k(array, j+1, end, k-j-1);
}

int main()
{
    //freopen("/home/lintingbin/test.txt", "r", stdin);
    int i, n, k;
    
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &input[i]);
        find_k(input, 0, n-1, k+1);
        quick_sort(input, 0, k-1);
        for (i = 0; i < k - 1; i++)
            printf("%d ", input[i]);
        if (k > 0)
            printf("%d", input[k-1]);
        printf("\n");
    }

    return 0;
}

