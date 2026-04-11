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

Node *sortWithConstSpace(Node *head)
{
    Node *curr = head;
    int count0, count1, count2;
    while(curr != nullptr)
    {
        if(curr->val == 0) count0++;
        else if(curr->val == 1) count1++;
        else count2++;
    }

    curr = head;
    while(count0)
    {
        curr->val = 0;
        curr = curr->next;
        count0--;
    }
    while(count1)
    {
        curr->val = 1;
        curr = curr->next;
        count1--;
    }
    while(count2)
    {
        curr->val = 2;
        curr = curr->next;
        count2--;
    }

    return head;
}


Node *sortWithNSpace(Node *head)
{
    Node *newHead = nullptr, *newList;
    while(head != nullptr)
    {
        // Create new node for each of the nodes of the given LL and find its correct position
        int x = head->val;
        Node *curr = new Node(x);

        // newHead = null => list is null => create the head
        if(newHead == nullptr) 
        {
            newHead = curr;
        }
        
        // Check if the current node is lesser than the head replace it
        else if(x <= newHead->val)
        {
            curr->next = newHead;
            newHead = curr;
        }
        
        // Insert in the of the LL finding correct place
        else
        {
            while(newList->next != nullptr && x > newList->next->val)
            {
                newList = newList->next;
            }
            
            curr->next = newList->next;
            newList->next = curr;
        }
        
        newList = newHead;
        head = head->next;
    }

    return newHead;
}

int main()
{
    Node *head = createLinkedList();
    cout << "Linked list is created at: " << head;
    cout << endl << "Display of the linked list: " << endl;
    display(head);
    head = sortWithNSpace(head);
    cout << endl << "Sorted LL: " << endl;
    display(head);
}
