#include <stdio.h>

//字符和字符串有关的一些练习
static int count = 0;

void shooting_do(int *a, int index, int len, int score)
{
    int i,j;
    int total = 0;
    if (index > len - 1)
    {
        for (i = 0; i < len; i++)
        {
            total += a[i];
            //printf("%d ", a[i]);
        }
        //printf("\n");
        if (total == score)
            count++;
        return;
    }
    for (i = 0; i <= len; i++)
    {
        a[index] = i;
        for (j = 0; j <= index; j++)
        {
            total += a[j];
        }
        if ((total + (len-1-index)*len) < score)
        {
            total = 0;
            continue;
        }
        shooting_do(a, index+1, len, score);
    }
}

int shooting()  //打靶10次，分数高于90的情况个数
{
    int a[10];
    int len = 10, score = 90;

    shooting_do(a, 0, len, score);
    return count;
}

void combine_do(char *in, char *out, int len, int start, int cur)
{
    int i;

    if (cur == len)
        return;
    for (i = start; i < len; i++)
    {
        out[cur] = in[i];
        out[cur+1] = '\0';
        printf("%s\n", out);
        if (i < len - 1)
            combine_do(in, out, len, start+1, cur+1);
    }
}

int combine()  //字符串字串问题，还没完成，后面再看看
{
    char str[] = "hart";
    char out[100];
    int len = 4;
    combine_do(str, out, len, 0, 0);
}
int bag[100] = {0};
int mVal, nVal;
void bag_01(int m, int n) //0 1背包问题
{
    int i;

    if (n<1||m<1||(n==1&&m!=1))
        return;
    if (n == m)
    {
        bag[n] = 1;
        for (i = 1; i <= nVal; i++)
            if (bag[i] == 1)
                printf("%d ", i);
        printf("\n");
        bag[n] = 0;
    }

    bag[n] = 1;
    bag_01(m - n, n - 1);  //n有加入的情况下
    bag[n] = 0;
    bag_01(m, n-1);   //n没有加入的情况下
}

void call_bag01(int m, int n) //0 1背包调用函数
{
    mVal = m;
    nVal = n;
    bag_01(mVal, nVal);
}
