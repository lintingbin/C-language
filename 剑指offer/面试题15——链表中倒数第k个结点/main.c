#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    //freopen("test.txt", "r", stdin);
    int count, pos, i;
    struct node *head, *cur, *tmp;

    while (scanf("%d %d", &count, &pos) != EOF)
    {
        if (pos > count)
            pos = 0;
        head = malloc(sizeof(struct node));
        scanf("%d", &(head->data));
        cur = head;
        for (i = 0; i < count-1; i++)
        {
            cur->next = malloc(sizeof(struct node));
            cur = cur->next;
            scanf("%d", &(cur->data));
        }
        cur->next = NULL;
        tmp = cur = head;
        for (i = 0; i < pos && tmp != NULL; i++)
        {
            tmp = tmp->next;
        }
        while (tmp)
        {
            cur = cur->next;
            tmp = tmp->next;
        }
        if (cur)
            printf("%d\n", cur->data);
        else
            printf("NULL\n");
        while (head)
        {
            cur = head;
            head = head->next;
            free(cur);
        }
    }
    return 0;
}

/**************************************************************
Problem: 1517
User: lintingbin2009
Language: C
Result: Accepted
Time:100 ms
Memory:912 kb
 ****************************************************************/
