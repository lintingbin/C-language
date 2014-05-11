#include <stdio.h>
#define N 1001
int CanBiCreate;
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node * reCreate(int *pre_order, int *mid_order, int count)
{
    struct node *root;
    int subCount = 0;

    if (count < 1)
        return NULL;
    while (*pre_order != *(mid_order+subCount))
    {
        subCount++;
        if (subCount >= count)
        {
            CanBiCreate = 0;
            return NULL;
        }
    }
    root = malloc(sizeof(struct node));
    root->data = *pre_order;
    root->lchild = reCreate(pre_order+1, mid_order, subCount);
    root->rchild = reCreate(pre_order+subCount+1, mid_order+1+subCount, count-subCount-1);
    return root;
}
void succ_order(struct node *tree)
{
    if (tree == NULL)
        return;
    succ_order(tree->lchild);
    succ_order(tree->rchild);
    printf("%d ", tree->data);
}
int main()
{
    //freopen("test.txt", "r", stdin);
    int count, pre_order[N], mid_order[N];
    int i;
    struct node *tree;

    while (scanf("%d", &count) != EOF)
    {
        for (i = 0; i < count; i++)
        {
            scanf("%d", &pre_order[i]);
        }
        for (i = 0; i < count; i++)
        {
            scanf("%d", &mid_order[i]);
        }
        CanBiCreate = 1;
        tree = reCreate(pre_order, mid_order, count);
        if (CanBiCreate)
            succ_order(tree);
        else
            printf("No");
        printf("\n");
    }
    return 0;
}

/**************************************************************
Problem: 1385
User: lintingbin2009
Language: C
Result: Accepted
Time:0 ms
Memory:912 kb
****************************************************************/
