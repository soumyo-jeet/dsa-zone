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

string reverseWords(string s)
{
    // reverse the complete str
    reverse(s.begin(), s.end());

    // reverse each words of the string
    int i = 0;
    string ans = "";
    while (i < s.length())
    {
        string word = "";
        while (
            i < s.length() &&
            ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
             (s[i] >= '0' && s[i] <= '9')))
        {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());

        if (word != "")
            ans = ans + word + " ";

        i++;
    }

    // pop out the last extra whitespace
    ans.pop_back();
    return ans;
}