#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct listNode
{
    int data;
    struct listNode *next ;
}listNode,*list;

typedef struct btNode
{
    int data;
    struct btNode *lchild, *rchild;
}btNode, *BiTree;



#endif // HEADER_H_INCLUDED
