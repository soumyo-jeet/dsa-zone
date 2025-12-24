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
    Node *next;
    int val;

    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

Node *createLL()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;
    Node *head = new Node(x);
    head->next = createLL();

    return head;
}

void display(Node *h)
{
    if (h == NULL)
        return;
    cout << (h->val) << " ";
    display(h->next);
}

// k = 3
// 1 -> 2 -> 3 -> 4 -> 5
// 1    2 <- 3 <- 4    5
// |____|__________|    |
//      |_______________|
Node *reverse(Node *first, int k)
{
    // store the start
    Node *prev = first, *sc = first->next, *curr = sc;
    while (curr != NULL && k)
    {
        // reverse the connection between start and kth node
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        k--;
    }

    first->next = prev;
    sc->next = curr;
    return sc;
}

Node *reverseKGr(Node *h, int k)
{
    // adding dummy head
    Node *dummy = new Node(-1);
    dummy->next = h;

    Node *curr = dummy;
    while (curr->next != NULL)
    {
        // lc -> does not allow to reverse if there's < k nodes
        Node *checker = curr->next;
        int count = 1;
        while (checker->next != NULL && count < k)
        {
            count++;
            checker = checker->next;
        }
        
        
        if(count == k) curr = reverse(curr, k);
        else break;
    }

    return dummy;
}

int main()
{
    Node *list = createLL();
    display(list);

    int k;
    cin >> k;
    list = reverseKGr(list, k);
    cout << list << "here: \n";
    display(list);
}