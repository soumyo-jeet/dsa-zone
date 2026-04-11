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

// PS-> Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10 } and a target value n. Find the minimum number of coins and/or notes needed to make the change for Rs n. 


// greedy approach -> find the nearest coin of the amount left
class Solution {
  public:
    int findMin(int amount) {
        int coins [4] = { 1, 2, 5, 10 };
        int amountLeft = amount, totalC = 0;
        while(amountLeft > 0)
        {
            int minC = INT_MAX, maxA = coins[0];
            for(int coin: coins)
            {
                int c = amountLeft / coin;
                if(c > 0 && c < minC)
                {
                    minC = c;
                    maxA = coin;
                }
            }
            if(minC == INT_MAX) break;
            amountLeft %= (maxA * minC);
            totalC+= minC;
        }

        if(amountLeft > 0) return -1;
        return totalC;
    }
};