#include <stdio.h>
//关于树的一些练习
typedef struct btNode
{
    int data;
    struct btNode *lchild, *rchild;
}btNode, *BiTree;

BiTree CreateBiTree(){
    char ch;
    BiTree T;
    scanf(" %c",&ch);
    if(ch=='#')T=NULL;
    else{
        T = (BiTree)malloc(sizeof(btNode));
        T->data = ch;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
    }
    return T;
}
void PreOrderTraverse(BiTree T){
    if(T){
       printf("%c",T->data);
       PreOrderTraverse(T->lchild);
       PreOrderTraverse(T->rchild);
    }
}
void TreeOfMirror(BiTree T){
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
