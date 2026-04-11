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

// SWEEP LINE + GREEDY
// Goal: Pick at most 2 non-overlapping events such that total profit is maximum
int maxTwoEvents(vector<vector<int>> &events)
{
    // Stores the final answer
    int maxSum = 0;

    // Stores the best profit among all events that have already ended
    int maxEndedProfit = 0;

    /*
        We convert all events into timeline points.
        Each event becomes:
            (start_time, isStart=true, profit)
            (end_time+1, isStart=false, profit)
        end+1 is used so that events ending at time t
        do NOT overlap with events starting at time t+1.
    */
    vector<pair<int, pair<bool, int>>> timeline;

    for(auto &event : events)
    {
        int start = event[0], end = event[1], profit = event[2];

        // Start marker of an event
        timeline.push_back({start, {true, profit}});

        // End marker (exclusive)
        timeline.push_back({end + 1, {false, profit}});
    }

    // Sort all time points so we sweep from left to right in time
    sort(timeline.begin(), timeline.end());

    /*
        We sweep through time.
        At any moment:
        - maxEndedProfit holds the best profit of events that are already finished
        - when a new event starts, we try to pair it with the best finished one
    */
    for(auto timeStance : timeline)
    {
        int time = timeStance.first;              // current time
        bool isStart = timeStance.second.first;  // start or end of event
        int profit = timeStance.second.second;   // profit of that event

        if(isStart)
        {
            /*
                A new event is starting.
                We try to combine it with the best event that already ended.
                Greedy idea:
                best finished event + this event → candidate for answer
            */
            maxSum = max(maxSum, profit + maxEndedProfit);
        }
        else
        {
            /*
                An event just ended.
                Update the best profit among all finished events.
            */
            maxEndedProfit = max(maxEndedProfit, profit);
        }
    }
    return maxSum;
}