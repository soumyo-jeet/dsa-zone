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

Node *deleteNode (Node *root, int target)
{
    if (root == NULL) return NULL;
    
    // do delete
    if(root->val == target)
    {
        // target is leaf node
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // the node has two child
        if(root->left != NULL &&  root->right != NULL)
        {
            // serach for the highest child in its left children with its parent
            Node *child = root->left, *parent = root;
            while(child->right != NULL)
            {
                parent = child;
                child= child->right;
            }

            if(parent == root)
            {
                child->right = parent->right;
                delete root;
                return child;
            }

            // delete the rightmost node and connect its left child with its parent
            parent->right = child->left;
            
            // modify the child
            child->right = root->right;
            child->left = root->left;

            delete root;

            // delete the child
            return child;
        }
        
        // the node has only one child 
        else
        {
            Node *temp;

            // capture the existing child
            if(root->left != NULL) temp = root->left;
            else temp = root->right;
            
            // delete the target
            delete root;

            // connect its child with its parent
            return temp;

        }
    }

    // search first
    if(target < root->val)
    {
        root->left = deleteNode(root->left, target);
    }

    else
    {
        root->right = deleteNode(root->right, target);
    }
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

    int i = 6;
    while(i)
    {
        int t;
        cout << "Enter target: ";
        cin >> t;

        head = deleteNode(head, t);
        cout << "Target has been deleted:\n";
        display(head);
    }
}