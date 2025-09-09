#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
} node;

node *createDoublyLL (node *prev)
{
    int x;
    printf("Enter x: ");
    scanf("%d", &x);

    if (x == -1) return NULL;

    node *head = (node *) malloc(sizeof(node));
    head->val = x;
    head->prev = prev;
    head->next=createDoublyLL(head);

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

    // return new head and link the head with null
    head = temp;
    head->prev=NULL;
    return head;
}

node *removeAnyNode(node *head, int pos)
{
    if (head->next == NULL) 
    {
        free(head);
        return NULL;
    }

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
    curr->next = temp->next;
    temp->next->prev = curr;
    free(temp);

    return head;
}

node *insertAtFr(node *head)
{
    int x;
    printf("Enter element: ");
    scanf("%d", &x);

    node *temp = (node *)malloc(sizeof(node));
    temp->val = x;
    temp->next = head;
    temp->prev = NULL;
    temp->next->prev = temp;
    head = temp;

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
    curr->next->prev = curr;

    return head;
}

node *reverse(node *head)
{
    // find the tail
    node *curr = head, *th = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    // reverse
    node *tail = curr;
    while(tail != head)
    {
        int temp = head->val;
        head->val = tail->val;
        tail->val = temp;

        head = head->next;
        tail = tail->prev;
    }

    printf("\nReversed successfully !!");
    return th;
}

void display(node *head)
{
    printf("\nDisplay: \n");
    node *curr = head;
    while(curr != NULL)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
}

int main()
{
    node *head = createDoublyLL(NULL);
    
    printf("\n1. Display 2. Insert At Front 3. Insert Between 4. Delete Any Node With Node Index 5. Reverse 7. Exit");
    int f;
    printf("\nEnter your choice: ");
    scanf("%d", &f);

    while (f != 7)
    {
        if (f == 1)
            display(head);
        else if (f == 5)
            head = reverse(head);
        else
            break;

        printf("\nEnter your choice: ");
        scanf("%d", &f);
    }
}