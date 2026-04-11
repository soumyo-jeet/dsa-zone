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
    int maximizeSquareHoleArea(int n, int m, vector<int>& vBars, vector<int>& hBars) {

       sort(vBars.begin(), vBars.end());
       sort(hBars.begin(), hBars.end());

       // find max consecutive bars in h bars
       int h = 1, maxh = 1;
       for(int i = 1; i < vBars.size(); i++)
       {
            if(vBars[i] - vBars[i - 1] == 1) {
                h++;
                maxh = max(h, maxh);
            }
            else h = 1;
       }

       // find max consecutive bars in v bars
       int w = 1, maxw =1;
       for(int i = 1; i < hBars.size(); i++) {
            if(hBars[i] - hBars[i - 1] == 1) {
                w++;
                maxw = max(w, maxw);
            }
            else w = 1;
        }

        int acc = min(maxh, maxw);
        return max(1, (acc + 1)*(acc + 1));
    }
};