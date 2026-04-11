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
    char val;
    Node *left, *right;
    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

int eval_char(char c)
{
    if(c == '^') return 0;
    else if(c == '*' || c == '/') return 1;
    else if(c == '+' || c == '-') return 2;
    else return 4;
}


int findRoot(string infix, int s, int e)
{
    if(s == e) return s;
    int lp = INT_MIN, ans;
    for(int i = s; i <= e; i ++)
    {
        char curr = infix[i];
        if(eval_char(curr) != 4 && eval_char(curr) >= lp)
        {
            lp = eval_char(curr);
            ans = i;
        }
    }
    return ans;
}


Node *createETFromIn(string infix, int start, int end)
{
    if(start > end) return NULL;

    // find the root
    int rootP = findRoot(infix, start, end);

    // create the root
    Node *root = new Node(infix[rootP]);

    // left part of the root position will create the left subtree
    root->left = createETFromIn(infix, start, rootP-1);
    // right part of the root position will create the right subtree
    root->right = createETFromIn(infix, rootP+1, end);

    return root;
}

void display (Node *head)
{
    if(head == NULL) return;
    cout << head->val << " ";
    display(head->left);
    display(head->right);
}

int main()
{
    string infix;
    cout << "Give the infix expression: ";
    cin >> infix;

    Node *root = createETFromIn(infix, 0, infix.length() - 1);

    cout << "\nExpression Tree is created at root: " << root;
    cout << "\nDisplay:\n";
    display(root);
}