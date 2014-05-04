#include<stdio.h>
#include<string.h>
#define N 100
#define MAX 10000


int main()
{
    //freopen("/home/lin/test.txt", "r", stdin);
    char input[MAX], ascii[N];
    int len, find, i;

    while (scanf("%s", input) != EOF) {
        find = 0;
        memset(ascii, 0, 100);
        len = strlen(input);
        for (i = 0; i < len; i++)
            ascii[input[i]]++;
        for (i = 0; i < len; i++) {
            if (ascii[input[i]] == 1) {
                printf("%d\n", i);
                find = 1;
                break;
            }
        }
        if (!find)
            printf("%d\n", -1);
    }
    return 0;
}
