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

// SWEEP ALGO
int maxTwoEvents(vector<vector<int>> &events)
{
    int maxSum = 0, maxEndedProfit = 0;

    // record the times in a timeline
    vector<pair<int, pair<bool, int>>> timeline;
    for(auto &event : events)
    {
        int start = event[0], end = event[1], profit = event[2];
        // push the start times with true flag and profit
        timeline.push_back({start, {true, profit}});
        // push the exclusive end times with false flag and profit
        timeline.push_back({end + 1, {false, profit}});
    }

    // sort the timeline
    sort(timeline.begin(), timeline.end());

    // access each time from the timeline
    for(auto timeStance : timeline)
    {
        int time = timeStance.first;
        bool isStart = timeStance.second.first;
        int profit = timeStance.second.second;

        if(isStart)
        {
            // take the max profitable event between now ended and prevly ended event
            maxSum = max(maxSum, maxSum + maxEndedProfit);
        }
        else
        {
            // take the max profitable event between now ended and prevly ended event
            maxEndedProfit = max(maxEndedProfit, profit);
        }

        return maxSum;
    }

}