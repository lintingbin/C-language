#include <stdio.h>

#define N 15

char num[N];

int main()
{
    //freopen("test.txt", "r", stdin);

    int cnt, i, j, tmp, flag;
    while(scanf("%d", &cnt) != EOF && cnt != 0)
    {
        memset(num, 0, N);
        for (i = 0; i < cnt; i++)
        {
            scanf("%d", &tmp);
            num[tmp]++;
        }
        for (i = 1; i < N; i++)
            if (num[i] != 0)
                break;
        flag = 1;
        for (j = 0; j < cnt; j++, i++)
        {
            if (num[i] > 1 || (num[i] == 0 && num[0] == 0))
                flag = 0;
            if (num[i] == 0 && num[0] > 0)
            {
                num[i]++;
                num[0]--;
            }
        }
        if (flag == 1)
            printf("So Lucky!\n");
        else
            printf("Oh My God!\n");
    }
    return 0;
}

/**************************************************************
    Problem: 1355
    User: lintingbin2009
    Language: C
    Result: Wrong Answer
****************************************************************/
