#include <stdio.h>
#include <limits.h>

/*求与数组有关的问题*/


/*求数组中和最大的字串，返回最大的和
*这个解法的时间复杂度为O(n^2)*/
int MaxSumInArray(int *array, int len)
{
    int Max, sum, i, j;

    Max = INT_MIN;
    for (i = 0; i < len; i++)
    {
        sum = 0;
        for ( j = i; j < len; j++)
        {
            sum += array[j];
            if (sum > Max)
                Max = sum;
        }
    }

    return Max;
}


/*求数组中和最大的字串，返回最大的和
*这个解法的时间复杂度为O(n)
这个解比上面的解来的好，只需扫描一次即可
这个算法同时指出循环数组*/
int MaxSumInArray01(int *array, int len)
{
    int Max, sum, i, begin;

    Max = INT_MIN;
    for (i = sum = 0; i < len*2 && i < len + begin; i++)
    {
        sum += array[i%len];
        if (sum > Max)
            Max = sum;
        if (sum <= 0)
        {
            sum = 0;
            begin = i;
        }
    }

    return Max;
}
