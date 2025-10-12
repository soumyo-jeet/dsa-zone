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


int size (Node* root)
{
    int ans = 1;
    queue<Node*> nodes;
    nodes.push(root);

    while(!nodes.empty())
    {
        Node* temp = nodes.front();
        nodes.pop();

        if(temp->left != NULL)
        {
            nodes.push(temp->left);
            ans ++;
        }

        if(temp->right != NULL)
        {
            nodes.push(temp->right);
            ans ++;
        }

    }

    return ans;
}



int leafNodes (Node* root)
{
    int ans = 0;
    queue<Node*> nodes;
    nodes.push(root);

    while(!nodes.empty())
    {
        Node* temp = nodes.front();
        nodes.pop();

        if(temp->left != NULL)
        {
            nodes.push(temp->left);
        }

        if(temp->right != NULL)
        {
            nodes.push(temp->right);
        }

        if(temp->left == NULL && temp->right == NULL)
        {
            ans ++;
        }

    }

    return ans;
}

int main()
{
    Node* root = createBinaryTree();
    cout << "Binary tree is created at " << root << endl;

    cout << "Total leaf nodes of the BT is: " << leafNodes(root) << endl;
    cout << "Total non-leaf nodes of the BT is: " << size(root) - leafNodes(root);
}