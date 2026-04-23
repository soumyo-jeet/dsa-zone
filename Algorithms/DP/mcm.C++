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

vector<vector<pair<int, int>>> createMCMMat (vector<int> D) {
    int n = D.size() - 1;
    vector<vector<pair<int, int>>> mcm (n, vector<pair<int, int>>(n, {0, -1}));

    for(int x = 1; x < n; x++) {
        for(int i = 0; i < n - x; i++) {

            int j = i + x, minV = INT_MAX, minK = -1;
            for(int k = i; k < j; k++) {
                int y = mcm[i][k].first + mcm[k + 1][j].first + D[i] * D[k + 1] * D[j + 1];
                if(y < minV) {
                    minV = y;
                    minK = k;   
                }
            }

            mcm[i][j] = {minV, minK};
        }
    }

    return mcm;
}

string parenthesize (int s, int e, vector<vector<pair<int, int>>> mcm) {
    if(s == e) return "( " + string(1, char('A' + s)) + " )";
    if(e - s == 1) return "( " + string(1, char('A' + s)) + " * " + string(1, char('A' + e)) + " )";

    int k = mcm[s][e].second;
    string left = parenthesize (s, k, mcm),
    right = parenthesize(k + 1, e, mcm);

    return "( " + left + " * " + right + " )";
}


int main()
{
    int ms;
    cout << "Number of matrices in the chain: ";
    cin >> ms;

    vector<int> D(ms + 1);

    for(int i = 0; i < D.size(); i++) {
        cin >> D[i];
    }


    vector<vector<pair<int, int>>> mcm = createMCMMat(D);

    for(int i = 0; i < mcm.size(); i++) {
        for(int j = 0; j < mcm[0].size(); j++) {
            cout << mcm[i][j].first << " -> "  << mcm[i][j].second << "   ";
        }
        cout << endl;
    }

    cout << endl << parenthesize(0, ms - 1, mcm);
}