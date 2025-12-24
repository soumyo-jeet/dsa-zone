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
    

    int minDeletionSize(vector<string>& strs) {
        int delcount = 0;
        // alreadySorted[i] -> row till i+1 is sorted
        vector<bool> alreadySorted (strs.size() - 1, 0); 

        for(int j = 0; j < strs[0].length(); j++)
        {
            for(int i = 0; i < strs.size() - 1; i++)
            {
                // recent row is not sorted + recent col is not sorted
               if(!alreadySorted[i] && strs[i+1][j] < strs[i][j])
               {
                    delcount++;
                    goto end;
               }
            }

            // mark the rows as sorted which are strictly increasing
            // otherwise before evaluating the next col 
            // we cant determine that row as sorted
            for(int i = 0; i < strs.size() - 1; i++)
            {
                if(strs[i+1][j] > strs[i][j]) alreadySorted[i] = 1;
            }

            end:;
        }

        return delcount;
    }
};