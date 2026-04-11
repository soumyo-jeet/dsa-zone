// ALGORITHM-->
//      0. Insert the node at the leaf of the tree, maintaing BST logic and update the height
//      1. Check the balance of the node
//      2. the tree is left imbalanced at the node
//         (FULLY)
//              => rotate the node to the right of its child node
//              => attach the grand right child (the right child of the node's child) to the left of the node
//          (PARTIALLY == l-r)
//              => rotate the child of the node to the left of its grand child  
//              => attach it to the left of the node
//              => the node becomes fully left imbalanced
//              => handle it by the conventional way
//      3. the tree is right imbalanced at the node
//         (FULLY)
//              => rotate the node to the left of its child node
//              => attach the grand left child (the left child of the node's child) to the right of the node
//         (PARTIALLY == r-l)
//              => rotate the child of the node to the right of its grand child  
//              => attach it to the right of the node
//              => the node becomes fully right imbalanced
//              => handle it by the conventional way


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
    int h, val;
    Node *left, *right;

    Node(int x)
    {
        val = x;
        h = 1;
        left = right = NULL;
    }
};

int hOfN(Node *n)
{
    if(n == NULL) return 0;
    else return n->h;
}

Node *rightRotation(Node *n)
{
    Node *child = n->left;
    Node *grandChild = child->right;

    // shift the node to the right side of its child
    child->right = n;

    // shift the grand right child to the node's left
    n->left = grandChild;

    // update height
    n->h = 1 + max(hOfN(n->left), hOfN(n->right));
    child->h = 1 + max(hOfN(n->left), hOfN(n->right));


    //  make the child new root
    return child;
}


Node *leftRotation(Node *n)
{
    Node *child = n->right;
    Node *grandChild = child->left;

    // shift the node to the left side of its child
    child->left = n;

    // shift the grand left child to the node's right
    n->right = grandChild;

    // update height
    n->h = 1 + max(hOfN(n->left), hOfN(n->right));
    child->h = 1 + max(hOfN(n->left), hOfN(n->right));


    //  make the child new root
    return child;
}



Node *insert(int x, Node *root)
{
    // reaching to the leaf create the node
    if(root == NULL)
    {
        Node *root = new Node(x);
        return root;
    }

    // find the insertion position and place it
    if(x < root->val) root->left= insert(x, root->left);
    else if(x > root->val) root->right= insert(x, root->right);
    else return root;

    // height update
    root->h = 1 + max(hOfN(root->left), hOfN(root->right));

    // check balance
    int bal = hOfN(root->left) - hOfN(root->right);
    
    // left-left
    if(bal > 1 && x < root->left->val)
    {
        // right rotation of the top
        return rightRotation(root);
    }

    // right-right
    else if(bal < -1 && x > root->right->val)
    {
        // left rotation of the top
        return leftRotation(root);
    }

    // left-right
    else if(bal > 1 && x > root->left->val)
    {
        // left rotation of the middle
        root->left = leftRotation(root->left);
        // tree has become l-l, do right rotation on the top now 
        return rightRotation(root);
    }

    // right-left
    else if(bal < -1 && x < root->right->val)
    {
        // right rotate the middle
        root->right = rightRotation(root->right);
        // tree has become r-r, do left rotate on the top now
        return leftRotation(root);
    }

    else return root;
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
    int x;
    cout << "Insert: ";
    cin >> x;
    Node *root = insert(x, NULL);
    cout << root << endl;
    while(x != -1)
    {
        cout << "Insert: ";
        cin >> x;
        if(x == -1) break;
        root = insert(x, root);
        cout << root << endl;
    }

    cout << "\nDisplay pre order: \n";
    display(root);
}