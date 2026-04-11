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

// Kadan's Algo
//

vector<int> prefixSum(vector<int> arr)
{
    vector<int> ans(arr.size());
    ans[0] = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        ans[i] = arr[i - 1] + arr[i];
    }

    return ans;
}

int maxSum(vector<int> arr)
{
    /*
        Kadane’s Algorithm
        ------------------
        Goal:
        Find the maximum sum of any contiguous subarray.

        Key idea:
        At every index i, decide:
        1) Should we EXTEND the previous subarray?
        2) Or START a new subarray from arr[i]?
    */

    int currSum = 0;
    /*
        currSum represents:
        -> maximum subarray sum ending exactly at index (i - 1)
        -> helps us decide whether extending is beneficial or not
    */

    int maxSum = INT_MIN;
    /*
        maxSum stores:
        -> the maximum subarray sum found so far
        -> initialized to INT_MIN to handle all-negative arrays
    */

    for (int i = 0; i < arr.size(); i++)
    {
        /*
            If we extend the previous subarray,
            the new sum becomes:
            arr[i] + currSum
        */
        int subarraySum = arr[i] + currSum;

        /*
            Decision step (heart of Kadane’s):
            --------------------------------
            Compare:
            1) Start new subarray at index i → arr[i]
            2) Extend previous subarray      → subarraySum

            Choose whichever gives the larger sum
        */
        currSum = max(subarraySum, arr[i]);

        /*
            Update global maximum
            -> currSum is the best subarray ending at i
            -> maxSum tracks the best seen anywhere
        */
        maxSum = max(maxSum, currSum);
    }

    /*
        After loop ends,
        maxSum contains the maximum subarray sum
    */
    return maxSum;
}


int main()
{
    vector<int> arr;
    int s;
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << maxSum(arr);
}