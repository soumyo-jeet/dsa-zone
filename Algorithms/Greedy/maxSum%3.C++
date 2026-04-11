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
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int>rem1, rem2;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 3 == 1) rem1.push_back(nums[i]);
            else if (nums[i] % 3 == 2) rem2.push_back(nums[i]);
            sum+=nums[i];
        }

        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        if(sum % 3 == 0) return sum;
        else if(sum % 3 == 1)
        {
            int op1, op2;
            op1 = rem1.size() >= 1? sum - rem1[0] : 0;
            op2 = rem2.size() >= 2? sum - (rem2[0] + rem2[1]) : 0;

            sum = max(op1, op2);
        }
        else
        {
            int op1, op2;
            op1 = rem2.size() >= 1? sum - rem2[0] : 0;
            op2 = rem1.size() >= 2? sum - (rem1[0] + rem1[1]) : 0;

            sum = max(op1, op2);
        }

        return sum;
    }
};




// We want the maximum possible sum such that it is divisible by 3.
// So first, we take the sum of all elements — this gives the largest possible sum.

// Every number has a remainder when divided by 3 (0, 1, or 2).
// The total sum’s remainder (sum % 3) decides if we need to remove something.

// If the remainder is 0, the sum is already valid.

// If the remainder is 1, we must subtract 1 (mod 3).

// If the remainder is 2, we must subtract 2 (mod 3).

// To fix this, we only need to remove the smallest value(s):

// For remainder 1:
//  remove one element with remainder 1
//  or two elements with remainder 2

// For remainder 2:
//  remove one element with remainder 2
//  or two elements with remainder 1

// From these options, we choose the one that removes the minimum total value,
// so the remaining sum stays maximum.