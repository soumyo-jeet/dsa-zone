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


int isBalanced(Node* node)
{
    if(node == nullptr) return 1;

    if((node->left == nullptr || node->data > node->left->data) && 
    (node->right == nullptr || node->data <= node->right->data)) return 1;

    else return 0;

    return isBalanced(node->left) && isBalanced(node->right);
}

int main()
{
    Node* root = createBT();
    cout << endl << "BTs has created at " << root << endl;
    cout << isBalanced(root);
}
