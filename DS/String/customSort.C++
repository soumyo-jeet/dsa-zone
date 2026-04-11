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
    string customSortString(string order, string s) {
        map<char, int> chars;
        vector<int> lefts;
        for(int i = 0; i < order.length(); i++)
        {
            chars[order[i]] = 0;
        }

        for(int i = 0; i < s.length(); i++)
        {
            if (chars.find(s[i]) != chars.end()) chars[s[i]]++;
            else lefts.push_back(i);
        }

        string ans = "";
        for(int i = 0; i < order.length(); i++)
        {
            while(chars[order[i]]--) ans += order[i];
        }

        for(int i = 0; i < lefts.size(); i++) ans+=s[lefts[i]];
        return ans;
    }

};

// https://leetcode.com/problems/custom-sort-string/