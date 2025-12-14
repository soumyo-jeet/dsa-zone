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

bool metaStrings(string S1, string S2) {
    if(S1 == S2 || S1.length() != S2.length()) return false;
    
    unordered_map<char, int> freq;
    // count freq of each word in S1
    for(int i = 0; i < S1.length(); i++) freq[S1[i]]++;
    // decrease freq of the word if it's found in S2
    for(int i = 0; i < S2.length(); i++) freq[S2[i]]--;
    
    // check if all values in the freq map is 0 => if not S1 and S2 has different word => can,t be meta
    for(auto& it: freq) if(it.second != 0) return false;
    
    // now count position mismatches 
    int mismatches = 0, f = 0, s = 0;
    while(s < S2.length() || f < S2.length())
    {
        if(S1[f] != S2[s]) mismatches++;
        f++; s++;
    }
    
    if(mismatches == 2) return true;
    return false;
}