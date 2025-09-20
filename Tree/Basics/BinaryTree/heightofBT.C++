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
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


Node* createBinaryTree ()
{
    int x;
    cout << "Enter element: ";
    cin >> x;

    if(x == -1) return NULL;

    Node* node = new Node(x);
    node->left = createBinaryTree();
    node->right = createBinaryTree();
    return node;
}

int max (int a, int b)
{
    int ans = a > b ? a : b;
    return ans;
}

int height (Node* root)
{
    if(root == NULL) return 0;

    // find max of nodes in left and right
    return 1 + max(height(root->left) , height(root->right)); 
}

int main()
{
    Node* root = createBinaryTree();
    cout << "Binary tree is created at " << root << endl;

    cout << "Height of the BT is: " << height(root);
}