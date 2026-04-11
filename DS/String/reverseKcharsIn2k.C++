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

int min(int a, int b)
{
    return a < b ? a : b;
}

string reverseStr(string s, int k)
{
    int start = 0;
    while (start < s.length())
    {
        // determine the end -> k window span from the start
        int end = min(start + k, s.length());

        // reverse between start and end
        reverse(s.begin() + start, s.begin() + end);

        // fix the next starting point
        start += 2 * k;
    }

    return s;
}