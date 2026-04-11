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
    if(head == nullptr)
    {
        cout << "Empty list!";
        return;
    }

    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
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

Node *deleteKthNode(Node *head, int k)
{
    if (k == 1) return nullptr;
    int currSeq = 1;
    Node *curr = head, *prev = nullptr;

    while(curr != nullptr)
    {
        if(currSeq % k == 0)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
        currSeq ++;
    }
    return head;
}




int main()
{
    Node *head = createLinkedList();
    cout << "Linked list is created at: " << head;
    cout << endl << "Display of the linked list: " << endl;
    display(head);
    int k;
    cout << endl << "enter k: ";
    cin >> k;
    deleteKthNode(head, k);
    cout << endl << "required list: " << endl;
    display(head);
}
