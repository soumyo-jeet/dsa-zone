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


int totalPossible (int total, int n, int target, int id, int coins[1000], vector<vector<int>> &memoTb)  {
    if(total == target) return 1;
    if(total > target || coins[id] == 0) return 0;
    if(memoTb[total][id] != -1) return memoTb[total][id];

    int ways = 0;
    for(int i = id; i < n; i++) {
        ways += totalPossible(total + coins[i], n, target, i, coins, memoTb);
    }

    return memoTb[total][id] = ways;
}

int totalPossible_ (int n, int target, int coins[1000]) {
    vector<vector<int>> memoTb (target + 1, vector<int> (n, 0));
    
    for(int id = 0; id < n; id++) {
        memoTb[target][id] = 1;
    }

    for(int total = target - 1; total >= 0; total--) {
        for(int id = n - 1; id >= 0; id --) {

            int ways = 0;
            for(int i = id; i < n; i++) {
                if(coins[i] + total <= target) {
                    ways += memoTb[coins[i] + total][i];
                }
            } 

            memoTb[total][id] = ways;
        }
    }

    return memoTb[0][0];
}

int main () {
    int n;
    cout << "Coin present: ";
    cin >> n;

    int coins [n];

    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int t;
    cout << "Enter target: ";
    cin >> t;

    vector<vector<int>> memoTb (t + 1, vector<int> (n, -1));
    cout << totalPossible(0, n, t, 0, coins, memoTb);
    cout << endl << "BU: " << totalPossible_(n, t, coins);

}