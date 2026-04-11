#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *prev, *next;

    Node(int x)
    {
        val = x;
        prev = next = NULL;
    }
};

Node *createDoublyLL(Node *prev)
{
    int x;
    printf("Enter x: ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    Node *head = new Node(x);
    head->prev = prev;
    head->next = createDoublyLL(head);
    return head;
}

void display (Node *head)
{
    Node *curr = head;
    while(curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
}

Node *middle(Node *head, Node *tail)
{
    Node *slw = head, *fast = head;
    while(fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slw = slw->next;
    }
    return slw;
}

void merge(Node *h, Node *m, Node *t)
{
    Node *lS = h, *lE = m->prev, *rS = m, *rE = t, *temp = new Node(-1), *itr = temp;

    while (lS != lE && rS != rE)
    {
        if (lS->val < rS->val)
        {
            itr->next = new Node(lS->val);
            lS = lS->next;
        }
        else
        {
            itr->next = new Node(rS->val);
            rS = rS->next;
        }
        itr = itr->next;
    }

    while (lS != lE)
    {
        itr->next = new Node(lS->val);
        lS = lS->next;
        itr = itr->next;
    }

    while (rS != rE)
    {
        itr->next = new Node(rS->val);
        rS = rS->next;
        itr = itr->next;
    }

    // record back to the real list
    Node *curr = h, *currT = temp->next;
    while(currT != NULL)
    {
        curr->val = currT->val;
        curr = curr->next;
        currT = currT->next;
    }
}


void mergeSort (Node *head, Node *tail)
{
    if(head == tail || head == NULL || tail == NULL) return;

    Node *mid = middle(head, tail);

    mergeSort(head, mid->prev);
    mergeSort(mid, tail);

    merge(head, mid, tail);
}

void sortLL (Node *head)
{
    Node *tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    mergeSort(head, tail);
}

int main ()
{
    Node *list = createDoublyLL(NULL);
    cout << "Linked list: " << endl;
    display(list);
    sortLL(list);
    cout << "After merge sort: " << endl;
    display(list);
}