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

Node *reverse(Node *head)
{
    if(head == nullptr || head->next == nullptr) return head;
    Node *prevNode = nullptr, *futHead = head->next;
    while(futHead != nullptr)
    {
        cout << "Future head: " << futHead->val << " ";
        cout << "Previous head: " << prevNode << " ";
        cout << "Current head: " << head->val << " ";
        // replace the next of the curr node with prev
        head->next = prevNode;

        // new prev / prev for the next step will be the curr node
        prevNode = head;
        // new curr node will be the future node 
        head = futHead;
        // new future node will be the next of the new curr node
        futHead = head->next;
        cout << endl;
    }

    // modify the connection of the last node
    head->next = prevNode;
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


int main()
{
    Node *head = createLinkedList();
    cout << "Linked list is created at: " << head;
    cout << endl << "Display of the linked list: " << endl;
    display(head);
    cout << endl << "Display of the current reversed linked list: " << endl;
    head = reverse(head);
    display(head);

}
