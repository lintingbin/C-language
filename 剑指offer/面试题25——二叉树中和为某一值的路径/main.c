#include <stdio.h>
#define N 10001
 
struct node {
    int data;
    int lchild;
    int rchild;
};
 
struct node input[N];
int path[N];
 
void pre_order(int n, int k, int count)
{
    int i, tmp;
    if (n == 1)
        path[count] = 1;
    k -= input[n].data;
    if (k < 0)
        return;
    if ((input[n].lchild) == -1 && (input[n].rchild) == -1 && 0 == k)
    {
        printf("A path is found:");
        for (i = 1; i <= count; i++)
            printf(" %d", path[i]);
        printf("\n");
    }
    if (input[n].lchild > input[n].rchild)//小的要先输出
    {
        tmp = input[n].lchild;
        input[n].lchild = input[n].rchild;
        input[n].rchild = tmp;
    }
 
    if (input[n].lchild != -1)
    {
        path[count+1] = input[n].lchild;
        pre_order(input[n].lchild, k, count+1);
    }
    if (input[n].rchild != -1)
    {
        path[count+1] = input[n].rchild;
        pre_order(input[n].rchild, k, count+1);
    }
}
 
int main()
{
    //freopen("/home/lintingbin/test.txt", "r", stdin);
    int n, k, i;
 
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (i = 1; i <= n; i++)
            scanf("%d%d%d", &(input[i].data), &(input[i].lchild), &(input[i].rchild));
        printf("result:\n");
        if (n > 0)
            pre_order(1, k, 1);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1368
    User: lintingbin2009
    Language: C
    Result: Accepted
    Time:30 ms
    Memory:1068 kb
****************************************************************/
