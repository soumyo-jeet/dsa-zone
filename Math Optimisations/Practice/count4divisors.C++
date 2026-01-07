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

int solve (vector<int> arr)
{
    int ans = 0;
    for(int n: arr){
        int rootn = sqrt(n);
        int cnt = 1, sum = 1;
        for(int j = 1; j <= rootn; j++)
        {
            if(n % j == 0) {
                cnt++;
                sum += j;
            }
        }
        if(cnt == 4) ans = sum;
    }

    return ans;
}