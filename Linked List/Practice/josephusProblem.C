#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} node;

node *createCircularLL(node *head, int a, int n)
{
    if (a > n)
        return head;

    node *curr = (node *)malloc(sizeof(node));
    curr->val = a;
    curr->next = createCircularLL(head, ++a, n);
    return curr;
}


node *removeHead(node *head)
{

    // find the tail
    node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }

    // drop the head
    node *temp = head->next;
    free(head);

    // return new head and link the tail with it
    head = temp;
    curr->next = head;
    return head;
}

node *removeAnyNode(node *head, node *pos)
{
    if (head->next == head) 
    {
        free(head);
        return NULL;
    }

    if (pos == head)
    {
        return removeHead(head);
    }

    // find out the pos
    node *curr = head;
    while (curr->next != pos)
    {
        curr = curr->next;
    }

    node *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);

    return head;
}

node *safestPlace (node *head, int k, int n)
{
    if(head->next == head) return head;
    node *curr = head, *temp = head;
    int pos = 1;
    while(n > 1)
    {
        node *t = curr->next;
        if(pos % k == 0)
        {
            temp = removeAnyNode(temp, curr);  
            n--;
        }
        curr = t;
        pos++;
    }
    return curr;
}

void display(node *head)
{
    if(head == nullptr) 
        printf("\nLL is vacent");
    
    printf("\nDisplay of the LL: \n");
    node *curr = head;
    while (curr->next != head)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }

    printf("%d %d", curr->val, curr->next->val);
}

int main()
{
    int k, n;
    printf("\nNumber of skips: ");
    scanf("%d", &k);
    printf("\nNumber of players: ");
    scanf("%d", &n);

    node *head = (node *)malloc(sizeof(node));
    head->val = 1;
    head->next = createCircularLL(head, 2, n);
    
    int win = safestPlace(head, k, n)->val;
    printf("\nHence the safest place in the game is: %d", win);
}