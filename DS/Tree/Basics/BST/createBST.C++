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

class Node {
    public:
    int val;
    Node *left;
    Node *right;

    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};
/* 
Node *createBST (int arr[], int i, int size)
{
    if(i == size) return NULL;

    Node *n = new Node(arr[i]);
    if(((i + 1) < size) && (arr[i + 1] < n->val)) n->left = createBST(arr, i + 1, size);
    if(((i + 1) < size) && (arr[i + 1] > n->val)) n->right = createBST(arr, i + 1, size);

    return n;
} */

Node *createBST(int target, Node *root)
{
    // create the node and return its add while the place is null
    if(root == NULL) 
    {
        Node *temp = new Node(target);
        return temp;
    }

    // move left
    if(target < root->val)
    {
        root->left = createBST(target, root->left);
    }

    // move right
    else
    {
        root->right = createBST(target, root->right);
    }

    return root;
}

void display (Node *head)
{
    if(head == NULL) return;
    cout << head->val << " ";
    display(head->left);
    display(head->right);
}

int main()
{
    int arr[100], n;
    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = NULL;
    for(int i = 0; i < n; i++)
    {
        head = createBST(arr[i], head);
    }
    cout << "BST created at: " << head;
    cout << "\nDisplay of the tree in pre order: \n";
    display(head);
}