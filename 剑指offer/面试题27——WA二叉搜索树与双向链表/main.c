#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node *CreatTree()
{
    struct node *root = NULL;
    int tmp;

    scanf("%d", &tmp);
    if (tmp != 0)
    {
        root = malloc(sizeof(struct node));
        root->data = tmp;
        root->lchild = CreatTree();
        root->rchild = CreatTree();
    }
    return root;
}
void tree_to_link(struct node *root)
{
    struct node *p, *q;

    if (root != NULL)
    {
        p = root->lchild;
        if (p != NULL && p->rchild != NULL)
            p = p->rchild;
        q = root->rchild;
        if (q != NULL && q->lchild != NULL)
            q = q->lchild;
        tree_to_link(root->lchild);
        tree_to_link(root->rchild);
        if (p != NULL)
        {
            p->rchild = root;
            root->lchild = p;
        }
        if (q != NULL)
        {
            q->lchild = root;
            root->rchild = q;
        }
    }
}

int main()
{
    //freopen("/home/lintingbin/test.txt", "r", stdin);
    int n, i, tmp;
    struct node *tree, *head;

    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            head = tree = CreatTree();
            tree_to_link(tree);
            while (head != NULL && head->lchild != NULL)
                head = head->lchild;
            while (head != NULL)
            {
                printf("%d ", head->data);
                head = head->rchild;
            }
            printf("\n");
        }
    }
    return 0;
}

/**************************************************************
	Problem: 1503
	User: lintingbin2009
	Language: C
	Result: Wrong Answer
****************************************************************/
