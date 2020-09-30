#include <stdio.h>
//单链表的一些练
#An amazing project#
typedef struct listNode
{
    int data;
    struct listNode *next ;
}listNode,*list;

list CreateList(int *str, int len)
{
    int i;
    listNode *head, *node, *tmp;

    if (str == NULL || len == 0)
        return NULL;
    head = (list)malloc(sizeof(listNode));
    head->next = NULL;
    for (i = 0; i < len - 1; i++)
    {
        node = (list)malloc(sizeof(listNode));
        node->data = str[i];
        tmp = head->next;
        head->next = node;
        node->next = tmp;

    }
    head->data = str[i];
    return head;
}
list reverseList(list l)
{
    list head, tmp;

    head = tmp = NULL;
    while (l != NULL)
    {
        tmp = head;
        head = l;
        l = l->next;
        head->next = tmp;
    }
    return head;
}

void printList(list head)
{
    if (head == NULL)
        return;

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

list mergeList(list a, list b)
{
    list head = NULL;

    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a->data > b->data)
    {
        head = a;
        head->next = mergeList(a->next, b);
    }
    else
    {
        head = b;
        head->next = mergeList(a, b->next);
    }
    return head;
}
