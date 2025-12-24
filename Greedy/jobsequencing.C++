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

// greedy approach -> book each time slot within the max deadline with the most proftable jobs available within that slot
class Solution {
  public:
    int find(int num, vector<int> &slots)
    {
        if(num == slots[num]) return num;
        return slots[num] = find(slots[num], slots);
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>> jobs;
        for(int i = 0; i < profit.size(); i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        
        // sort by profit descending
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        int maxD = INT_MIN;
        for(int i = 0; i < deadline.size(); i++)
        {
            maxD = max(maxD , deadline[i]);
        }
        
        // job slots
        vector<int> slots(maxD+1);
        for(int i = 0; i < slots.size(); i++)
        {
            slots[i] = i;
        }
                
        int jC = 0, pC = 0;
        for(int i = 0; i < jobs.size(); i ++)
        {
            int p= jobs[i].first, d = jobs[i].second;
            // search for available 1 unit slot before the deadline to accomplish it
            int slot = find(d, slots);
            if(slot>0)
            {
                pC+= p;
                jC++;
                slots[slot]--;
            }
        }
        
        
        vector<int> ans;
        ans.push_back(jC);
        ans.push_back(pC);
        
        return ans;
    }
};