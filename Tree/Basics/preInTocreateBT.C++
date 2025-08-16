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

int findPosition (vector<int> inOrder, int inSt, int inEnd, int pivot)
{
    for(int i = inSt; i <= inEnd; i++)
    {
        if(inOrder[i] == pivot) return i;
    }
    return -1;
}


Node* createBTFromPreIn (vector<int>& preOrder, vector<int>& inOrder, int inSt, int inEnd, int index)
{
    // from preorder the root is determined
    // from inorder the left & right of the root are determined

    // inSt > inEnd => inOrder elements at that pos has became null
    if(inSt > inEnd) return NULL;

    Node* root = new Node(preOrder[index]);

    // position of the root in inorder
    int pos = findPosition(inOrder, inSt, inEnd, preOrder[index]);

    // left elements of the pos in inorder => left of the root
    root->left = createBTFromPreIn(preOrder, inOrder, inSt, pos - 1, index + 1);

    // right elements of the pos in inorder => right of the root
    root->right = createBTFromPreIn(preOrder, inOrder, pos + 1, inEnd, index + (pos - inSt) + 1); 

    return root;
}



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


int main()
{
    vector<int> inOrder, preOrder;
    int n;
    cout << "Number of nodes: ";
    cin >> n;

    cout << "Give the inorder sequence: ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        inOrder.push_back(x);
    }

    cout << "Give the preorder sequence: ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        preOrder.push_back(x);
    }

    Node* root = createBTFromPreIn(preOrder, inOrder, 0, n-1, 0);
    cout << "The tree is created at " << root << endl;

    cout << "The nodes in In Order: " << endl;
    traverseIn(root);
    
}