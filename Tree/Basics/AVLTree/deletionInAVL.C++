// ALGORITHM --> 
//   0. Find the node contains the element
//   1. Delete it obeying the BST law
//   2. Check the balance
//      => left heavy ->
//          => Check the condition -> 
//              1. left child of the node has more child nodes at right than left => PARTIAL 
//              2. else => FULL
//      => Same for right heavy

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
        // right rotation of the middle
        root->left = rightRotation(root->left);
        // tree has become l-l, do right rotation on the top now 
        return rightRotation(root);
    }

    // right-left
    else if(bal < -1 && x < root->right->val)
    {
        // left rotate the middle
        root->right = leftRotation(root->right);
        // tree has become r-r, do left rotate on the top now
        return leftRotation(root);
    }

    else return root;
}


Node *remove(int x, Node *root)
{
    if (root == NULL) return NULL;

    // do delete
    if(root->val == x)
    {
        // leaf node
        if(root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }

        // node has both child
        else if(root->left != NULL && root->right != NULL)
        {
            // find the lowest element from its right child subtree
            Node *child = root->right;
            while(child->left != NULL)
            {
                child = child->left;
            }

            // transfer value to the root and right child to its parent and then remove it
            root->val = child->val;
            root->right = remove(child->val, root->right);
        }

        // node has only one child
        else
        {
            Node *child;
            if(root->left != NULL) child = root->left;
            else child = root->right;

            delete root;
            return child;
        }
    }

    // find the elemnt
    if(x < root->val) root->left = remove(x, root->left);
    else root->right = remove(x, root->right);

    // update the height
    root->h = 1 + max(hOfN(root->left), hOfN(root->right));

    // check the balance
    int bal = hOfN(root->left) - hOfN(root->right);

    // left heavy
    if(bal > 1)
    {
        int flag = hOfN(root->left->left) - hOfN(root->left->right);
        // PARTIAL
        if(flag < 0)
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
        // FULL
        else
        {
            return rightRotation(root);
        }
    }

    // right heavy
    else if(bal < -1)
    {
        int flag = hOfN(root->right->left) - hOfN(root->right->right);
        // FULL
        if(flag < 0)
        {
            return leftRotation(root);
        }
        // PARTIAL
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
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
    cout << "Create the tree: \n";
    int x;
    cout << "Insert: ";
    cin >> x;
    Node *root = NULL;
    while(x != -1)
    {
        root = insert(x, root);

        cout << "Insert: ";
        cin >> x;
    }

    cout << "\nDisplay pre order: \n";
    display(root);

    cout << "\nDeletion: \n";
    int y;
    cout << "Delete: ";
    cin >> y;
    while(y != -1)
    {
        root = remove(y, root);
        cout << "\nDisplay pre order: \n";
        display(root);

        cout << "Delete: ";
        cin >> y;
    }
}