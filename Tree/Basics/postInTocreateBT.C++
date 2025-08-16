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

Node* createBTFromPostIn(vector<int> &postOrder, vector<int> &inOrder, int inSt, int inEnd, int index)
{
    if(inSt > inEnd) return NULL;
    Node* root = new Node(postOrder[index]);

    int pos = findPosition(inOrder, inSt, inEnd, postOrder[index]);

    // in postorder the just left of the root => right of the acc tree root
    root->right = createBTFromPostIn(postOrder, inOrder, pos + 1, inEnd, index - 1);
    root->left = createBTFromPostIn(postOrder, inOrder, inSt, pos - 1, index - (inEnd - pos) - 1);

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
    vector<int> inOrder, postOrder;
    int n;
    cout << "Number of nodes: ";
    cin >> n;

    cout << "Give the inorder sequence: ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        inOrder.push_back(x);
    }

    cout << "Give the postorder sequence: ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        postOrder.push_back(x);
    }

    Node* root = createBTFromPostIn(postOrder, inOrder, 0, n-1, n-1);
    cout << "The tree is created at " << root << endl;

    cout << "The nodes in In Order: " << endl;
    traverseIn(root);
    
}