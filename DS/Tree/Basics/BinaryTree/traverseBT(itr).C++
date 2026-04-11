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

void traversePre (Node* root)
{
    stack<Node*> nodes;
    nodes.push(root);

    while(!nodes.empty())
    {
        // print the node
        cout << nodes.top()->data << " ";
        Node* temp = nodes.top();
        nodes.pop();

        // store in stack in R L order
        if(temp->right != NULL)
        {
            nodes.push(temp->right);
        }
        
        if(temp->left != NULL)
        {
            nodes.push(temp->left);
        }

    }
}

void traverseIn (Node* root)
{
    stack<Node *> nodes;
    stack<int> count;
    nodes.push(root);
    count.push(0);

    while(!nodes.empty())
    {
        // taking the top element out and checking the count / visit
        int tempC = count.top();
        count.pop();
        Node* temp = nodes.top();
        nodes.pop();

        if(tempC == 0)
        {
            // inserting inorder seq -> R N L (to get L N R)
            if(temp->right != NULL)
            {
                nodes.push(temp -> right);
                count.push(0);
            }
    
            nodes.push(temp);
            count.push(1);
    
            if(temp->left != NULL)
            {
                nodes.push(temp -> left);
                count.push(0);
            }
        }

        else
        {
            // printing the node
            cout << temp->data << " ";
        }

    }

}


void traversePost (Node* root)
{
    vector<int> ans;
    stack<Node *> nodes;
    nodes.push(root);

    // framing ans in N R L order
    while(!nodes.empty())
    {
        // pop out the top (node) store it to ans
        Node* temp = nodes.top();
        nodes.pop();
        ans.push_back(temp->data);

        // struct the stack in L R order
        if(temp->left != NULL) 
        {
            nodes.push(temp->left);
        }

        if(temp->right != NULL)
        {
            nodes.push(temp->right);
        }
    }

    // reversing ans to get L R N order
    for(int i = ans.size() - 1; i >= 0 ; i--)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    Node* root = createBinaryTree();
    cout << "Binary tree is created at " << root << endl;

    cout << endl << "The nodes in Pre Order: " << endl;
    traversePre(root);

    cout << endl << "The nodes in In Order: " << endl;
    traverseIn(root);

    cout << endl << "The nodes in Post Order: " << endl;
    traversePost(root);


}


