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
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;   
    }
};


Node* createBT()
{
    int x;
    cout << "Enter element: ";
    cin >> x;
    if(x == -1) return nullptr;

    Node* node = new Node(x);
    node->left=createBT();
    node->right=createBT();

    return node;
}


int height(Node* root, int &valid)
{
    if(root == nullptr) return 0;

    // height of the left sub tree
    int lh = height(root->left, valid);

    // height of the right sub tree
    int rh = height(root->right, valid);

    // check if the diff bw left & right sub tree h is in valid range
    if(!(lh - rh >= -1 && lh - rh <= 1)) 
    {
        valid = 0;
    }

    // return the h of the tree to its root -> h of the root
    return 1 + max(lh, rh); 
}

int isBalanced(Node* node)
{
    int valid = 1;
    height(node, valid);
    return valid;
}

int main()
{
    Node* root = createBT();
    cout << endl << "BTs has created at " << root << endl;
    cout << isBalanced(root);
}
