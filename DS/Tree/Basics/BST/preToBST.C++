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
        cout << root->val << " ";
        dispaly(root->left);
        dispaly(root->right);
    }
};

// O(n * n)
int findPart(vector<int> &preorder, int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        if (preorder[start] < preorder[i])
            return i;
    }
    return end + 1;
}
TreeNode *createBSTFromPre(vector<int> &preorder, int start, int end, int index)
{
    if (start > end)
        return NULL;

    TreeNode *root = new TreeNode(preorder[index]);

    // find the index where greater than root lies
    int partition = findPart(preorder, start, end);
    cout << index << " ";
    cout << partition << endl;

    // elements at the left of the partition should go to the left of the tree
    root->left = createBSTFromPre(preorder, start + 1, partition - 1, index + 1);
    // elements at the right of the partition should go to the right of the tree
    // no partition => no right child
    root->right = partition == end + 1 ? NULL : createBSTFromPre(preorder, partition, end, partition);

    return root;
}


// O (n)
int start = 0;
TreeNode *createBSTFromPre_(vector<int> preorder, int end, int minLimit, int maxLimit)
{
    // check if the element lies in the range of the node
    if(start > end || !(preorder[start] > minLimit && preorder[start] < maxLimit)) 
    return NULL;

    // create a node if it lies in
    TreeNode *root = new TreeNode(preorder[start]);
    start ++;
    
    // determie the range of the nodes

    // left child node should be < root and > parent of the root (while the root is)
    root->left = createBSTFromPre_(preorder, end, minLimit, root->val);
    root->right = createBSTFromPre_(preorder, end, root->val, maxLimit);

    return root;
}



int main()
{
    vector<int> preorder ;
    int s;
    cin >> s;
    for(int i = 0; i < s; i++)
    {
        int x;
        cin >> x;
        preorder.push_back(x);
    }


    cout << "Preoreder of the BST: ";
    TreeNode *BST = createBSTFromPre_(preorder, s-1, INT_MIN, INT_MAX);
    BST->dispaly(BST);
}