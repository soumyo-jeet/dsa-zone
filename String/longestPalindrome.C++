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
    int longestPalindrome(string s) {
        // in a palindrom string all chars except one should occur even times

        // map the freq
        unordered_map<char, int> freqMap;
        for(char c : s) freqMap[c]++;

        int count = 0, odd = 0;
        for(auto& it:freqMap)
        {
            if(it.second % 2 == 0)
            {
                // add all the occurance
                count += it.second;
            }

            else 
            {
                // add even number of occs only
                count += it.second - 1;
                // and add an odd ele only for one time
                odd = 1;
            }
        }

        return count + odd;
    }
};

// https://leetcode.com/problems/longest-palindrome/