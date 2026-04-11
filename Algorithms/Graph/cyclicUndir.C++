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

vector<vector<int>> createGraph(int v)
{
    vector<vector<int>> undirgr(v);
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
                    undirgr[i].push_back(j);
                    undirgr[j].push_back(i);
                }
            }
        }
    }

    return undirgr;
}


bool isCyclic (vector<vector<int>>& graph, vector<int>& parent, int node, vector<int>& visited)
{
    visited[node] = 1;

    for(int n : graph[node])
    {
        if(visited[n] && parent[node] != n) return 1;
        else if(visited[n]) continue;

        parent[n] = node;
        return isCyclic(graph, parent, n, visited);
    }

}

int main()
{
    int v;
    cout << "number of vertices: ";
    cin >> v;

    vector<vector<int>> graph = createGraph(v);
    vector<int> visited (v, 0);
    vector<int> parent (v, -1);

    cout << isCyclic(graph, parent, 0, visited);
}