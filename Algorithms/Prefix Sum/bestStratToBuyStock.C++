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


// O(n) - O(1)
class Solution {
public:
    long long max(long long a, long long b)
    {
        return a > b ? a : b;
    }

    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        // evaluate the profits
        vector<long long> profits(prices.size());
        long long origProfit = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            profits[i] = 1LL* strategy[i] * prices[i];
            origProfit += profits[i];
        }

        int k2 = k / 2, i = 0, j = 0;
        long long modified = 0, orig=0, maxPossible = 0;
        while(i + k - 1 < prices.size())
        {
            orig += profits[j];
            if(j - i >= k2) modified += prices[j];
            if(j - i + 1 == k) {
                maxPossible = max(maxPossible, (modified - orig));
                orig -= profits[i];
                modified -= prices[i+k2];
                i++;
            }
            j++;
        }
        
        return max(origProfit, origProfit + maxPossible);
    }
};



// O(n * k)

class Solution {
public:
    // Custom max function for long long values
    long long max(long long a, long long b)
    {
        return a > b ? a : b;
    }
    
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {

        // Prefix sum array to store cumulative original profit till index i
        vector<int> proPreSum(prices.size());

        // Profit for day 0 = strategy[0] * prices[0]
        proPreSum[0] = strategy[0] * prices[0];

        // Build prefix sum of original profits
        for(int i = 1; i < prices.size(); i++)
        {
            // profit till i = profit till i-1 + profit on day i
            proPreSum[i] = proPreSum[i - 1] + (1LL * strategy[i] * prices[i]);
        }

        // k2 = size of second half of window where modification applies
        int k2 = k / 2;

        // i -> window start, j -> current index inside window
        int i = 0, j = 0;

        // itr counts elements processed inside the current window
        int itr = 1;

        // modified stores profit of modified strategy for current window
        long long modified = 0;

        // maxPossible stores maximum profit improvement found so far
        long long maxPossible = 0;

        // Loop while a full window of size k can exist
        while(i + k - 1 < prices.size())
        {
            // First k/2 elements contribute zero profit in modified strategy
            if(itr <= k2) 
                modified += 0;

            // Remaining k/2 elements contribute prices[j]
            else 
                modified += prices[j];

            // If window size k is completed
            if(itr == k) {

                // Reset window counter
                itr = 1;

                // Original profit of current window [i...j]
                int origWinPro = proPreSum[j] - (i > 0 ? proPreSum[i-1] : 0);

                // Modified profit for the same window
                int modWinPro = modified;

                // Track maximum profit gain from modification
                maxPossible = max(maxPossible, (modWinPro - origWinPro));

                // Debug output (prints intermediate max gain)
                cout << maxPossible << " ";

                // Reset modified profit for next window
                modified = 0; 

                // Slide window start by 1
                i++; 

                // Reset j to new window start
                j = i;   
            }
            else {
                // Move to next element inside window
                itr++;
                j++;
            }
        }
        
        // Return max of:
        // 1) original total profit
        // 2) original profit + best possible improvement
        return max(
            proPreSum[proPreSum.size() - 1],
            proPreSum[proPreSum.size() - 1] + maxPossible
        );
    }
};
