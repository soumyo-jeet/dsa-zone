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
    int isVowel(char s){

        return (s == 'a' || s == 'e' || s == 'i' || s == 'o' ||
                s == 'u');

    }

    string reverseWords(string s) {

        int ideal = -1;
        int currc = 0, start = -1;
        for (int i = 0; i < s.length(); i++) {
            // word continuing
            if (s[i] != ' ') {
                if (isVowel(s[i]))
                    currc++;
            } else {
                // end of one word
                if (ideal == -1) {
                    ideal = currc;

                } else if (currc == ideal) {
                    // relative selection of words
                    reverse(s.begin() + start, s.begin() + i);
                }

                // reset the count
                currc = 0;
                // store the next word start
                start = i + 1;
            }
        }

        // last word
        if (currc == ideal)
            reverse(s.begin() + start, s.end());
        return s;
    }
};