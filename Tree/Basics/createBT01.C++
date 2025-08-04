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
    Node* left;
    Node* right;
    int data;

    Node(int val) 
    {
        data = val;
        left = NULL;
        right - NULL;
    }

};

int main()
{
    int x;
    cout << "enter root of the tree: ";
    cin >> x;

    Node* node = new Node(x);
    queue<Node*> nodes;

    nodes.push(node);

    while(!nodes.empty())
    {
        cout << "enter at the left of " << nodes.front()->data << endl;
        cin >> x;

        if(x != -1)
        {
            Node* node = new Node(x);
            nodes.push(node);
            nodes.front()->left = node;
        }

        cout << "enter at the right of " << nodes.front()->data << endl;
        cin >> x;

        if(x != -1)
        {
            Node* node = new Node(x);
            nodes.push(node);
            nodes.front()->right = node;
        }

        nodes.pop();
    }
}