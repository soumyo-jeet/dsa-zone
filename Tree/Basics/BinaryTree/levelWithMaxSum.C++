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

Node *createBinaryTree()
{
    int x;
    cout << "Enter element: ";
    cin >> x;

    if (x == -1)
        return NULL;

    Node *node = new Node(x);
    node->left = createBinaryTree();
    node->right = createBinaryTree();

    return node;
}

void levelTraverse (Node* root)
{
    queue<Node *>nodes;
    nodes.push(root);
    int levelC = 1;
    vector<int> levelSum;
    
    while(!nodes.empty())
    {
        int levelS = nodes.size();
        int sum = 0;

        // total number of ele present in the q = number of nodes in the level
        for(int i = 0; i < levelS; i++)
        {
            // push the element of that level
            Node* temp = nodes.front();
            nodes.pop();
    
            sum += temp-> data;
    
            // queue the L R
            if(temp->left != NULL)
            {
                nodes.push(temp->left);
            }
    
            if(temp->right != NULL)
            {
                nodes.push(temp->right);
            }

        }

        levelSum.push_back(sum);
        cout << endl << "Sum of level " << levelC << ": " << sum << endl;
        levelC ++;
    }

    int max = levelSum[0], maxL = 1;
    for(int i = 0; i < levelSum.size(); i++)
    {
        if(max < levelSum[i])
        {
            maxL = i + 1;
            break;
        }
    }

    cout << endl << "The level having max sum " << maxL;
}



int main ()
{
    Node* root = createBinaryTree();
    cout << "Binary tree is created at " << root << endl;

    cout << endl << "The nodes in level wise: " << endl;
    levelTraverse(root);
}