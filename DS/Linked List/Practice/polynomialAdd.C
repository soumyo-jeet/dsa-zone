#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int cff;
    int ex;
    struct Node *next;
} node;

node *createLL()
{
    int x, y;
    printf("Coefficient: ");
    scanf("%d", &x);
    x = x < 0 ? x * -1 : x;

    printf("Exponent: ");
    scanf("%d", &y);
    if (y == -1)
        return NULL;

    node *curr = (node *)malloc(sizeof(node));
    curr->cff = x;
    curr->ex = y;
    curr->next = createLL();
    return curr;
}

node *add(node *h1, node *h2)
{
    node *h = (node *)malloc(sizeof(node)), *curr = h;
    while (h1 != NULL || h2 != NULL)
    {
        if (h1->ex > h2->ex)
        {
            curr->ex = h1->ex;
            curr->cff = h1->cff;
            h1 = h1->next;
        }
        else if (h1->ex < h2->ex)
        {
            curr->ex = h2->ex;
            curr->cff = h2->cff;
            h2 = h2->next;
        }
        else
        {
            curr->ex = h1->ex;
            curr->cff = h1->cff + h2->cff;
            h1 = h1->next;
            h2 = h2->next;
        }

        // handle last node
        if(h1 == NULL && h2 == NULL)
        {
            curr->next = NULL;
        }
        else
        {
            curr->next = (node *)malloc(sizeof(node));
        }
        curr = curr->next;
    }

    // remaining parts of the h1
    while (h1 != NULL)
    {
        curr->ex = h1->ex;
        curr->cff = h1->cff;
        h1 = h1->next;
        if(h1 == NULL)
        {
            curr->next = NULL;
        }
        else
        {
            curr->next = (node *)malloc(sizeof(node));
        }
        curr = curr->next;
    }

    // remaining parts of the h2
    while (h2 != NULL)
    {
        curr->ex = h2->ex;
        curr->cff = h2->cff;
        h2 = h2->next;
        if(h2->next == NULL)
        {
            curr->next = NULL;
        }
        else
        {
            curr->next = (node *)malloc(sizeof(node));
        }
        curr = curr->next;
    }

    return h;
}

void display(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        printf("%d, %d  |", curr->cff, curr->ex);
        curr = curr->next;
    }
}

int main()
{
    printf("Expression 1: ");
    node *h1 = createLL();
    printf("Expression 2: ");
    node *h2 = createLL();

    node *head = add(h1,h2);
    printf("\nRequired added polynomial: \n");
    display(head);
}