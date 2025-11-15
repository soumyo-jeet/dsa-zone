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

// no of 1s before one serise of 0 = no of operations have done before that serise of 0

int maxOperations(string s)
{
    int opts = 0, ones = 0, n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ones++;
        }
        else if ((i > 0) && s[i - 1] == '1')
        {
            opts += ones;
        }
    }

    return opts;
}