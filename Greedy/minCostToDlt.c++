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
    long long max (long long a, long long b) {return a > b ? a : b; }
public:
    long long minCost(string s, vector<int>& costs) {
        // find the max cost for keeping one character and its all occurance
        unordered_map<char, long long> alphaCosts;
        long long totalCost = 0;
        for(long long i = 0; i < costs.size(); i++)
        {
            totalCost += costs[i];
            alphaCosts[s[i]] += costs[i];
        }

        long long maxCost = -1;
        for(auto it : alphaCosts)
        {
            maxCost = max(maxCost, it.second);
        }

        return totalCost - maxCost;
    }
};


// https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal/