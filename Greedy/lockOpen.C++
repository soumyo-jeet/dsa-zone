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

// PS -> Given a lock made up of N different circular rings. Each ring has 0-9 digit printed on it. There is only one particular code which can open the lock. You can rotate each ring any number of times in either direction. Given the random sequence R and the desired sequence D, find the minimum number of rotations required to open the lock. 

// greedy approach -> rotate in the direction to which the desired step can be reached faster 
class Solution {
  public:
    int rotationCount(long long R, long long D) {
        int total = 0;
        while(R)
        {
            long long s = R % 10;
            long long t = D % 10;
            
            long long d = abs(t - s);
            if(d > 5) d = 10 - d;
            total+=d;
            
            R = R / 10;
            D = D / 10;
        }
        
        return total;
    }
};