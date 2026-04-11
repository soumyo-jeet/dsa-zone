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
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum (nums.size());
        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        int count = 0;
        unordered_map<int, int> freqMap;
        for(int j = 0; j < nums.size(); j++)
        {
            // find the excess to be k in the sum of the subarray [0...j]
            int excess = prefixSum[j] - k;
            
            // no excess -> the subarray should be taken into consideration
            if(!excess) count++;
            
            // find the excess in i < j
            if(freqMap.find(excess) != freqMap.end())
            {
                count+= freqMap[excess];
                // number of excess == number of subarray can be formed excluding the previous part to get required subarray 
            }
            
            // store the prefix sum freq to the map
            freqMap[prefixSum[j]]++;
        }

        return count;
    }
};