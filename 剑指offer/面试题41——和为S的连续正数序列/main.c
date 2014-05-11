#include <stdio.h>
#include <math.h>

void show(int a ,int N)
{
    int i;
    for(i=0; i<N; ++i)
    {
        if( i != 0 ) printf(" ");
        printf("%d",a+i);
    }
    printf("\n");
}

int main()
{
    //freopen("test.txt", "r", stdin);

    int S,b,flag, i;
    while(scanf("%d",&S) && S >= 0)
    {
        flag = 0;
        for(i=sqrt(2*S); i>=2; --i)
        {
            if( (2*S) % i == 0 )
            {
                b = 2*S / i - i + 1;

                if( (b&1) == 0 )
                {
                    show( b/2 , i );
                    flag = 1;
                }
            }
        }
        if(flag == 0)
            printf("Pity!\n");
        printf("#\n");
    }
    return 0;
}

/**************************************************************
    Problem: 1354
    User: lintingbin2009
    Language: C
    Result: Accepted
    Time:110 ms
    Memory:928 kb
****************************************************************/
