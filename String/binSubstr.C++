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

int binarySubstring(string &s)
{
    int ones = 0;
    // count total '1'
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            ones++;
    }

    // total possible substr = onesC2
    // sub having '1' at end and start will be valid => total valids = no of possible ways to select 1 for 2 places
    return ones * (ones - 1) / 2;
}