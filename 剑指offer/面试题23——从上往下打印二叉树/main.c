#include <stdio.h>
#define N 1001

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
void level_order(struct node* tree, int n)
{
    struct node *quence[N], *tmp;
    int head, tail;

    tail = -1;
    head = 0;
    if (tree == NULL)
        return;
    quence[head++] = tree;
    while (tail < head - 1)
    {
        n--;
        tmp = quence[++tail];
        if (tmp->lchild != NULL)
            quence[head++] = tmp->lchild;
        if (tmp->rchild != NULL)
            quence[head++] = tmp->rchild;
        if(n)
            printf("%d ", tmp->data);
        else
            printf("%d", tmp->data);
    }
}

int main()
{
    //freopen("/home/lintingbin/test.txt", "r", stdin);
    int n, i, tmp;
    char opt;
    struct node *input[N];

    while (scanf("%d", &n) != EOF)
    {
        if (n < 1)
        {
            printf("NULL\n");
            continue;
        }
        for (i = 0; i < n; i++)
        {
            input[i] = malloc(sizeof(struct node));
            scanf("%d", &(input[i]->data));
        }
        for (i = 0; i < n; i++)
        {
            scanf(" %c", &opt);
            switch (opt)
            {
                case 'd':
                    scanf("%d", &tmp);
                    input[i]->lchild = input[tmp-1];
                    scanf("%d", &tmp);
                    input[i]->rchild = input[tmp-1];
                    break;
                case 'l':
                    scanf("%d", &tmp);
                    input[i]->lchild = input[tmp-1];
                    input[i]->rchild = NULL;
                    break;
                case 'r':
                    scanf("%d", &tmp);
                    input[i]->rchild = input[tmp-1];
                    input[i]->lchild = NULL;
                    break;
                case 'z':
                    input[i]->rchild = NULL;
                    input[i]->lchild = NULL;
                    break;
            }
        }
        level_order(input[0], n);
        printf("\n");
    }
    return 0;
}
/**************************************************************
Problem: 1523
User: lintingbin2009
Language: C
Result: Accepted
Time:0 ms
Memory:912 kb
 ****************************************************************/
