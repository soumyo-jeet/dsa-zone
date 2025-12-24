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

// Optimised / foolish
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // Sort the capacities in desc order
        sort(capacity.begin(), capacity.end(),
             [](int a, int b) { return a > b; });


        int boxes = 1, capi = 0, capac = capacity[capi++], left = 0;
        for (int app : apple) {
            // evaluate the current apple count
            int curr = left + app;
            left = curr - capac;

            if (left > 0) {
                // increase capacity
                capac += capacity[capi++];
                // box count
                boxes++;
                // send the complete app count as left
                left = curr;
            }

            else {
                // decrease the capacity of current box
                capac -= curr;
                
                left = 0;
            }
        }

        // do the same for still left apples
        while (left > 0 && capi < capacity.size()) {
            int curr = left;
            left = left - capac;
            if (left > 0) {
                capac += capacity[capi++];
                boxes++;
                left = curr;
            }
        }

        return boxes;
    }
};


// optimised / clever
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        // eval the total capacity needed
        int sum = accumulate(apple.begin(), apple.end(), 0);

        sort(cap.begin(), cap.end(), greater<int>());

        int res = 0;
        while (sum > 0)
            // box count ++ untill the total cpacity need fullfilled
            sum -= cap[res++];

        return res;
    }
};
