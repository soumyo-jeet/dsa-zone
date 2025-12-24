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

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }

    void dispaly(TreeNode *root)
    {
        if(root == NULL) return;
        dispaly(root->left);
        dispaly(root->right);
        cout << root->val << " ";
    }
};


// Don't know... not working... needs proper dry run 
int findPart(vector<int> &postorder, int start, int end)
{
    for (int i = start - 1; i >= end; i--)
    {
        if (postorder[start] > postorder[i])
            return i;
    }
    return -1;
}
TreeNode *createBSTFromPost (vector<int> &postorder, int start, int end, int indx)
{
    if(end > start) return NULL;

    // create the root 
    TreeNode *root = new TreeNode(postorder[indx]);

    // find the lesser element than root
    int partition = findPart(postorder, start, end);

    // right of the partition at the right of the root
    root->right = createBSTFromPost(postorder, start - 1, partition + 1, indx - 1);
    // left of the partition at the left of the root
    // partition -1 => no left child
    root->left = partition == -1 ? NULL: createBSTFromPost(postorder, partition, end, partition);

    return root;
}


// O(n)
TreeNode *createBSTFromPost_(vector<int> postorder, int &start, int minLimit, int maxLimit)
{
    // check if the element lies in the range of the node
    if(start < 0 || !(postorder[start] > minLimit && postorder[start] < maxLimit)) 
    return NULL;
    // create a node if it lies in
    TreeNode *root = new TreeNode(postorder[start]);
    start --;
    
    // determie the range of the nodes
    // start with right subtree for post order

    // right child node should be > root and < parent of the root (while the root is)
    root->right = createBSTFromPost_(postorder, start, root->val, maxLimit);
    root->left = createBSTFromPost_(postorder, start, minLimit, root->val);

    return root;
}

int main()
{
    vector<int> postorder ;
    int s;
    cin >> s;
    for(int i = 0; i < s; i++)
    {
        int x;
        cin >> x;
        postorder.push_back(x);
    }


    cout << "Preoreder of the BST: ";
    int start = s-1;
    TreeNode *BST = createBSTFromPost_(postorder, start, INT_MIN, INT_MAX);
    BST->dispaly(BST);
}