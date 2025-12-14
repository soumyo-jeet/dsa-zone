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

int remAnagram(string &s1, string &s2)
{

    if (s1.length() != s2.length())
        return false;
    unordered_map<char, int> freq;
    int i = 0, j = 0;

    // increase freq while it occurs in s1 and decrease while in s2
    while (s1[i] != '\0')
        freq[s1[i++]]++;
    while (s2[j] != '\0')
        freq[s2[j++]]--;

    int rem = 0;
    // the freq map now stores the rest freq of chars which make the string non anagram
    for (auto &it : freq)
    {
        rem += abs(it.second);
    }

    return rem;
}