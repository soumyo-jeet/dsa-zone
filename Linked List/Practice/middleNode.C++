// fast and slow pointer concept -->
//      two pinter will traverse through the whole linked lists but one in x speed (simple travarsal), one with 2x speed (skipping one node)
//      when fast pointer reaches the end node the slow pointer will be at the middle node

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

Node *middleNode(Node *head)
{
    Node *fastptr = head, *slowptr = head;

    while(fastptr != nullptr && fastptr->next != nullptr)
    {
        cout << endl << "slow: " << slowptr->val;
        cout << endl << "fast: " << fastptr->val;
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }

    cout << "middle: " << slowptr->val;
    return slowptr;
}


int main()
{
    Node *head = createLinkedList();
    cout << "Linked list is created at: " << head;
    cout << endl << "Display of the linked list: " << endl;
    display(head);
    cout << endl << "Middle of the linked list: " << middleNode(head)->val;
}
