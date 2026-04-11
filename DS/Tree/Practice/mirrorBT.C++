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


Node* convertToMirror(Node* root)
{
    if(root == nullptr) return nullptr;

    // swap left of the node with the right
    Node* temp = root->left;
    root->left = convertToMirror(root->right);
    root->right = convertToMirror(temp);
    
    return root;
}

// N L R order
void displayPre(Node* node)
{
    if(node == nullptr) return;

    cout << node->data << " ";
    displayPre(node->left);
    displayPre(node->right);
}

int main()
{
    Node* root = createBT();
    cout << endl << "BTs has created at " << root << endl;

    cout << "Your Tree: " << endl;
    displayPre(root);

    convertToMirror(root);
    cout << "Mirror Tree: " << endl;
    displayPre(root);
    
}