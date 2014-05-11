#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 101

int input[N];

int cmp(const void *a, const void *b)//比较两个数，看哪个数放在前面数会比较小
{
    char str1[20], str2[20], tmp[20];

    sprintf(str1, "%d", *(int*)a);
    sprintf(str2, "%d", *(int*)b);
    strcpy(tmp, str1);
    strcat(str1, str2);
    strcat(str2, tmp); 
    return strcmp(str1, str2);
}

int main()
{
    //freopen("/home/lin/test.txt", "r", stdin);
    int n, i;

    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++)
            scanf("%d", &input[i]);
        qsort(input, n, sizeof(input[0]), cmp);
        for (i = 0; i < n; i++)
            printf("%d", input[i]);
        printf("\n");
    }
    return 0;
}
