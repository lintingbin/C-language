#include <stdio.h>
typedef struct btNode
{
    int data;
    struct btNode *lchild, *rchild;
}btNode, *BiTree;

int main()
{
    BiTree tree;

    tree = CreateBiTree();
    printf("%d ",TreeMaxRoad(tree));

    return 0;
}
