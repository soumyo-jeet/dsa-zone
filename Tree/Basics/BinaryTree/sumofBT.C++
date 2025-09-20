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


int sum (Node* root)
{
    int ans = 0;
    queue<Node*> nodes;
    nodes.push(root);

    while(!nodes.empty())
    {
        Node* temp = nodes.front();
        nodes.pop();
        ans += temp->data;

        if(temp->left != NULL)
        {
            nodes.push(temp->left);
        }

        if(temp->right != NULL)
        {
            nodes.push(temp->right);
        }

    }

    return ans;
}

int main()
{
    Node* root = createBinaryTree();
    cout << "Binary tree is created at " << root << endl;

    cout << "Sum of the BT is: " << sum(root);
}