#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

int main()
{
    freopen("test.txt", "r", stdin);
    int input;
    struct node *head, *cur, *tmp;

    head = (struct node *)malloc(sizeof(struct node));
    cur = head;
    scanf("%d", &input);
    while (input != -1)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = input;
        tmp->next = NULL;
        cur->next = tmp;
        cur = cur->next;
        scanf("%d", &input);
    }
    cur = head->next;
    head->next = NULL;
    while (cur)
    {
        tmp = head->next;
        head->next = cur;
        cur = cur->next;
        head->next->next = tmp;
    }
    cur = head->next;
    while (cur)
    {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    return 0;
}
