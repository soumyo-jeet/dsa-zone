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
    int blank_left;
    int blank_right;
    int data;

    Node(int val, Node *l = NULL, Node *r = NULL)
    {
        data = val;
        left = l;
        right = r;
        blank_left = 0;
        blank_right = 0;
    }
};

class Tree
{
    Node *root;
    queue<Node *> nodes;

public:
    Tree(int val)
    {
        root = new Node(val);
        nodes.push(root);
    }

    int insert(int val)
    {

        if (val != -1)
        {
            Node *newNode = new Node(val);
            // left insertion
            if (nodes.front()->left == NULL && nodes.front()->blank_left == 0)
            {
                nodes.front()->left = newNode;
                nodes.push(newNode);
                cout << val << " is joined at the left of " << nodes.front()->data << endl;
            }

            // right insertion
            else if (nodes.front()->right == NULL && nodes.front()->blank_right == 0)
            {
                nodes.front()->right = newNode;
                nodes.push(newNode);
                cout << val << " is joined at the right of " << nodes.front()->data << endl;
            }
        }

        // ignore insertion
        else if (val == -1 && (nodes.front()->left == NULL && nodes.front()->blank_left == 0))
        {
            nodes.front()->blank_left = 1;
            cout << "the left of " << nodes.front()->data << " left empty " << nodes.front()->blank_left<< endl;
        }
        else
        {
            nodes.front()->blank_right = 1;
            cout << "the right of " << nodes.front()->data << " left empty " << nodes.front()->blank_right << endl;
        }

        if ((nodes.front()->right != NULL || nodes.front()->blank_right == 1) &&
        (nodes.front()->left != NULL || nodes.front()->blank_left == 1))
        {
            nodes.pop();
        }

        if (nodes.empty())
            return 0;
        return 1;
    }
};

int main()
{
    int x;
    cout << "enter root of the tree: ";
    cin >> x;

    Tree t1(x);
    cout << "tree is created with root " << x << endl;

    cout << "Enter element to insert: ";
    cin >> x;
    while (t1.insert(x))
    {
        cout << "Enter element to insert: ";
        cin >> x;
    }

    return 0;
}