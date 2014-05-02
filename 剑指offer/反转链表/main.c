#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    //freopen("test.txt", "r", stdin);
    int count, i;
    struct node *head, *cur, *tmp;

    while (scanf("%d", &count) != EOF)
    {
        if (!count)
        {
            printf("NULL\n");
            continue;
        }
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

        //·´×ªÁ´±í
        cur = head->next;
        head->next = NULL;
        while (cur)
        {
            tmp = cur;
            cur = cur->next;
            tmp->next = head;
            head = tmp;
        }
        cur = head;
        while (cur->next)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("%d", cur->data);
        printf("\n");
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
Problem: 1518
User: lintingbin2009
Language: C
Result: Accepted
Time:160 ms
Memory:912 kb
 ****************************************************************/
