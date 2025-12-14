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

bool rotateString(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    // doubling the string results into a string which contains all the substr which are possible for the str rotations
    s1 = s1 + s1;
    if (s1.contains(s2)) // available on cpp23+
        return true;
    return false;
}
