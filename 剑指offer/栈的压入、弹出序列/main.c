#include <stdio.h>
#define N 100001
int stack[N], input[N];
 
int main()
{
    //freopen("/home/lintingbin/test.txt", "r", stdin);
    int n, i, j, top, tmp, Yes;
 
    while (scanf("%d", &n) != EOF)
    {
        Yes = 1;
        top = -1;
        for (i = 0; i < n; i++)
            scanf("%d", &input[i]);
        for (i = j = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            if (tmp == input[j] && j < n)
            {
                j++;
                continue;
            }
            if (stack[top] == tmp && top > -1)
            {
                top--;
                continue;
            }
            while (stack[top] != tmp && j < n)
                stack[++top] = input[j++];
            if (j >= n-1 && stack[top] != tmp)
            {
                Yes = 0;//这里不能加break，不然就不能吸收全部的数
            }
            if (stack[top] == tmp)
                top--;
        }
        if (Yes)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
/**************************************************************
    Problem: 1366
    User: lintingbin2009
    Language: C++
    Result: Accepted
    Time:190 ms
    Memory:1800 kb
****************************************************************/
