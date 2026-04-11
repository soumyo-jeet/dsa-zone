// Segment Tree -> A complete binary tree holds informations of each segment of an given array (sum, min, max)
//      -> It can be created using 2 * n time ~ O(n) and 2 * n space O(n)
//      

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

void buildSegmentTree (vector<int>& arr, vector<int>& segTree, int l, int r, int i) 
{
    if(l==r) 
    {
        segTree[i] = arr[l];
        return;   
    }

    int mid = l + (r - l) / 2;
    buildSegmentTree (arr, segTree, l, mid, 2 * i + 1); // left child at 2 * i + 1
    buildSegmentTree (arr, segTree, mid+1, r, 2 * i + 2); // right child at 2 * i + 2
    // intermediate nodes val = sum of its 2 children nodes
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

int rangeSumQuery (vector<int> segTree, int l, int r, int i, int rs, int re) 
{
    if(r < rs || l > re) return 0; // out of target range
    if(l >= rs && r <= re) return segTree[i]; // tight in target range
    // otherwise
    int mid = l + (r - l) / 2;
    int sum = rangeSumQuery(segTree, l, mid, 2 * i + 1, rs, re) // dive into the left 
    + rangeSumQuery(segTree, mid+1, r, 2 * i + 2, rs, re) ; // dive into the right 

    return sum;
}

int main () 
{
    vector<int> arr;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    vector<int> segTree(2 * n);
    buildSegmentTree(arr, segTree, 0, n - 1, 0);

    for(int s: segTree) cout << s << " ";
    int rs, re;
    cin >> rs >> re;
    cout << rangeSumQuery(segTree, 0, n - 1, 0, rs, re);
}