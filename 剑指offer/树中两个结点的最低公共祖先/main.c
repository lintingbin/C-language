#include <stdio.h>

#define N 10001

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}Node, *tree;

tree Create()
{
    int tmp;
    Node *tmpNode;

    scanf("%d", &tmp);
    if (tmp == 0)
        return NULL;
    tmpNode = malloc(sizeof(Node));
    tmpNode->data = tmp;
    tmpNode->lchild = Create();
    tmpNode->rchild = Create();
    return tmpNode;
}

int getPath(tree root, int m, int *stack, int *top)
{
    if (root == NULL)
        return 0;
    stack[++(*top)] = root->data;
    if (root->data != m)
    {
        if (getPath(root->lchild, m, stack, top) || getPath(root->rchild, m, stack, top))
            return 1;
        else
        {
            (*top)--;
            return 0;
        }
    } else{
        return 1;
    }
}

int stack1[N], top1, stack2[N], top2;

int main()
{
    //freopen("test.txt", "r", stdin);

    int cnt, i, j, num1, num2;
    tree root;
    while (scanf("%d", &cnt) != EOF)
    {
        for (i = 0; i < cnt; i++)
        {
            root = Create();
            scanf("%d%d", &num1, &num2);
            top1 = top2 = -1;
            if (getPath(root, num1, stack1, &top1) && getPath(root, num2, stack2, &top2))
            {
                if (top1 > top2)
                    top1 = top2;
                for (j = top1; j >= 0; j--)
                {
                    if (stack1[j] == stack2[j])
                    {
                        printf("%d\n", stack1[j]);
                        break;
                    }
                }
            }
            else
                printf("My God\n");
        }
    }
    return 0;
}

/**************************************************************
    Problem: 1509
    User: lintingbin2009
    Language: C
    Result: Accepted
    Time:140 ms
    Memory:4820 kb
****************************************************************/
