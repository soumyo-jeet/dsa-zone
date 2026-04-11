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

Node *newTail(Node *head, int n)
{
    while(head != nullptr && n > 0)
    {
        head=head->next;
        n --;
    }
    return head;
}

Node *tail(Node *head)
{
    while(head->next != nullptr)
    {
        head = head->next;
    }

    return head;
}

Node *rotate(Node *head, int k)
{
    if(head == nullptr || head->next == nullptr) return head;

    // strategy :--> cut the last k nodes to the before of the current head
    int totalNodes = totalNode(head);
    k = k % totalNodes;
    if (k == 0) return head;

    Node *currTail = tail(head);
    Node *futTail = newTail(head, totalNodes - k - 1);
    Node *futHead = futTail->next;
    futTail->next = nullptr;
    currTail->next = head;
    head = futHead;

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


int main ()
{
    Node *head = createLinkedList();
    cout << "Linked list is created at: " << head;
    cout << endl << "Display of the linked list: " << endl;
    display(head);

    int k;
    cout << "Enter k: ";
    cin >> k;
    
    cout << endl << "Rotated version of the linked list: " << endl;
    head = rotate(head, k);
    display(head);
}
