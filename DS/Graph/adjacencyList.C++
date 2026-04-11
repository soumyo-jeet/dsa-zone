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

int main () 
{
    int v;
    cout << "Number of vertices: ";
    cin >> v;

    vector<pair<int, int>> undirgr [v];
    for(int i = 0; i < v; i++)
    {
        for(int j = i; j < v; j ++)
        {
            if (i <= j)
            {
                int e;
                cout << "Edge between " << i << " and " << j << ": ";
                cin >> e;
                if(e > 0) 
                {
                    undirgr[i].push_back({j, e});
                    undirgr[j].push_back({i,e});
                }
            }
        }
    }

    cout << "\nDisplay: \n";
    // Display the list
    for(int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for(int j = 0; j < undirgr[i].size(); j++)
        {
            cout << "(" << undirgr[i][j].first << " , " << undirgr[i][j].second << ") | ";
        }
        cout << " ";
    }
}