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


// all computers it can be unlocked if their complexity is < 0th one 
// and can be arranged in (n-1)! ways
int countPermutations(vector<int> &complexity)
{
    long long fact = 1, n = complexity.size();
    for (int i = 1; i < n; i++)
    {
        if (complexity[i] <= complexity[0])
            return 0;
        fact = (fact * i) % 1000000007;
    }
    return fact;
}