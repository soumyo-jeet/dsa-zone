// fast and slow pointer concept -->
//      two pinter will traverse through the whole linked lists but one in x speed (simple travarsal), one with 2x speed (skipping one node)

// for linear list -->
//      when fast pointer reaches the end node the slow pointer will be at the middle node

// for circular list -->
//      there's no end => slow pointer will catch the fast pointer after a certain of time
//      where they will meet it will be the middle of the loop



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

Node *createLinearLinkedList()
{
    int x;
    cout << "Enter element: ";
    cin >> x;

    if(x == -1) return nullptr;
    Node *head = new Node(x);
    head->next = createLinearLinkedList();
    
    return head;
}


Node *createCircularLinkedList (int pos)
{
    if(pos == 0) return createLinearLinkedList();

    int x;
    // create head of the list
    cout << "Enter element: ";
    cin >> x;
    Node *head = new Node(x), *curr = head;

    // create linear linked list untill the position
    while(pos > 1)
    {
        cout << "Enter element: ";
        cin >> x;
        curr->next = new Node(x);
        curr = curr->next;
        pos --;
    }

    // head of the circular linked list
    Node *chead = curr;

    // now create the circular list
    cout << "Enter element: ";
    cin >> x;
    while(x != -1)
    {
        curr->next = new Node(x);
        curr = curr->next;
        cout << "Enter element: ";
        cin >> x;
    }
    
    // make the circle
    curr->next = chead;

    return head;
}

void *display (Node *head)
{
    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int lenOfLoop(Node *head)
{
    Node *slwptr = head, *fastptr = head->next;

    while(fastptr != nullptr && fastptr->next != nullptr)
    {
        if(fastptr == slwptr) break;
        fastptr = fastptr->next->next;
        slwptr = slwptr->next;
    }

    // loop is present
    int count = 0;
    if(fastptr == slwptr)
    {
        slwptr = slwptr->next;
        count = 1;

        while(slwptr != fastptr)
        {
            slwptr = slwptr->next;
            count ++;
        }
    }

    return count;
}

int main ()
{
    int p;
    cout << "Enter position, from where the list will become circular: ";
    cin >> p;
    Node *head = createCircularLinkedList(p);
    cout << "Length of loop: " << lenOfLoop(head) << endl;
    cout << "Display of the list: " << endl;

}