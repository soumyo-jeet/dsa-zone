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

int totalWaysRecc (int tr, int tc) {
    if(tr == 0 && tc == 0) 
    return 1;

    int ri8 = 0, dwn = 0;
    // at the target row move left (eq to ri8 move)
    if(tr == 0) ri8 += totalWaysRecc(tr, tc - 1);
    // at target col move down (eq to up move)
    if(tc == 0) dwn += totalWaysRecc(tr - 1, tc);
    // at mid of the grid (ri8 n up both moves granted)
    if(tr > 0 && tc > 0) {
        ri8 += totalWaysRecc(tr, tc - 1);
        dwn += totalWaysRecc(tr - 1, tc);
    }

    return ri8 + dwn;
}


// MEMOIZATION
int totalWaysReccMemo (int tr, int tc, vector<vector<int>> &pathRecords) {
    if(tr == 0 && tc == 0) 
    return 1;

    if(pathRecords[tr][tc] != -1) 
    return pathRecords[tr][tc];

    int ri8 = 0, dwn = 0;
    // at the target row move left (eq to ri8 move)
    if(tr == 0) ri8 += totalWaysReccMemo(tr, tc - 1, pathRecords);
    // at target col move down (eq to up move)
    if(tc == 0) dwn += totalWaysReccMemo(tr - 1, tc, pathRecords);
    // at mid of the grid (ri8 n up both moves granted)
    if(tr > 0 && tc > 0) {
        ri8 += totalWaysReccMemo(tr, tc - 1, pathRecords);
        dwn += totalWaysReccMemo(tr - 1, tc, pathRecords);
    }

    pathRecords[tr][tc] = ri8 + dwn;
    return ri8 + dwn;
}

// BOTTOM-UP
int totalWaysReccDP (int tr, int tc, vector<vector<int>> &pathRecords) {
    // all the boundary boxes can be reached by 1 step
    for(int i = 0; i < tc; i++) {
        pathRecords[0][i] = 1;
    }
    for(int i = 0; i < tr; i++) {
        pathRecords[i][0] = 1;
    }

    

    for(int r = 1; r < tr; r++) {
        for(int c = 1; c < tc; c++) {
            pathRecords[r][c] = pathRecords[r - 1][c] + pathRecords[r][c - 1];
        }
    }

    return pathRecords[tr][tc];
}

int main () {
    int r, c;
    cout << "Target: ";
    cin >> r >> c;
    cout << totalWaysRecc(r, c) << endl;

    vector<vector<int>> pathRecords (r + 1, vector<int> (c + 1, -1));
    cout << totalWaysReccMemo(r, c, pathRecords) << endl;

    cout << totalWaysReccDP(r, c, pathRecords) << endl;
}