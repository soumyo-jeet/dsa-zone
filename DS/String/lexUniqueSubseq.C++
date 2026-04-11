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
    string smallestSubsequence(string s) {
        vector<int> visited(26, 0);
        vector<int> lastId(26);
        stack<char> chars;

        for (int i = 0; i < s.length(); i++)
            lastId[s[i] - 'a'] = i;

        for (int i = 0; i < s.length(); i++) {
            if (visited[s[i] - 'a'] == 1)
                continue;

            while (!chars.empty() && chars.top() > s[i] &&
                   lastId[chars.top() - 'a'] > i) {
                char temp = chars.top();
                visited[temp - 'a'] = 0;
                chars.pop();
            }

            chars.push(s[i]);
            visited[s[i] - 'a'] = 1;
        }

        string ans = "";
        while (!chars.empty()) {
            ans += chars.top();
            chars.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};