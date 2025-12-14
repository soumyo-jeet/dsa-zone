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

int smallestSubstring(string S)
{
    vector<int> rec(3, 0);
    int ans = INT_MAX, start = 0, end = 0;
    while (end < S.length())
    {
        rec[S[end] - '0']++;

        // open the win untill target becomes missed
        while (rec[0] && rec[1] && rec[2])
        {
            ans = min(ans, end - start + 1);
            rec[S[start] - '0']--;
            start++;
        }

        // slide the win untill target becomes hit
        end++;
    }

    return ans == INT_MAX ? -1 : ans;
}