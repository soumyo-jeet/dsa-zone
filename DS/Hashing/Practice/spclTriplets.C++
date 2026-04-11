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
    int specialTriplets(vector<int>& nums) {
        long long count = 0;
        for(int j = 1; j < nums.size() - 1; j++)
        {
            long long lft = 0 ,right = 0;
            for(int i = 0; i < j; i++)
            {
                if(2 * nums[j] == nums[i]) {
                    lft += 1;
                }
            }

            for(int k = j + 1; k < nums.size(); k++)
            {
                if(2 * nums[j] == nums[k]) {
                    right += 1;
                }
            }

            if(lft && right) count = (count + lft * right)% (1000000007);
        }

        return count ;
    }
};

// two pass
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long count = 0;
        unordered_map<int, long long> freq_right;
        for(int num: nums)
        {
            freq_right[num]++;
        }

        unordered_map<int, long long> left_freq;
        for(int num: nums)
        {
            // decrease the count of the num at from right record
            freq_right[num]--;

            // find for 2x at left and right record
            if(freq_right.find(2 * num) != freq_right.end() && 
            left_freq.find(2 * num) != left_freq.end())
            {
                count = (count += freq_right[2 * num] * left_freq[2 * num]) % 1000000007;
            }
            
            // increase at left record
            left_freq[num]++;
        }

        return count ;
    }
};