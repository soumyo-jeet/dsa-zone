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
    TreeNode *left, *right;
    char data;
    int freq;

    TreeNode (char c, int f) 
    {
        data = c;
        freq = f;
        left = nullptr;
        right = nullptr;
    }
};

class customSort 
{
    public:
    bool operator() (TreeNode *& a, TreeNode *& b) {
        return a->freq > b->freq;
    }
};

TreeNode *createTree (vector<pair<char, int>> &dataMap) 
{
    priority_queue<TreeNode *, vector<TreeNode *>, customSort> pq;
    for(auto &data : dataMap) 
    {
        TreeNode *dataNode = new TreeNode(data.first, data.second);
        pq.push(dataNode);
    }

    while(pq.size() > 1) 
    {
        TreeNode *left = pq.top();
        pq.pop();
        TreeNode *right = pq.top();
        pq.pop();

        TreeNode *parent = new TreeNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    TreeNode *root = pq.top();
    return root;
}

void encode (TreeNode *root, vector<string>& codes, vector<char>& datas, string& code) 
{
    if(!root) return;

    cout << root->data << " - > " << root->freq << endl;
    // leaf
    if(root->left == root->right) 
    {
        codes.push_back(code);
        datas.push_back(root->data);
    }

    // left
    code.push_back('0');
    encode(root->left, codes, datas, code);
    code.pop_back();

    // right
    code.push_back('1');
    encode(root->right, codes, datas, code);
    code.pop_back();
}

int main()
{
    int n;
    cin >> n;
    vector<pair<char, int>> dataMap;
    for(int i = 0; i < n; i++) 
    {
        char c;
        int freq;
        cout << "Char: ";
        cin >> c;
        cout << "Freq: ";
        cin >> freq;

        dataMap.push_back({c, freq});
    }

    TreeNode *root = createTree(dataMap);

    vector<string> codes;
    vector<char> datas;

    string code = "";
    encode(root, codes, datas, code);

    for(int i = 0; i < codes.size(); i++)
    {
        cout << datas[i] << " -> " << codes[i] << endl;
    }
}