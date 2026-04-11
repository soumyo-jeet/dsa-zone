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
        left = right = NULL;   
    }
};


Node* createBT()
{
    int x;
    cout << "Enter element: ";
    cin >> x;
    if(x == -1) return NULL;

    Node* node = new Node(x);
    node->left=createBT();
    node->right=createBT();

    return node;
}

void find(Node *root, int pos, int &l, int &r)
{
    if(root == NULL) return;

    l = min(l,pos);
    r = max(r,pos);

    // shift to left
    find(root->left, pos-1, l, r);
    // shift to right
    find(root->right, pos+1, l, r);
}

// find the rightmost (+r) and leftmost (-l) node index
// size of the ans vector = r - (-l) + 1
// queue the treenodes with there shifted index (actual index, where the node data should be inserted)
// consider the last node for a repitative index
vector<int> bottomView(Node *root)
{
    int l = 0, r = 0;
    find(root, 0, l, r);
    cout << l << " " << r << endl;

    vector<int> ans(r - l + 1);
    
    int rootIndx = -1 * l;

    queue<Node *> level; queue<int> id;
    level.push(root);
    id.push(rootIndx);

    while(!level.empty())
    {
        // pop out the element with id and place it to the vector at the specific id
        Node *curr = level.front();
        int currId = id.front();
        id.pop();
        level.pop();

        // for top view only the first element correspond to the currId should be considered
        ans[currId] = curr->data;

        if(curr->left != NULL) 
        {
            level.push(curr->left);
            id.push(currId - 1);
        }
        if(curr->right != NULL) 
        {
            level.push(curr->right);
            id.push(currId + 1);
        }
    }

    for(int i = 0; i < ans.size(); i ++)
    {
        cout << ans[i] << " ";
    }

    return ans;
}

void bView(Node *root, int pos, vector<int> &ans)
{
    if(root == NULL) return;

    ans[pos] = root->data;
    // shift left
    bView(root->left, pos-1, ans);
    // shift right
    bView(root->right, pos+1, ans);
}

vector<int> bottomViewWithRecc(Node *root)
{
    int l = 0, r = 0;
    find(root, 0, l, r);
    
    vector<int> ans(r - l + 1);
    
    int rootIndx = -1 * l;
    bView(root, rootIndx, ans);

    for(int i = 0; i < ans.size(); i ++)
    {
        cout << ans[i] << " ";
    }
    return ans;
}

int main()
{
    Node* root = createBT();
    cout << endl << "BTs has created at " << root << endl;

    cout << "Bottom view of your Tree: " << endl;
    bottomView(root);

    cout << endl << "Bottom view of your Tree (with reccursion): " << endl;
    bottomViewWithRecc(root);
}