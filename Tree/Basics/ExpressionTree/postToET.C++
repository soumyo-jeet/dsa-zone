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



Node *createETFromPost(string postfix, stack<Node *> opr)
{
    Node *root;
    for(int i = 0; i < postfix.length(); i ++)
    {
        char curr = postfix[i];
        int check = eval_char(curr);

        // push operands to the stack creating separate nodes
        if(check == 4)
        {
            root = new Node(curr);
            opr.push(root);
        }

        // pop out two tops from the stack apply the oprator and push back the subtree
        else
        {
            Node *B = opr.top();
            opr.pop();
            Node *A = opr.top();
            opr.pop();

            root = new Node(curr);
            root->left = A;
            root->right = B;
            opr.push(root);
        }
    }

    return opr.top();
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
    string postfix;
    stack<Node *> opr;

    cout << "Give the postfix expression: ";
    cin >> postfix;

    Node *root = createETFromPost(postfix, opr);

    cout << "\nExpression Tree is created at root: " << root;
    cout << "\nDisplay:\n";
    display(root);
}