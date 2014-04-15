#include <stdio.h>
//约瑟夫环的数学实现方法
int Joseph_ring_recurse(int n, int m)
{
    if (n == 1 && m > 0)
        return 0;
    if (n > 1 && m > 0)
    {
        return (Joseph_ring_recurse(n - 1, m) + m) % n;
    }

    return -1;
}
int Joseph_ring(int n, int m)
{
    int i, init = 0;

    if (n <= 0 || m <= 0)
        return -1;
    for (i = 2; i <= n; i++)
    {
        init = (init + m) % i;
    }

    return init;
}
