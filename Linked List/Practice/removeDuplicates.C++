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

int alreadyPresent(int x, vector<int> arr)
{
    for(int i = 0; i < arr.size(); i ++)
    {
        if (arr[i] == x) return 1;
    }
    return 0;
}

Node *removeDuplicates(Node *head)
{
    vector<int> vals;
    Node *curr = head, *prev = nullptr;
    while(curr != nullptr)
    {
        if(alreadyPresent(curr->val, vals))
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            vals.push_back(curr->val);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}



int main()
{
    Node *head = createLinkedList();
    cout << "Linked list is created at: " << head;
    cout << endl << "Display of the linked list: " << endl;
    display(head);

    head = removeDuplicates(head);
    cout << endl << "Required list: ";
    display(head);
}
