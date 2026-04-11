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
    int isInRange (int t)
    {
        return (t >= 1 && t < 10);
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        vector<pair<int, int>> startMap;
        // the starting indices of all possible 3 X 3 grids
        for (int i = 0; i + 2 < grid.size(); i++) {
            for (int j = 0; j + 2 < grid[0].size(); j++) {

                vector<int> used (10, 0);
                int k = 0;
                for(; k < 3; k++)
                {
                    int curr1 = grid[i + k][j], 
                    curr2 = grid[i + k][j + 1], curr3 = grid[i + k][j + 2];
                    if((isInRange(curr1) && used[curr1] == 0))  {
                        used[curr1] = 1;
                    }
                    else break;

                    if(isInRange(curr2) && used[curr2] == 0) {
                        used[curr2] = 1;
                    }
                    else break;

                    if(isInRange(curr3) && used[curr3] == 0) {
                        used[curr3] = 1;
                    }
                    else break;
                }
                cout << grid[i][j] << " ";
                if(k == 3) startMap.push_back({i, j});
            }
        }
        
        int count = 0;
        for (auto point : startMap) {
            int startR = point.first;
            int startC = point.second;
            int ideal = grid[startR][startC] + 
            grid[startR][startC + 1] + grid[startR][startC + 2];

            int flag = 0;
            // verify other rows
            for (int i = startR + 1; i < startR + 3; i++) {
                int rowSum = grid[i][startC] + 
                grid[i][startC + 1] + 
                grid[i][startC + 2];

                if (ideal != rowSum) {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            // verify cols
            for (int j = startC; j < startC + 3; j++) {
                int colSum = grid[startR][j] + 
                grid[startR + 1][j] + grid[startR + 2][j];
                if (ideal != colSum) {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;

            // verify diags
            int diagSum = grid[startR][startC] + 
            grid[startR + 1][startC + 1] + 
            grid[startR + 2][startC + 2];
            if(diagSum != ideal) continue;

            int revdiagSum = grid[startR][startC + 2] + 
            grid[startR + 1][startC + 1] + 
            grid[startR + 2][startC];
            if(revdiagSum != ideal) continue;

            count ++;
        }

        return count;
    }
};