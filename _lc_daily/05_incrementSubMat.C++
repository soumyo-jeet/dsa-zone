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

// Brute Force
// O(q*n*n)
void incrementMat(int query[][4], int n, int s)
{
    vector<vector<int>> mat(s, vector<int>(s, 0));

    for (int i = 0; i < n; i++)
    {
        int rS = query[i][0], cS = query[i][1], rE = query[i][2], cE = query[i][3];
        for (int j = rS; j <= rE; j++)
        {
            for (int k = cS; k <= cE; k++)
            {
                mat[j][k]++;
            }
        }
    }

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << mat[i][j] << ' ';
            // Initialize or use arr[i][j] here
        }
        cout << endl;
    }
}

// Optimal -> ADT (Array Difference Tech) 
// O(q*n + n*n)
vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
{
    vector<vector<int>> diffArr(n, vector<int>(n, 0));
    // For each query
    //      increase all elements between rS and rE of cS by 1
    //      decrease all elements between rS and rE of cE + 1 by 1

    for (vector<int> q : queries)
    {
        int rS = q[0], cS = q[1], rE = q[2], cE = q[3];
        for (int i = rS; i <= rE; i++)
        {
            diffArr[i][cS]++;
            if (cE + 1 < n)
                diffArr[i][cE + 1]--;
        }
    }

    // take the commulative sum and return the vector
    for (int i = 0; i < n; i++) // row
    {
        for (int j = 1; j < n; j++) // col
        {
            diffArr[i][j] += diffArr[i][j - 1];
        }
    }

    return diffArr;
}

int main()
{
    int n, arr[50][4];
    cout << "Number of queries: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    incrementMat(arr, n, 3);
}