#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} node;

node *createCircularLL(node *head)
{
    int x;
    printf("\nEnter element: ");
    scanf("%d", &x);
    if (x == -1)
        return head;

    node *curr = (node *)malloc(sizeof(node));
    curr->val = x;
    curr->next = createCircularLL(head);
    return curr;
}

node *insertAtFr(node *head)
{
    int x;
    printf("\nEnter element you want to insert: ");
    scanf("%d", &x);

    // find the tail
    node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }

    // create new head
    node *temp = (node *)malloc(sizeof(node));
    temp->val = x;
    temp->next = head;
    head = temp;

    // link the new head with the tail
    curr->next = head;

    return head;
}

node *insertBetween(node *head, int pos1)
{
    int x;
    printf("Enter element: ");
    scanf("%d", &x);

    // find out the pos
    int i = 1;
    node *curr = head;
    while (i < pos1)
    {
        curr = curr->next;
        i++;
    }

    // create new node
    node *temp = curr->next;
    curr->next = (node *)malloc(sizeof(node));
    curr->next->val = x;
    curr->next->next = temp;

    return head;
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

node *removeAnyNode(node *head, int pos)
{
    if (head->next == head) return nullptr;
    if (pos == 1)
    {
        return removeHead(head);
    }

    // find out the pos
    int i = 1;
    node *curr = head;
    while (i < pos - 1)
    {
        curr = curr->next;
        i++;
    }

    node *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);

    return head;
}


node *sort(node *head)
{
    node *curr = head; 
    for(node *curr = head; curr->next != head; curr=curr->next)
    {
        node *min = curr;
        for(node *next = curr->next; next != head; next = next->next)
        {
            if(min->val > next->val)
            {
                min = next;
            }
        }
        int temp = curr->val;
        curr->val = min->val;
        min->val = temp; 
    }

    return head;
}

node *reverse(node *head)
{
    node *prev=NULL, *curr =head, *fut = curr->next;
    while(fut != head)
    {
        curr->next = prev;
        prev=curr;
        curr=fut;
        fut=curr->next;
    }

    head->next = curr;
    curr->next=prev;
    head = curr;
    return head;
}


void *display(node *head)
{
    if(head == NULL) 
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
    int x;
    printf("\nCreate a head: ");
    scanf("%d", &x);

    node *head = (node *)malloc(sizeof(node));
    head->val = x;
    head->next = createCircularLL(head);
    printf("\nHead: %d", head->val);

    printf("\n1. Display 2. Insert At Front 3. Insert Between 4. Delete Any Node With Node Index 5. Sort 6. Reverse 7. Exit");
    int f;
    printf("\nEnter your choice: ");
    scanf("%d", &f);

    while (f != 7)
    {
        if (f == 1)
            display(head);
        else if (f == 2)
            head = insertAtFr(head);
        else if (f == 3)
        {
            int p;
            printf("\nEnter position: ");
            scanf("%d", &p);
            head = insertBetween(head, p);
        }
        else if (f == 4)
        {
            int p;
            printf("\nEnter position: ");
            scanf("%d", &p);
            head = removeAnyNode(head, p);
        }
        else if (f == 5)
        {
            head = sort(head);
            printf("\nSorted successfully!");
        }
        else if (f == 6)
        {
            head = reverse(head);
            printf("\nReversed successfully!");
        }
        else
            break;

        printf("\nEnter your choice: ");
        scanf("%d", &f);
    }
}