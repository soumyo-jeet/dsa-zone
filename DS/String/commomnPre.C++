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
    int min (int a, int b)
    {
        return a < b ? a : b;
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        string ideal = strs[0];
        int e = ideal.length();

        for(int i = 1; i < strs.size(); i ++)
        {
            int p1 = 0, p2 = 0;
            while(p1 < ideal.length() && p2 < strs[i].length())
            {
                if(ideal[p1] != strs[i][p2]) break;
                p1++; p2++;
            } 

            e = min(e, p1);
        }

        string ans = "";
        for(int i = 0; i < e; i++)
        {
            ans+= ideal[i];
        }

        return ans;
    }
};