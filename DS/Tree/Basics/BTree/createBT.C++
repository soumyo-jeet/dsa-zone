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

class Block;
class Node {
    public:
    int val;
    Block *left;
    Block *right;

    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

class Block {
    public:
    vector<Node *> b;
    int blockSize;

    Block (int s)
    {
      blockSize = s; 
    }
};

int findPos(int x, Block *block)
{
    int i = 0;
    for(int i = 0; i < block->b.size(); i++)
    {
        if(x > block->b[i]->val) break;
    }

    return i;
}

void insertInB(int pos, Block *block, Node *node)
{
    if(pos >= block->b.size()) block->b.push_back(node);
    else
    {
        // shift the elements to the right
        block->b.push_back(block->b[block->b.size() - 1]);
        for(int i = block->b.size() - 2; i >= pos; i --)
        {
            block->b[i+1] = block->b[i];
        }

        // insert the node at the pos
        block->b[pos] = node;
    }
}

Block *createNewBlock (vector<Node *> ele, int st, int e)
{
    Block *newBlock = new Block(3);
    for(int i =st; i <= e; i++)
    {
        newBlock->b.push_back(ele[i]);
    }
    return newBlock;
}

Block *splitAt(int pos, Block *block, Node *node)
{
    Block *newRoot = new Block(block->blockSize);
    Block *left = createNewBlock(block->b, 0, pos-1);
    Block *right = createNewBlock(block->b, pos, block->b.size()-1);
    node->left = left;
    node->right = right;

    newRoot->b.push_back(node);
    return newRoot;
}

Block *insert(Block *root, int x)
{
    // create the node
    Node *node = new Node(x);

    // check the insertion position
    int p = findPos(x, root);

    // if block has no child => leaf node
    if(root->b[p]->left == NULL && root->b[p]->right == NULL) 
    {
        if(root->blockSize != 0) 
        {
            insertInB(p, root, node);
            return root;
        }

        // split when position is not the last index of the block
        else if(p != root->blockSize - 1)
        {
            root = splitAt(p, root, node);
            return root;
        }
        // split when position is the last index of the block
        else
        {
            // split has to perform by the last element 
            Node *splitIndx = root->b[p];

            // update the position with the upcoming node
            root->b[p]= node;
            
            root = splitAt(p, root, splitIndx);
            return root;
        }
    }

    // not leaf nodes => traverse to reach leaf nodes
    if(x < root->b[p]->val) root->b[p]->left = insert(root->b[p]->left, x);
    else root->b[p]->right = insert(root->b[p]->right, x);
    
    return root;
}

int main()
{
    Block *root = new Block(3);
    int x;
    cout << "Enter element: ";
    cin >> x;

    while(x != -1)
    {
        root = insert(root, x);
        cout << "Enter element: ";
        cin >> x;
    }


    cout << "Tree is created at "<< root;
}