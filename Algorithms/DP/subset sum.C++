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
    int dp[201][100 * 201];
    void initDp() {
        for(int i = 0; i < 201; i++) {
            for(int j = 0; j < 100 * 201; j++) {
                dp[i][j] = -1;
            }
        }
    }

    // Recc
    bool solve(int n, int sum, int totalSum, vector<int>& nums) {
        if(2 * sum == totalSum) return true;
        if(n == 0) return false;
        if(dp[n][sum] != -1) return dp[n][sum];

        bool skip = solve(n - 1, sum, totalSum, nums),
        take = solve(n - 1, sum + nums[n - 1], totalSum, nums);

        return dp[n][sum] = skip || take;
    }

    // Bottom up
    bool solve2 (int totalSum, vector<int>& nums) {
        int target = totalSum / 2,
        n = nums.size();

        vector<vector<int>> tb (n + 1, vector<int> (target + 1, 0));

        // using 0 elements getting sum == 0 is only possible way
        tb[0][0] = 1;


        // fill the sack
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= target ; j++) {
                bool skip = tb[i - 1][j] ,
                take = j >= nums[i - 1] ? tb[i - 1][j - nums[i - 1]]: 0;

                // is possible to get sum == j with i elemnets from the array
                tb[i][j] = skip || take;
            }
        }

        // is possible to get sum == target with n elemnets from the array
        return tb[n][target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(sum % 2) return false;

        return solve2(sum, nums);
    }
};