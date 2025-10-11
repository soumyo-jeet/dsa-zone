class Solution {
public:
    /* bool evaluateTree(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;

        root->left->val = evaluateTree(root->left);
        root->right->val = evaluateTree(root->right);

        if(root->val == 2) root->val = root->left->val || root->right->val;
        else root->val = root->left->val && root->right->val;

        return root->val;
    } */
};


// https://leetcode.com/problems/evaluate-boolean-binary-tree/