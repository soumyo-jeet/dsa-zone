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

string reverseString(string &s)
{
    int start = 0, end = s.length() - 1;
    string rev = s;
    while (start < end)
    {
        int temp = rev[start];
        rev[start] = rev[end];
        rev[end] = temp;
        start++;
        end--;
    }

    return rev;
}

string reverseByWords()
{
    
}