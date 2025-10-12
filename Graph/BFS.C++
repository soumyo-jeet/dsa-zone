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

vector<vector<pair<int, int>>> createGraph(int v)
{
    vector<vector<pair<int, int>>> undirgr(v);
    for (int i = 0; i < v; i++)
    {
        for (int j = i; j < v; j++)
        {
            if (i <= j)
            {
                int e;
                cout << "Edge between " << i << " and " << j << ": ";
                cin >> e;
                if (e > 0)
                {
                    undirgr[i].push_back({j, e});
                    undirgr[j].push_back({i, e});
                }
            }
        }
    }

    return undirgr;
}

void displayGraphList(vector<vector<pair<int, int>>> undirgr)
{
    cout << "\nDisplay: \n";
    int v = undirgr.size();
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < undirgr[i].size(); j++)
        {
            cout << "(" << undirgr[i][j].first << " , " << undirgr[i][j].second << ") | ";
        }
        cout << "\n";
    }
}

vector<int> BFS(vector<vector<pair<int, int>>> undirgr)
{
    int v = undirgr.size();
    queue<int> nodes;
    vector<bool> contaminated(v, 0);
    vector<int> ans;

    // push the starting node and make contaminated true (here starting from 0th node)
    nodes.push(0);
    contaminated[0] = 1;

    // start the contamination
    while (!nodes.empty())
    {
        // pop out the front from the queue and queue its near by not contaminated neighbours
        int curr = nodes.front();
        nodes.pop();

        // push the node to ans
        ans.push_back(curr);

        // look for the neighbours in its adjacency list
        for (int i = 0; i < undirgr[curr].size(); i++)
        {
            int neigh = undirgr[curr][i].first;
            // check the not contaminated neighbours and push it to the queue and make contaminated true
            if (contaminated[neigh] != 1)
            {
                nodes.push(neigh);
                contaminated[neigh] = 1;
            }
        }
    }

    return ans;
}

void displayBFS(vector<int> bfs)
{
    cout << "\nBFS Display: \n";
    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }
}

int main()
{
    int v;
    cout << "Number of vertices: ";
    cin >> v;

    vector<vector<pair<int, int>>> undirgr(v);
    undirgr = createGraph(v);
    displayGraphList(undirgr);

    vector<int> bfs(v);
    bfs = BFS(undirgr);
    displayBFS(bfs);
}