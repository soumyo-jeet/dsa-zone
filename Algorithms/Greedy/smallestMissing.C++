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
    int firstMissingPositive(vector<int>& arr) {
        vector<int> record(arr.size(), 0);
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] > 0 && arr[i] <= arr.size()) 
            record[arr[i] - 1] ++;
        }
        

        for(int i = 0; i < record.size(); i++)
        {
            if(record[i] == 0) return i+1;
        }
        
        return arr.size() + 1;
    }
};