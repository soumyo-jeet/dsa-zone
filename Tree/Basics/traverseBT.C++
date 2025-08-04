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
    Node *left;
    Node *right;
    int data;

    Node(int val, Node *l = nullptr, Node *r = nullptr)
    {
        data = val;
        left = l;
        right = r;
    }
};

Node *createBinaryTree()
{
    int x;
    cout << "Enter element: ";
    cin >> x;

    if (x == -1)
        return NULL;

    Node *node = new Node(x);
    node->left = createBinaryTree();
    node->right = createBinaryTree();

    return node;
}


// N -> L -> R 
void traversePre (Node* node)
{
    if (node == NULL) return;

    // print the node
    cout << node->data << " ";

    // traverse to left
    traversePre(node->left);
    // traverse to right
    traversePre(node->right);
}


// L -> N -> R
void traverseIn (Node* node)
{
    if (node == NULL) return;

    
    // traverse to left
    traverseIn(node->left);

    // print the node
    cout << node->data << " ";

    // traverse to right
    traverseIn(node->right);
}


// L -> R -> N
void traversePost (Node* node)
{
    if (node == NULL) return;

    
    // traverse to left
    traversePost(node->left);
    // traverse to right
    traversePost(node->right);

    // print the node
    cout << node->data << " ";
}



int main()
{
    Node* root = createBinaryTree();
    cout << "Binary tree is created at " << root << endl;

    cout << "The nodes in Pre Order: " << endl;
    traversePre(root);

    cout << "The nodes in In Order: " << endl;
    traverseIn(root);

    cout << "The nodes in Post Order: " << endl;
    traversePost(root);


}