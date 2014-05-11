#include <stdio.h>
#include <limits.h>
#define N 1000000
int stack[N];
int stackMin[N];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, top, i;
    char opt;

    while (scanf("%d", &n) != EOF)
    {
        top = -1;
        for (i = 0; i < n; i++)
        {
            scanf(" %c", &opt);
            if (opt == 's')
            {
                scanf("%d", &stack[++top]);
                if(top == 0)
                    stackMin[top] = stack[top];
                else if (stack[top] < stackMin[top-1])
                    stackMin[top] = stack[top];
                else
                    stackMin[top] = stackMin[top-1];
            }
            else
            {
                if (top < 1)
                {
                    //小细节要注意到，虽然刚开始不为空
                    if (top == 0)
                        top--;
                    printf("NULL\n");
                    continue;
                }
                else
                    top--;
            }
            printf("%d\n", stackMin[top]);
        }
    }
    return 0;
}

/**************************************************************
Problem: 1522
User: lintingbin2009
Language: C
Result: Accepted
Time:20 ms
Memory:8724 kb
 ****************************************************************/
