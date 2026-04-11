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


class Solution {
    long long max (long long a, long long b) { return a > b ? a : b; }
    unordered_map<TreeNode*, long long> nodeSum;
    long long ans = 0;
    long long getSums(TreeNode* root) {
        if (root == NULL)
            return 0;
        nodeSum[root] = (long long) root->val + getSums(root->left) + getSums(root->right);
        return nodeSum[root];
    }

    void getMaxProduct(TreeNode* root, long long totalSum) {
        // partition at root & root-left
        if (root->left != NULL) {
            long long leftSubTree = 
            nodeSum[root->left] * (totalSum - nodeSum[root->left]);
            ans = max(ans, leftSubTree);
            getMaxProduct(root->left, totalSum);
        }

        // partition at root & root-right
        if(root->right!= NULL) {
            long long rightSubTree = 
            nodeSum[root->right] * (totalSum - nodeSum[root->right]);
            ans = max(ans, rightSubTree);
            getMaxProduct(root->right, totalSum);
        }
    }

public:
    int maxProduct(TreeNode* root) {
        getSums(root);
        long long totalSum = nodeSum[root] ;
        getMaxProduct(root, totalSum);
        return ans % 1000000007;
    }
};

// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree