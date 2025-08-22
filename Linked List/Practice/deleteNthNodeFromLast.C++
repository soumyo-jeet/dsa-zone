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

    ~Node() {}
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

int totalNode(Node *head)
{
    int ans = 0;
    while(head != nullptr)
    {
        head = head->next;
        ans++;
    }
    return ans;
}

Node *prevOfTarget(Node *head, int n)
{
    int nc = 0, totalNodes = totalNode(head), k = totalNodes - n;
    while(nc < k - 1 && head != nullptr)
    {
        nc ++;
        head = head->next;
    }

    return head;
}

Node *deleteTarget(Node *head, int n)
{
    int tns = totalNode(head);
    if((n <= 0) || (n > tns)) return head;
    if(n == tns)
    {
        Node *futHead = head->next;
        delete head;
        head = futHead;
        return head;
    }

    Node *prevT = prevOfTarget(head, n);
    Node *target = prevT->next;
    prevT->next = target->next;
    delete target;
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
    int n;
    cout << "enter n: ";
    cin >> n;
    head = deleteTarget(head, n);
    cout << endl << "After deleting target: " << endl;
    display(head);
}
