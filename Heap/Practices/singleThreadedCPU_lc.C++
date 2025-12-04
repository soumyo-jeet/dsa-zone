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
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        // record the task's actual index to the tasks
        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }

        // sort the tasks based on their enqueue time
        sort(tasks.begin(), tasks.end());

        // set the starting time to the first enqueue time
        long long st = tasks[0][0];

        // push the available tasks into a minheap to get task with minimum
        // processing time
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        // initialise the heap with the available tasks at the first st
        int i = 0;
        while (i < tasks.size() && st >= tasks[i][0]) {
            pq.push({tasks[i][1], tasks[i][2]});
            i++;
        }

        // start storing the task sequences
        while (!pq.empty()) {

            // pop out the task with minimum pt
            auto ctask = pq.top();
            long long pt = ctask.first;
            long long ti = ctask.second;
            pq.pop();

            // add the task to ans and update the time
            ans.push_back(ti);
            st += pt;

            // update the heap with the available tasks in the time
            while (i < tasks.size() && st >= tasks[i][0]) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }


            // empty heap may =>s next task is delayed too much than the current st so handle it in this way
            if (i < tasks.size() && pq.empty()) {
                st = tasks[i][0];
                while (i < tasks.size() && st >= tasks[i][0]) {
                    pq.push({tasks[i][1], tasks[i][2]});
                    i++;
                }
            }
        }

        return ans;
    }
};