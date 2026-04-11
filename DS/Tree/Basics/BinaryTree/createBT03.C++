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
        Node *left;
        Node *right;
        int data;

        Node(int val, Node* l = nullptr, Node* r = nullptr) {
            data = val;
            left = l;
            right = r;
        }
};


Node* createBinaryTree () {
    int x;
    cout << "Enter element: ";
    cin >> x;

    if( x == -1 ) return NULL;

    Node* node = new Node(x);
    node->left = createBinaryTree();
    node->right = createBinaryTree();

    return node;
}


int main()
{
    createBinaryTree();
    cout << "Binary tree is created";
}