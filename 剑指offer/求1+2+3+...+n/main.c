#include <stdio.h>

typedef unsigned int (*fun)(int n);

unsigned int over(int n)
{
    return 0;
}

//解题思路主要是用函数指针的方法，当n为0时!n刚好为1，这是一个小技巧。
unsigned int factorial(int n)
{
    fun function[2] = {factorial, over};
    return n + function[!n](n - 1);
}

int main()
{
    //freopen("test.txt", "r", stdin);

    unsigned int n;
    while (scanf("%u", &n) != EOF)
    {
        printf("%u\n", factorial(n));
    }
    return 0;
}

/**************************************************************
    Problem: 1506
    User: lintingbin2009
    Language: C
    Result: Accepted
    Time:360 ms
    Memory:1208 kb
****************************************************************/
