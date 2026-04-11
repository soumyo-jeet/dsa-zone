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

int longestMatch (string a, string b) {
    int aLen = a.length(), bLen = b.length();
    vector<vector<int>> LCWDP (a.length() + 1, vector<int> (b.length() + 1, 0));
    int maxL = INT_MIN;
    for(int j = bLen - 1; j >= 0; j--)
    {
        for(int i = aLen - 1; i >= 0; i--) 
        {
            if(a[i] == b[j]) 
            LCWDP[i][j] = 1 + LCWDP[i+1][j+1];
            maxL = max(maxL, LCWDP[i][j]);
        }
    }

    return maxL;
}


int main ()
{
    string a = "bisect";
    string b = "section";
    cout << longestMatch(a, b);
}