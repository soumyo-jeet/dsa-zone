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


int isIdentical(Node* r1, Node* r2)
{
    if(r1 == nullptr && r2 == nullptr) return 1;
    else if((r1 == nullptr && r2 != nullptr) || (r1 != nullptr && r2 == nullptr)) return 0;

    queue<Node*> nodes1, nodes2;
    nodes1.push(r1);
    nodes2.push(r2);

    while(!nodes1.empty() || !nodes2.empty())
    {
        Node* temp1 = nodes1.front();
        Node* temp2 = nodes2.front();

        nodes1.pop();
        nodes2.pop();

        if(temp1->data != temp2->data) return 0;

        if(temp1->left != nullptr && temp2->left != nullptr) 
        {
            nodes1.push(temp1->left);
            nodes2.push(temp2->left);
        }

        else if(!(temp1->left == nullptr && temp2->left == nullptr)) return 0;

        if(temp1->right != nullptr && temp2->right != nullptr) 
        {
            nodes1.push(temp1->right);
            nodes2.push(temp2->right);
        }

        else if(!(temp1->right == nullptr && temp2->right == nullptr)) return 0;

    }

    return 1;
}

int main()
{
    cout << "Tree 1" << endl;
    Node* root1 = createBT();
    cout << "Tree 2" << endl;
    Node* root2 = createBT();

    cout << endl << "BTs have created at " << root1 << " and " << root2 << endl;
    cout << isIdentical(root1, root2);
}