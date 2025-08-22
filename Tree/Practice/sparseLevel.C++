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

Node *createBT()
{
    int x;
    cout << "Enter element: ";
    cin >> x;
    if (x == -1)
        return nullptr;

    Node *node = new Node(x);
    node->left = createBT();
    node->right = createBT();

    return node;
}

// simple using vector reverse logic
void sparseLevelTraverse1(Node *root)
{
    queue<Node *> nodes;
    vector<vector<int>> ans;

    if (root == nullptr)
        return;

    nodes.push(root);

    int level = 1;
    while (!nodes.empty())
    {
        int size = nodes.size();
        vector<int> levelEles;
        for (int i = 0; i < size; i++)
        {
            levelEles.push_back(nodes.front()->data);

            // first left
            if (nodes.front()->left != nullptr)
            {
                nodes.push(nodes.front()->left);
            }

            // then right
            if (nodes.front()->right != nullptr)
            {
                nodes.push(nodes.front()->right);
            }

            nodes.pop();
        }

        cout << endl
             << "Level " << level << endl;

        // print left to right for even levels
        if (level % 2 == 0)
        {
            for (int i = 0; i < levelEles.size(); i++)
            {
                cout << levelEles[i] << " ";
            }
        }

        // print right to left for odd levels
        else
        {
            for (int i = levelEles.size() - 1; i >= 0; i--)
            {
                cout << levelEles[i] << " ";
            }
        }

        level++;
    }
}

// using two stack
void sparseLevelTraverse2(Node *root)
{
    stack<Node *> rtl, ltr;
    rtl.push(root);

    int level = 1;
    while (!rtl.empty() || !ltr.empty())
    {
        vector<int> levelEl;

        if(level % 2)
        {
            while (!rtl.empty())
            {
                levelEl.push_back(rtl.top()->data);
    
                // store to ltr stack in rtl order
                if (rtl.top()->right != nullptr)
                {
                    ltr.push(rtl.top()->right);
                }
    
                if (rtl.top()->left != nullptr)
                {
                    ltr.push(rtl.top()->left);
                }
    
                rtl.pop();
            }
        }

        else
        {
            while (!ltr.empty())
            {
                levelEl.push_back(ltr.top()->data);
    
                // store to rtl stack in ltr order
                if (ltr.top()->left != nullptr)
                {
                    rtl.push(ltr.top()->left);
                }
    
                if (ltr.top()->right != nullptr)
                {
                    rtl.push(ltr.top()->right);
                }
    
                ltr.pop();
            }
        }

        cout << endl
             << "Level " << level << endl;

        for (int i = 0; i < levelEl.size(); i++)
        {
            cout << levelEl[i] << " ";
        }

        level ++;
    }
}

int main()
{
    Node *root = createBT();
    cout << endl
         << "BTs has created at " << root << endl;

    cout << endl << "Sparse using vector reversal method" << endl;
    sparseLevelTraverse1(root);
    cout << endl << "Sparse using two stack method" << endl;
    sparseLevelTraverse2(root);

}