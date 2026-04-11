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
public:
    int countNegatives(vector<vector<int>>& grid) {
        int d = 0, l = grid[0].size()-1, count = 0;
        while(d < grid.size() && l >= 0)
        {
            if(grid[d][l] <= -1) {
                count += grid.size() - d;
                l--;
            }
            else d++;
        }
        return count;

    }
};