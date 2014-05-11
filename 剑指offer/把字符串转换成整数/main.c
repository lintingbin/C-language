#include <stdio.h>
#include <string.h>

#define N 10

char num[N];
int error;

int antoi(char *num)
{
    int len = strlen(num), i = 0, flag = 1, result = 0;

    error = 0;
    if(num == NULL)
    {
        error = 1;
        return -1;
    }
    if (num[i] == '+' || num[i] == '-')
    {
        flag = (num[i]=='+')? 1:-1;
        i++;
    }

    for (; i < len; i++)
    {
        if (num[i]>='0' && num[i]<='9')
            result = result*10 + num[i] - '0';
        else
        {
            error = 1;
            break;
        }
    }
    return result * flag;
}
int main()
{
    //freopen("test.txt", "r", stdin);

    int result;
    while (scanf("%s", num) != EOF)
    {
        result = antoi(num);
        if (!error)
            printf("%d\n", result);
        else
            printf("My God\n");
    }
    return 0;
}

/**************************************************************
    Problem: 1508
    User: lintingbin2009
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:912 kb
****************************************************************/
