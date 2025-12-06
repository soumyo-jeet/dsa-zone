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
    bool isPalindrome(string s, int st, int end)
    {
        while(st < end)
        {
            if(s[st] != s[end]) return false;
            st ++; end --;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int start = 0, end = s.length() - 1;
        while(start < end)
        {
            if(s[start] != s[end])
            {
                // check removing start and removing end separetly
                return isPalindrome(s, start + 1, end) || isPalindrome(s, start, end - 1);
            }
            else 
            {
                start++;
                end --;
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/valid-palindrome-ii/