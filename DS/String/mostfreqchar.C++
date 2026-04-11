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
    char getMaxOccuringChar(string& s) {
        unordered_map <char, int> freqMap;
        int i = 0;
        while(s[i] != '\0')
        {
            freqMap[s[i++]]++;
        }
        
        char maxc = s[0]; int maxf = freqMap[maxc];
        for(auto& it : freqMap)
        {
            if(it.second == maxf && it.first < maxc)
            {
                maxc = it.first;
                maxf = it.second;
            }
            
            if(it.second > maxf)
            {
                maxc = it.first;
                maxf = it.second;
            }
        }
        
        return maxc;
    }
};