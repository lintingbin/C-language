#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 200001

int input[N];
int stack[N];

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void max_heapify(int *array, int index, int size) //保持大跟堆的性质
{
    int l, r, largest;

    l = index*2;
    r = index*2 + 1;
    if (l <= size && array[l] > array[index])
        largest = l;
    else
        largest = index;
    if (r <= size && array[r] > array[largest])
        largest = r;
    if (largest != index)
    {
        swap(&array[largest], &array[index]);
        max_heapify(array, largest, size);
    }
}

void create_heap(int *array, int size)  //建立大根堆
{
    int i;

    for (i = size/2; i >= 1; i--)
    {
        max_heapify(array, i, size);
    }
}

int main()
{
    //freopen("/home/lintingbin/test.txt", "r", stdin);
    int i, n, k, top;
    
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (i = 1; i <= n; i++)
            scanf("%d", &input[i]);
        create_heap(input, k);
        for (i = k + 1; i <= n; i++)
        {
            if (input[i] < input[1])
            {
            input[1] = input[i];
            max_heapify(input, 1, k);
            }
        }

        top = -1;
        for (i = k; i >= 1; i--)
        {
            stack[++top] = input[1];
            input[1] = input[i];
            max_heapify(input, 1, i-1);
        }

        while (top != 0)
            printf("%d ", stack[top--]);
        printf("%d", stack[top--]);

        printf("\n");
    }

    return 0;
}

