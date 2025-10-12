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

// each row and each col is sorted in ascending order
// hence if we start traversing from the last of each row
// as we move to left we will get lesser values and to down will get greater values
// as the element is max of the row (left) and min of the col (down)
// hence starting from the last element of the first row
// will move left if target is lesser and down if it is greater

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int s = 0, e = matrix.size() - 1, l = matrix[0].size()-1, d = 0;
    while(l >= s && d <= e)
    {
        if(matrix[d][l] == target) return 1;
        else if(matrix[d][l] < target) d++;
        else l--;
    }
    return 0;
}