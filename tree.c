#include <stdio.h>
//关于树的一些练习
typedef struct btNode
{
    int data;
    struct btNode *lchild, *rchild;
} btNode, *BiTree;

BiTree CreateBiTree()
{
    char ch;
    BiTree T;
    scanf(" %c",&ch);
    if(ch=='#')T=NULL;
    else
    {
        T = (BiTree)malloc(sizeof(btNode));
        T->data = ch;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
    }
    return T;
}
void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        printf("%c",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void TreeOfMirror(BiTree T)
{
    BiTree stack[100], current, tmp;
    int top = -1;

    if (T != NULL)
        stack[++top] = T;
    while (top != -1)
    {
        current = stack[top--];
        if (current->lchild != NULL)
            stack[++top] = current->lchild;
        if (current->rchild != NULL)
            stack[++top] = current->rchild;
        tmp = current->lchild;
        current->lchild = current->rchild;
        current->rchild = tmp;
    }
}

int TreeDeep(BiTree T)
{
    int leftDeep, rightDeep;

    if (T == NULL)
        return 0;
    leftDeep = TreeDeep(T->lchild) + 1;
    rightDeep = TreeDeep(T->rchild) + 1;
    return leftDeep>rightDeep? leftDeep:rightDeep;
}

int TreeMaxRoad(BiTree T)
{
    int leftDeep, rightDeep;
    static int Max = 0;

    if (T == NULL)
        return 0;
    leftDeep = TreeDeep(T->lchild) + 1;
    rightDeep = TreeDeep(T->rchild) + 1;
    if (leftDeep + rightDeep - 1 > Max)
        Max = leftDeep + rightDeep - 1;

    return Max;
}

int PrintNodeAtLevel(BiTree T, int level)
{
    if (!T || level < 0)
        return 0;
    if (level == 0)
    {
        printf("%c\n", T->data);
        return 1;
    }
    return (PrintNodeAtLevel(T->lchild, level-1) + PrintNodeAtLevel(T->rchild, level-1));
}
#define N 100
int PrintAllLevel(BiTree root)
{
    BiTree sequence[N];
    int start, end, last;

    if (root == NULL)
        return 0;

    start = -1;
    end = last = 0;
    sequence[end++] = root;
    while (++start <= end - 1)
    {
        if (sequence[start]->lchild != NULL)
            sequence[end++] = sequence[start]->lchild;
        if (sequence[start]->rchild != NULL)
            sequence[end++] = sequence[start]->rchild;
        printf("%c ", sequence[start]->data);
        if (start == last)
        {
            printf("\n");
            last = end - 1;
        }
    }
}



