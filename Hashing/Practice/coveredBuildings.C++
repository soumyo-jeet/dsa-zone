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
    int max (int a, int b) {return a > b ? a : b;}
    int min (int a, int b) {return a < b ? a : b;}

    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        // record the max min ys correspond to a particular x
        // do the same for y
        unordered_map<int, int>  minxs, maxxs, minys,maxys;
        for(int i = 0; i < buildings.size(); i++)
        {
            int x = buildings[i][0], y = buildings[i][1];
            minys[x] = minys.find(x) == minys.end() ? y : min(minys[x], y);
            maxys[x] = maxys.find(x) == maxys.end() ? y : max(maxys[x], y);
            minxs[y] = minxs.find(y) == minxs.end() ? x : min(minxs[y], x);
            maxxs[y] = maxxs.find(y) == maxxs.end() ? x : max(maxxs[y], x);
        }

        int covered = 0;
        for(int i = 0; i < buildings.size(); i++)
        {
            int x = buildings[i][0], y = buildings[i][1];
            // some buildings r ploted in the maxs and mins then it is covered
            if(x < maxxs[y] && x > minxs[y] && y < maxys[x] && y > minys[x])
            covered ++;
        }

        return covered;
    }
};