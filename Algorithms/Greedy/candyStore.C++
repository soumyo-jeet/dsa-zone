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

// PS -> In a candy store, there are different types of candies available and prices[i] represent the price of  ith types of candies. You are now provided with an attractive offer.
// For every candy you buy from the store, you can get up to k other different candies for free. Find the minimum and maximum amount of money needed to buy all the candies.
// Note: In both cases, you must take the maximum number of free candies possible during each purchase.

// greedy approach -> 
// min -> BUY the cheapest candy, get k free most expensive candies
// max -> BUY the most expensive one, get k free most cheap candies
class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // sort the prices
        sort(prices.begin(), prices.end());
        
        int n = prices.size(), min = 0, max = 0;
        int s = 0, e = n - 1;
        while(s <= e)
        {
            min+= prices[s];
            s++;
            e-=k;
        }
        
        s = 0, e = n - 1;
        while(s <= e)
        {
            max+= prices[e];
            e--;
            s+=k;
        }
        
        vector<int> ans;
        ans.push_back(min);
        ans.push_back(max);
        
        return ans;
    }
};