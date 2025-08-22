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


int level (int x, Node* root)
{
    queue<Node *> nodes;
    nodes.push(root);
    int level = 1;

    while(!nodes.empty())
    {
        int lvlSize = nodes.size();
        while(lvlSize)
        {
            if(nodes.front()->data == x) return level;

            if(nodes.front()->left != nullptr)
            {
                nodes.push(nodes.front()->left);
            }

            if(nodes.front()->right != nullptr)
            {
                nodes.push(nodes.front()->right);
            }

            nodes.pop();
            lvlSize--;
        }

        level++;
    }

    return -1;
}


int sameParent (int x, int y, Node* root)
{
    queue<Node *> nodes;
    nodes.push(root);
    int level = 1;

    while(!nodes.empty())
    {
        int lvlSize = nodes.size();
        while(lvlSize)
        {
            if( 
                (nodes.front()->left!=nullptr && nodes.front()->right!=nullptr) &&
                ((nodes.front()->left->data == x && nodes.front()->right->data == y) ||
                (nodes.front()->right->data == x && nodes.front()->left->data == y))
            ) return 1;

            if(nodes.front()->left != nullptr)
            {
                nodes.push(nodes.front()->left);
                
            }

            if(nodes.front()->right != nullptr)
            {
                nodes.push(nodes.front()->right);
            }

            nodes.pop();
            lvlSize--;
        }

        level++;
    }

    return 0;
}


bool isCousin (int x, int y, Node* root)
{
    return (level(x,root) == level(y,root)) && !sameParent(x,y,root);
}

int main()
{
    Node* root = createBT();
    cout << endl << "BTs has created at " << root << endl;

    int x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    cout << isCousin(x,y,root);
}