#include <stdio.h>

int main()
{
    //freopen("test.txt", "r", stdin);
    int count;
    long long max, num;

    while (scanf("%d", &count) != EOF)
    {
        max = num = 1;
        while (count--)
        {
            max *=10;
        }
        while (--max)
            printf("%lld\n", num++);

    }
    return 0;
}
/**************************************************************
Problem: 1515
User: lintingbin2009
Language: C
Result: Accepted
Time:40 ms
Memory:912 kb
 ****************************************************************/
