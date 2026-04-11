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



vector<int> computeShortestDist (vector<vector<pair<int, int>>> &graph, int s) 
{
    int v = graph.size();
    vector<int> distance (v, INT_MAX); // make all the distances inf
    // min heap to track minimum distance over the time
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> distTracker;
    vector<bool> visited(v, 0);

    // making the dist of the s 0 as we gonna start from here
    distance[s] = 0;
    distTracker.push({0, s});

    // traverse through all the vertices
    for(int i = 0; i < v; i++)
    {
        // find the min and unvisited nodes
        pair<int, int> curr = distTracker.top();
        distTracker.pop();
        int dist = curr.first, node = curr.second;
        if(visited[node]) continue;

        visited[node] = 1;

        // update the distances of all neighbers
        for(int i = 0; i < graph[node].size(); i++)
        {
            int u = graph[node][i].first, cost = graph[node][i].second;
            if(distance[u] > distance[node] + cost)
            {
                distance[u] = distance[node] + cost;
                distTracker.push({distance[u], u});
            }
        }
    }

    return distance;
}

int main()
{
    int v;
    cout << "number of vertices: ";
    cin >> v;

    vector<vector<pair<int, int>>> graph = createGraph(v);
    vector<int> shortesDists = computeShortestDist(graph, 0);

    for(int d: shortesDists)
    {
        cout << d << " ";
    }
}