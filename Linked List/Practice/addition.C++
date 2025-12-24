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


Node *reverseL(Node *h, Node *prev)
{
    if (h == NULL)
        return prev;
    Node *curr = h->next;
    h->next = prev;
    return reverseL(curr, h);
}

void display(Node *h)
{
    if (h == NULL)
        return;
    cout << (h->val) << " ";
    display(h->next);
}

Node *add(Node *h1, Node *h2)
{
    // reverse the lists
    h1 = reverseL(h1, NULL);
    h2 = reverseL(h2, NULL);

    //
    Node *addH = new Node(-1), *curr = addH;
    int carry = 0;
    while (h1 != NULL && h2 != NULL)
    {
        int sum = (h1->val + h2->val + carry);
        int sumVal = sum % 10;
        carry = sum / 10;

        curr->next = new Node(sumVal);
        curr = curr->next;
        h1 = h1->next;
        h2 = h2->next;
    }

    while (h1 != NULL)
    {
        int sum = (h1->val + carry);
        int sumVal = sum % 10;
        carry = sum / 10;

        curr->next = new Node(sumVal);
        curr = curr->next;
        h1 = h1->next;
    }

    while (h2 != NULL)
    {
        int sum = (h2->val + carry);
        int sumVal = sum % 10;
        carry = sum / 10;

        curr->next = new Node(sumVal);
        curr = curr->next;
        h2 = h2->next;
    }

    
    while (carry)
    {
        int now = carry % 10;
        int rem = carry / 10;
        curr->next = new Node(now);
        curr = curr->next;
        carry = rem;
    }

    addH = reverseL(addH->next, NULL);
    return (addH);
}

int main()
{
    cout << "\nNumber 1: ";
    Node *list1 = createLL();
    cout << "\nNumber 2: ";
    Node *list2 = createLL();
    display(list1);
    cout << endl;
    display(list2);

    cout << "\nAddition result: ";
    Node *res = add(list1, list2);
    display(res);
}