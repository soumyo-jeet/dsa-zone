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


string solve(string A, int B) {
    string ans = "";
    int s = 0, e = 0;
    while(e < A.length())
    {
        int consc = 0;
        // measure consecutive char len
        while(A[s] == A[e])
        {
            consc ++; e++;
        }
        
        if(consc != B) 
        {
            // the part [s, e) can be a part of ans
            ans += A.substr(s, e - s);
        }
        
        s = e;
        e = s;
    }
    
    
    return ans;
}
