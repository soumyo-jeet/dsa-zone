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

// PS -> You are given two arrays mices[] and holes[] of the same size. The array mices[] represents the positions of the mice on a straight line, while the array holes[] represents the positions of the holes on the same line. Each hole can accommodate exactly one mouse. A mouse can either stay in its current position, move one step to the right, or move one step to the left, and each move takes one minute. The task is to assign each mouse to a distinct hole in such a way that the time taken by the last mouse to reach its hole is minimized

// greedy apprach -> put nearer mice to nearer hole
class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // sort the holes and mices distances
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int maxD = INT_MIN;
        for(int i = 0; i < mices.size(); i++)
        {
            int dist = abs(holes[i] - mices[i]);
            maxD = dist > maxD ? dist : maxD;
        }
        
        return maxD;
    }
};