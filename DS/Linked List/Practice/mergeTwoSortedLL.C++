

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
    Node *next;
    Node(int x)
    {
        next = nullptr;
        val = x;
    }
};

Node *createLinkedList()
{
    int x;
    cout << "Enter element: ";
    cin >> x;

    if(x == -1) return nullptr;
    Node *head = new Node(x);
    head->next = createLinkedList();
    
    return head;
}

void display(Node *head)
{
    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

Node *merge(Node *h1, Node *h2)
{
    if((h1 == nullptr && h2 == nullptr) || (h1 != nullptr && h2 == nullptr)) return h1;
    if(h1 == nullptr && h2 != nullptr) return h2;

    Node *head, *curr, *curr1, *curr2;
    head = curr = curr1 = curr2 = nullptr;
    if(h1->val <= h2->val)
    {
        head = h1;
        curr1 = h1->next;
        curr2 = h2;
    }
    else
    {
        head = h2;
        curr1 = h1;
        curr2 = h2->next;
    }

    curr = head;
    while(curr1 != nullptr && curr2 != nullptr)
    {
        if(curr1->val <= curr2->val)
        {
            curr->next = curr1;
            curr = curr1;
            curr1 = curr1->next;
        }

        else
        {
            curr->next = curr2;
            curr = curr2;
            curr2 = curr2->next;
        }
    }

    while(curr1 != nullptr)
    {
        curr->next = curr1;
        curr = curr1;
        curr1 = curr1->next;
    }

    while(curr2 != nullptr)
    {
        curr->next = curr2;
        curr = curr2;
        curr2 = curr2->next;
    }

    return head;
}



int main()
{
    cout <<endl << "Linked list 1" << endl;
    Node *head1 = createLinkedList();
    cout << "Linked list is created at: " << head1;
    cout << endl << "Display of the linked list: " << endl;
    display(head1);
    cout <<endl << "Linked list 2" << endl;
    Node *head2 = createLinkedList();
    cout << "Linked list is created at: " << head2;
    cout << endl << "Display of the linked list: " << endl;
    display(head2);
    head1 = merge(head1, head2);
    cout << endl << "Merged linked list: " << endl;
    display(head1);

    delete head1;
    delete head2;
}
